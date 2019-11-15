#include "UserInterfaceStarter.hpp"
#include <QFontDatabase>
#include <QCoreApplication>
#include "QMLTypesRegistrator.hpp"

UserInterfaceStarter::UserInterfaceStarter(QObject *parent) :
	QObject(parent), url("qrc:/ui/Main.qml")
{
	QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, this,
		[this](QObject *obj, const QUrl &objUrl)
		{
			if (!obj && url == objUrl)
				QCoreApplication::exit(-1);
		}, Qt::QueuedConnection);
	loadFonts();
	registerTypes();
}

void UserInterfaceStarter::start()
{
	engine.load(url);
}

void UserInterfaceStarter::loadFonts()
{
	QStringList fontPaths =
	{
		"Roboto-Black.ttf",
		"Roboto-BlackItalic.ttf",
		"Roboto-Bold.ttf",
		"Roboto-BoldItalic.ttf",
		"Roboto-Italic.ttf",
		"Roboto-Light.ttf",
		"Roboto-LightItalic.ttf",
		"Roboto-Medium.ttf",
		"Roboto-MediumItalic.ttf",
		"Roboto-Regular.ttf",
		"Roboto-Thin.ttf",
		"Roboto-ThinItalic.ttf",
	};
	for (auto fontFileName : fontPaths)
	{
		QFontDatabase::addApplicationFont("qrc:/resources/font/" + fontFileName);
	}
}

void UserInterfaceStarter::registerTypes()
{
	QMLTypesRegistrator registrator(this);
	registrator.registerQMLTypes(engine);
}
