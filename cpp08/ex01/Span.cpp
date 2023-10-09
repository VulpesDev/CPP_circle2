#include "Span.hpp"

Span::Span( unsigned int N ) : maxsize(N)
{

}

Span::Span( const Span & cpy ) : maxsize(cpy.maxsize)
{
	set = cpy.set;
}

void	Span::addNumber(int value)
{
	if (set.size() >= maxsize)
		return throw OutOfBoundException();
	set.insert(value);
}