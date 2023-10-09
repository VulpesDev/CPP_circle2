#ifndef SPAN_HPP
# define SPAN_HPP

# include <set>

class Span
{
private:
	int					maxsize;
	std::multiset<int>	set;
public:
	Span( unsigned int N );
	Span( const Span & cpy );
	~Span();
	void	addNumber(int value);
	int		shortestSpan(void);
	int		longestSpan(void);

	class OutOfBoundException : public std::exception {
			public :
				const char* what() const throw(){
					return "Out Of Bound";
				}
		};
};

Span::Span(unsigned int N)
{
}

Span::~Span()
{
}


#endif