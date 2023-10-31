#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip>

int	main(int argc, char **argv)
{
	clock_t	start_time_vec, end_time_vec, start_time_deque, end_time_deque;

	if (argc <= 1)
	{
		std::cerr << "Invalid arguments!" << std::endl;
		return (1);
	}
	PmergeMe	p;
	for (int i = 1; i < argc; i++)
	{
		try{
			p.insert(argv[i]);
		}
		catch(...)
		{
			std::cerr << "Error" << std::endl;
			return (1);
		}
	}

	// for (size_t i = 1; i < 3000; i++)
	// {
	// 	int rand = std::rand();
	// 	p.insert(rand);
	// }
	
	std::cout << "Before:" << std::endl;
	p.print();
	start_time_vec = clock();
	p.sort_vec();
	end_time_vec = clock();
	start_time_deque = clock();
	p.sort_deque();
	end_time_deque = clock();
	std::cout << "After:" << std::endl;
	p.print();
	std::cout << "Time to process a range of " << p.size() << " elements with std::vector : "  << std::fixed << static_cast<double>(end_time_vec - start_time_vec)/CLOCKS_PER_SEC << "s" << std::endl;
	std::cout << "Time to process a range of " << p.size() << " elements with std::deque : "  << std::fixed << static_cast<double>(end_time_deque - start_time_deque)/CLOCKS_PER_SEC << "s" << std::endl;

	return (0);
}