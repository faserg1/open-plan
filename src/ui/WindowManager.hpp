#ifndef WINDOWMANAGER_HPP
#define WINDOWMANAGER_HPP

#include <QObject>
#include <QString>
#include <QQuickWindow>
#include <unordered_map>

class WindowManagerLink;

class WindowManager : public QObject
{
	Q_OBJECT
public:
	explicit WindowManager(QObject *parent = nullptr);
	void link(QString name, WindowManagerLink *link);
signals:
public slots:
	QQuickWindow *get(QString name);
private:
	std::unordered_map<QString, WindowManagerLink*> m_windows;
private:
	void onWindowManagerLinkDestroyed(QString name);
};

#endif // WINDOWMANAGER_HPP
