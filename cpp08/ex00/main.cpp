#include "easyfind.hpp"


int	main(void)
{
	std::vector<int>::iterator result;
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(0);
	int target = 3;
	try
	{
		result = easyfind(vec, target);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	
	std::cout << *result << std::endl;
	std::cout << "index: " << std::distance(vec.begin(), result);
	return 0;
}