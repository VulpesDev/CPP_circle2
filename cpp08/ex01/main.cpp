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

// #include <random>
// int main()
// {
//     std::random_device rd;
//     std::mt19937 gen(rd());
//     std::uniform_int_distribution<int> dist(1, 100000); // Adjust the range as needed

//     // Declare a vector of integers and populate it with random values
//     std::vector<int> myVector;
//     const int vectorSize = 1000; // Set the size you want

//     for (int i = 0; i < vectorSize; ++i) {
//         int randomValue = dist(gen);
//         myVector.push_back(randomValue);
//     }
// Span sp = Span(1000);
// sp.addRange(myVector.begin(), myVector.end());
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// return 0;
// }