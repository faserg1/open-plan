#ifndef PROJECTMANAGER_HPP
#define PROJECTMANAGER_HPP

#include <QObject>
#include <QVector>
#include <QSharedPointer>

class Project;

class ProjectManager : public QObject
{
	Q_OBJECT
public:
	explicit ProjectManager(QObject *parent = nullptr);

signals:

public slots:
	QSharedPointer<Project> newProject();
private:
	QVector<QSharedPointer<Project>> m_projects;
};

#endif // PROJECTMANAGER_HPP
