#include "easyfind.hpp"


int	main(void)
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(0);
	int target = 3;
	std::vector<int>::iterator result = easyfind(vec, target);
	std::cout << *result << std::endl;
	std::cout << "index: " << std::distance(vec.begin(), result);
	return 0;
}