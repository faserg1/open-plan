#include "QMLTypesRegistrator.hpp"
#include "../project/ProjectManager.hpp"

QMLTypesRegistrator::QMLTypesRegistrator(QObject *parent) : QObject(parent)
{

}

void QMLTypesRegistrator::registerQMLTypes(QQmlApplicationEngine &engine)
{
	constexpr const int majorVersion = 1;
	constexpr const int minorVersion = 1;

	//qmlRegisterType<ProjectManager>("Project", majorVersion, minorVersion, "ProjectManager");
	//qmlRegisterSingletonType<ProjectManager>()
}
