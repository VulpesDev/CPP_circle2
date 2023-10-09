#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
typename T::iterator	easyfind(T& t, int i)
{
	return std::find(t.begin(), t.end(), i);
}

#endif