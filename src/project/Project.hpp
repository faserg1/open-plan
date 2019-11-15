#ifndef PROJECT_HPP
#define PROJECT_HPP

#include <QObject>

class ProjectManager;

class Project : public QObject
{
	Q_OBJECT
public:
	explicit Project(ProjectManager *parent = nullptr);

	bool hasChanges() const;
signals:
public slots:
	void save();
	void close();
private:
	ProjectManager *const m_manager;
};

#endif // PROJECT_HPP
