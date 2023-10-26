#include "Span.hpp"

Span::Span( unsigned int N ) : maxsize(N)
{

}

Span::Span( const Span & cpy ) : maxsize(cpy.maxsize)
{
	set = cpy.set;
}

Span::~Span()
{

}

void	Span::addNumber(int value)
{
	if (set.size() + 1 > maxsize)
		return throw OutOfBoundException();
	set.insert(value);
}

int		Span::shortestSpan(void)
{
	int result = INT_MAX;
	std::multiset<int>	cpy(set);
	if (set.size() <= 1)
	{
		throw TooShortException();
		return -1;
	}
	std::multiset<int>::iterator min = cpy.begin();
	std::multiset<int>::iterator min2;
	while (min != --cpy.end())
	{
		min2 = min;
		++min2;
		while (min2 != cpy.end())
		{
			int calc = *min > *min2? (*min - *min2) : (*min2 - *min);
			if (min != min2 && result > calc)
				result = calc;
			min2++;
		}
		min++;
	}
	return (result);
}

int	Span::longestSpan(void)
{
	if (set.size() <= 1)
	{
		throw TooShortException();
		return -1;
	}
	std::multiset<int>::iterator max = std::max_element(set.begin(), set.end());
	std::multiset<int>::iterator min = std::min_element(set.begin(), set.end());
	return (*max - *min);
}