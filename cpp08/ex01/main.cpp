#include "Span.hpp"
#include <iostream>

int	main(void)
{
	Span	s(10);
	s.addNumber(1);
	s.addNumber(5);
	s.addNumber(23);
	s.addNumber(26);
	s.addNumber(102);
	std::cout << "Shortest span: " << s.shortestSpan() << std::endl;
	std::cout << "Longest span: " << s.longestSpan() << std::endl;
	return (0);
}

// int main()
// {
// Span sp = Span(5);
// sp.addNumber(6);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// return 0;
// }