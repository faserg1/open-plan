#ifndef WINDOWMANAGERLINK_HPP
#define WINDOWMANAGERLINK_HPP

#include <QObject>
#include <QQuickWindow>

class WindowManager;
class WindowManagerLink : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString name READ getName WRITE setName);
	Q_PROPERTY(QQuickWindow *window READ getWindow WRITE setWindow);
public:
	explicit WindowManagerLink(QObject *parent = nullptr);

	QString getName();
	void setName(QString name);

	QQuickWindow *getWindow();
	void setWindow(QQuickWindow *window);
signals:
private:
	QString m_name;
	QQuickWindow *m_window;
};

#endif // WINDOWMANAGERLINK_HPP
