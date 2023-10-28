#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <iterator>
# include <iostream>
# include <climits>

class Span
{
private:
	unsigned int		maxsize;
	std::vector<int>	set;
public:
	Span( unsigned int N );
	Span( const Span & cpy );
	~Span();
	Span	&operator=(Span const &t);
	
	void	addNumber(int value);
	void	addRange(std::vector<int>::iterator begin,
                    std::vector<int>::iterator end);
	int		shortestSpan(void);
	int		longestSpan(void);

	class OutOfBoundException : public std::exception {
		public :
			const char* what() const throw(){
				return "Out Of Bound";
			}
	};
	class TooShortException : public std::exception {
		public :
			const char* what() const throw(){
				return "Stored values are not enough";
			}
	};
};

#endif