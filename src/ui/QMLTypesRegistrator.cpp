#include "QMLTypesRegistrator.hpp"
#include "../project/Project.hpp"
#include "../project/ProjectManager.hpp"

#include "../ui/WindowManager.hpp"
#include "../ui/WindowManagerLink.hpp"

QMLTypesRegistrator::QMLTypesRegistrator(QObject *parent) : QObject(parent)
{

}

void QMLTypesRegistrator::registerQMLTypes(QQmlApplicationEngine &engine)
{
	Q_UNUSED(engine)

	addSignleton<WindowManager>("WindowManager", "WindowManager");
	add<WindowManagerLink>("WindowManager", "WindowManagerLink");

	addSignleton<ProjectManager>("Projects", "ProjectManager");
	addUncreatable<Project>("Projects", "Project", "Project cannot be created in QML directly. Use ProjectManager instead.");
}
