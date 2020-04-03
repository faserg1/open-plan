#ifndef WINDOWMANAGER_HPP
#define WINDOWMANAGER_HPP

#include <QObject>
#include <QString>
#include <QQuickWindow>
#include <QQmlEngine>
#include <unordered_map>
#include <memory>

class WindowManagerLink;

class WindowManager : public QObject
{
	Q_OBJECT
public:
	explicit WindowManager(QObject *parent = nullptr);
	~WindowManager();
	void link(QString name, WindowManagerLink *link);
	void registerWindow(QQmlEngine &engine, QString name, QUrl url);
signals:
public slots:
	QQuickWindow *get(QString name);
private:
	struct WindowFactory;
	std::vector<QMetaObject::Connection> m_connections;
	std::unordered_map<QString, std::unique_ptr<WindowFactory>> m_windowFactories;
	std::unordered_map<QString, WindowManagerLink*> m_windows;
private:
};

#endif // WINDOWMANAGER_HPP
