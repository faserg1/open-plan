#include "WindowManager.hpp"
#include "WindowManagerLink.hpp"

#include <QQmlComponent>

struct WindowManager::WindowFactory {
	WindowFactory(QQmlComponent *component, const QString &name) :
		component(component), name(name)
	{ }
	QQmlComponent *component;
	QString name;
};

WindowManager::WindowManager(QObject *parent) : QObject(parent)
{

}

WindowManager::~WindowManager()
{
	// Dunno why singleton is destroing BEFORE windows...
	for (auto c : m_connections)
		this->disconnect(c);
}

void WindowManager::link(QString name, WindowManagerLink *link)
{
	assert(m_windows.find(name) == m_windows.end());
	m_windows.insert({name, link});
	auto c = link->connect(link, &WindowManagerLink::destroyed, [this, name](){
		m_windows.erase(name);
	});
	m_connections.push_back(c);
}

void WindowManager::registerWindow(QQmlEngine &engine, QString name, QUrl url)
{
	// Maybe make REAL factory, ha? Seems to be created component will not be destroyed before... oh.. shit.
	assert(m_windowFactories.find(name) == m_windowFactories.end());
	auto factory = std::make_unique<WindowFactory>(new QQmlComponent(&engine, url), name);
	engine.setObjectOwnership(factory->component, QQmlEngine::JavaScriptOwnership);
	auto c = factory->component->connect(factory->component, &QQmlComponent::destroyed, [this, name](){
		m_windowFactories.erase(name);
	});
	m_connections.push_back(c);
	// should be last because of moving factory
	m_windowFactories.insert({name, std::move(factory)});
}

QQuickWindow *WindowManager::get(QString name)
{
	if (auto wit = m_windows.find(name); wit != m_windows.end())
		return wit->second->getWindow();
	if (auto wit = m_windowFactories.find(name); wit != m_windowFactories.end())
	{
		auto *engine = qmlEngine(this);
		QVariantMap initProps {{"name", name}};
		auto *window = qobject_cast<QQuickWindow*>(wit->second->component->createWithInitialProperties(initProps));
		engine->setObjectOwnership(window, QQmlEngine::JavaScriptOwnership);
		return window;
	}
	return nullptr;
}
