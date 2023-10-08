#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename unknown>
void	swap(unknown &a, unknown &b)
{
	unknown temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename unknown>
unknown min(unknown a, unknown b)
{
	if (a >= b)
		return b;
	else
		return a;
}

template <typename unknown>
unknown max(unknown a, unknown b)
{
	if (a <= b)
		return b;
	else
		return a;
}

#endif