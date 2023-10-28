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

Span &Span::operator=(Span const &t) {
    if (this == &t)
        return *this;
    if (t.set.size() > maxsize)
        throw OutOfBoundException();
    set.assign(t.set.begin(), t.set.end());
    return *this;
}

void	Span::addNumber(int value)
{
	if (set.size() + 1 > maxsize)
		return throw OutOfBoundException();
	set.push_back(value);
}

void Span::addRange(std::vector<int>::iterator begin,
                    std::vector<int>::iterator end) {
    if (set.size() + std::distance(begin, end) > maxsize) {
        throw OutOfBoundException();
    }
    set.insert(set.end(), begin, end);
}

int		Span::shortestSpan(void)
{
	if (set.size() <= 1)
	{
		throw TooShortException();
		return -1;
	}
	int ret = std::abs(set.at(1) - set.at(0));
    for (std::vector<int>::size_type i = 1; i < set.size() - 1; i++)
        ret = std::min(std::abs(set.at(i + 1) - set.at(i)), ret);
    return ret;
}

int	Span::longestSpan(void)
{
	if (set.size() <= 1)
	{
		throw TooShortException();
		return -1;
	}
	int ret = std::abs(set.at(1) - set.at(0));
    for (std::vector<int>::size_type i = 1; i < set.size() - 1; i++)
        ret = std::max(std::abs(set.at(i + 1) - set.at(i)), ret);
    return ret;
}