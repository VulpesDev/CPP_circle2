#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cerr << "Invalid arguments!" << std::endl;
		return (1);
	}

	PmergeMe	p;

	p.insert(10);
	p.insert(122);
	p.insert(1552);
	p.insert(15);
	p.insert(50);
	p.insert(1);
	p.insert(13);
	p.insert(77);
	p.insert(0);
	p.insert(88);
	p.print();
	std::cout << "After:" << std::endl;
	p.sort();
	std::cout << "After sorting:" << std::endl;
	p.print();
	return (0);
}