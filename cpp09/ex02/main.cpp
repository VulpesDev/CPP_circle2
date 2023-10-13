#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cerr << "Invalid arguments!" << std::endl;
		return (1);
	}

	PmergeMe	p;
	for (size_t i = 1; i < argc; i++)
	{
		p.insert(argv[i]);
	}
	
	std::cout << "Before:" << std::endl;
	p.print();
	p.sort();
	std::cout << "After:" << std::endl;
	p.print();
	return (0);
}