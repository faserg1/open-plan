#ifndef USERINTERFACESTARTER_HPP
#define USERINTERFACESTARTER_HPP

#include <QObject>
#include <QQmlApplicationEngine>

class UserInterfaceStarter : public QObject
{
	Q_OBJECT
public:
	explicit UserInterfaceStarter(QObject *parent = nullptr);

signals:

public slots:
	void start();
private:
	void loadFonts();
	void registerTypes();
private:
	QQmlApplicationEngine engine;
	const QUrl url;
};

#endif // USERINTERFACESTARTER_HPP
