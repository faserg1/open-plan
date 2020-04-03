#include "UserInterfaceStarter.hpp"
#include <QFontDatabase>
#include <QCoreApplication>
#include "QMLTypesRegistrator.hpp"
#include "TypeRegistrator.hpp"
#include "WindowManager.hpp"

UserInterfaceStarter::UserInterfaceStarter(QObject *parent) :
	QObject(parent)
{
	loadFonts();
	registerTypes();
	registerWindows();
}

void UserInterfaceStarter::start()
{
	auto *windowManager = engine.singletonInstance<WindowManager*>(getIndex<WindowManager>());
	auto *welcomeWindow = windowManager->get("welcome");
	welcomeWindow->show();
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

void UserInterfaceStarter::registerWindows()
{
	auto *windowManager = engine.singletonInstance<WindowManager*>(getIndex<WindowManager>());
	windowManager->registerWindow(engine, "welcome", QUrl("qrc:/ui/window/WelcomeWindow.qml"));
	windowManager->registerWindow(engine, "project", QUrl("qrc:/ui/window/ProjectWindow.qml"));
}
