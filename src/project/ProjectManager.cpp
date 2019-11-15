#include "ProjectManager.hpp"
#include "Project.hpp"

ProjectManager::ProjectManager(QObject *parent) : QObject(parent)
{

}

Project *ProjectManager::newProject()
{
	auto *project = new Project(this);
	this->m_projects.push_back(project);
	return project;
}

void ProjectManager::closeProject(Project *project)
{
	this->m_projects.removeOne(project);
	project->deleteLater();
}

void ProjectManager::saveProject(Project *project)
{
	Q_UNUSED(project)
	// TODO: save projects
}
