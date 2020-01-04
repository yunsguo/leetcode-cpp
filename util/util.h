#pragma once
#ifndef LIB_UTIL_H
#define LIB_UTIL_H

#include <string>
#include <sstream>

template<typename T>
struct show_trait
{
	using possess = std::is_arithmetic<T>;

	template<typename = std::enable_if_t<possess::value>>
	static std::string show(const T& val) {
		std::ostringstream stream;
		stream << val;
		return stream.str();
	}
};

#ifdef _IOSTREAM_
template<typename T, typename = std::enable_if_t<show_trait<T>::possess::value>>
std::ostream& operator<<(std::ostream& os, const T& val)
{
	return os << show_trait<T>::show(val);
}
#endif

#ifdef _VECTOR_
template<typename E>
struct show_trait<std::vector<E>> {

	using possess = typename show_trait<E>::possess;

	static std::string show(const std::vector<E>& vector) {
		std::string buffer = "[";
		auto l = vector.size();
		if (l != 0)
		{
			buffer += show_trait<E>::show(vector.front());
			for (size_t i = 1; i < l; i++)
				buffer += "," + show_trait<E>::show(vector[i]);
		}
		buffer += "]";
		return buffer;
	};
};
#endif
#endif