#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: wrong arguments";
		return (1);
	}
	std::cout << RPN::calculate(argv[1]) << std::endl;
	return (0);
}