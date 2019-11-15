#include "Project.hpp"
#include "ProjectManager.hpp"

Project::Project(ProjectManager *parent):
	QObject(parent), m_manager(parent)
{

}

bool Project::hasChanges() const
{
	return false;
}

void Project::save()
{
	m_manager->saveProject(this);
}

void Project::close()
{
	m_manager->closeProject(this);
}
