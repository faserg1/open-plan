#ifndef TYPEREGISTRATOR_HPP
#define TYPEREGISTRATOR_HPP

namespace detail {
template <class TSignleton>
struct TypeIndex {
	static inline int id;
};
}

template<class TSingleton>
inline int getIndex()
{
	return ::detail::TypeIndex<TSingleton>::id;
}


#endif // TYPEREGISTRATOR_HPP
