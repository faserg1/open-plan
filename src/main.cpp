#include <QGuiApplication>
#include "ui/UserInterfaceStarter.hpp"

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QGuiApplication app(argc, argv);

	UserInterfaceStarter starter;
	starter.start();

	return app.exec();
}
