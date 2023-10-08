#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename unknown, typename func>
void	iter(unknown arr[], size_t len, func f)
{
	for (size_t i = 0; i < len; i++)
	{
		f(arr[i]);
	}
}

#endif