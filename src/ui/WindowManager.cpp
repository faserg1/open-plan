#include "WindowManager.hpp"
#include "WindowManagerLink.hpp"

WindowManager::WindowManager(QObject *parent) : QObject(parent)
{

}

void WindowManager::link(QString name, WindowManagerLink *link)
{
	m_windows.insert({name, link});
	link->connect(link, &WindowManagerLink::destroyed, [this, name](){
		this->onWindowManagerLinkDestroyed(name);
	});
}

QQuickWindow *WindowManager::get(QString name)
{
	if (auto wit = m_windows.find(name); wit != m_windows.end())
		return wit->second->getWindow();
	return nullptr;
}

void WindowManager::onWindowManagerLinkDestroyed(QString name)
{
	m_windows.erase(name);
}
