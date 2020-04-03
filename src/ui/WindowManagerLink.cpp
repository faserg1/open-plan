#include "WindowManagerLink.hpp"
#include "WindowManager.hpp"
#include "TypeRegistrator.hpp"
#include <QQmlEngine>

auto *getWindowManager(QObject *obj)
{
	auto *engine = qmlEngine(obj);
	return engine->singletonInstance<WindowManager*>(getIndex<WindowManager>());
}

WindowManagerLink::WindowManagerLink(QObject *parent) :
	QObject(parent)
{
}

QString WindowManagerLink::getName()
{
	return m_name;
}

void WindowManagerLink::setName(QString name)
{
	if (name.isEmpty())
		return;
	if (!m_name.isEmpty() && m_name != name)
		return;
	m_name = name;
	auto *wm = getWindowManager(this);
	wm->link(name, this);
}

QQuickWindow *WindowManagerLink::getWindow()
{
	return m_window;
}

void WindowManagerLink::setWindow(QQuickWindow *window)
{
	m_window = window;
}
