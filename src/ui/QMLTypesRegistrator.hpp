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
private:
	template <class TSingleton>
	void addSignleton(const char *uri, const char *type)
	{
		QObject *(*func)(QQmlEngine *, QJSEngine *) = [](QQmlEngine *, QJSEngine *) -> QObject *
		{
			return new TSingleton();
		};
		qmlRegisterSingletonType<TSingleton>(uri, 1, 0, type, func);
	}
};

#endif // QMLTYPESREGISTRATOR_HPP
