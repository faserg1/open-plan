#ifndef QMLTYPESREGISTRATOR_HPP
#define QMLTYPESREGISTRATOR_HPP

#include <QObject>
#include <QQmlApplicationEngine>

class QMLTypesRegistrator : public QObject
{
	Q_OBJECT
public:
	explicit QMLTypesRegistrator(QObject *parent = nullptr);

signals:

public slots:
	void registerQMLTypes(QQmlApplicationEngine &engine);
};

#endif // QMLTYPESREGISTRATOR_HPP
