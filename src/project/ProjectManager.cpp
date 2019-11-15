#include "ProjectManager.hpp"
#include "Project.hpp"

ProjectManager::ProjectManager(QObject *parent) : QObject(parent)
{

}

QSharedPointer<Project> ProjectManager::newProject()
{
	return QSharedPointer<Project>(new Project(this));
}
