#ifndef PROJECT_HPP
#define PROJECT_HPP

#include <QObject>

class Project : public QObject
{
	Q_OBJECT
public:
	explicit Project(QObject *parent = nullptr);

signals:

public slots:
};

#endif // PROJECT_HPP
