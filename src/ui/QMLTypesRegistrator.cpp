#include "QMLTypesRegistrator.hpp"
#include "../project/ProjectManager.hpp"

QMLTypesRegistrator::QMLTypesRegistrator(QObject *parent) : QObject(parent)
{

}

void QMLTypesRegistrator::registerQMLTypes(QQmlApplicationEngine &engine)
{
	Q_UNUSED(engine)

	addSignleton<ProjectManager>("Projects", "ProjectManager");
}
