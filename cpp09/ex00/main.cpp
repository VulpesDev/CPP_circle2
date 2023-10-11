#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: wrong arguments" << std::endl;
		return (1);
	}
	BitcoinExchange	b("data.csv", argv[1]);
	std::cout << b << std::endl;
	return (0);
}