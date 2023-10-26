#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
typename T::iterator	easyfind(T& t, int i)
{
	typename T::iterator result = std::find(t.begin(), t.end(), i);
	if (result == t.end())
		throw	std::runtime_error("Element not found!\r\n");
	return result;
}

#endif