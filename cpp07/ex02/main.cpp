#include <iostream>
 #include "Array.hpp"
//#include "Test.hpp"

int	main()
{
	Array<int>	ar(15);
	for (size_t i = 0; i < ar.size(); i++)
	{
		ar[i] = i;
		std::cout << ar[i] << std::endl;
	}
	return (0);
}