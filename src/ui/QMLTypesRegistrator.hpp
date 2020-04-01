#ifndef QMLTYPESREGISTRATOR_HPP
#define QMLTYPESREGISTRATOR_HPP

#include <QObject>
#include <QQmlApplicationEngine>
#include "TypeRegistrator.hpp"

class QMLTypesRegistrator : public QObject
{
	Q_OBJECT
public:
	explicit QMLTypesRegistrator(QObject *parent = nullptr);
signals:

public slots:
	void registerQMLTypes(QQmlApplicationEngine &engine);
private:
	template<class TType>
	int add(const char *uri, const char *type)
	{
		return qmlRegisterType<TType>(uri, 1, 0, type);
	}

	template <class TSingleton>
	int addSignleton(const char *uri, const char *type)
	{
		QObject *(*func)(QQmlEngine *, QJSEngine *) = [](QQmlEngine *, QJSEngine *) -> QObject *
		{
			return new TSingleton();
		};
		::detail::TypeIndex<TSingleton>::id = qmlRegisterSingletonType<TSingleton>(uri, 1, 0, type, func);
		return getIndex<TSingleton>();
	}

	template <class TType>
	int addUncreatable(const char *uri, const char *type, const QString &reason)
	{
		return qmlRegisterUncreatableType<TType>(uri, 1, 0, type, reason);
	}
};

#endif // QMLTYPESREGISTRATOR_HPP
