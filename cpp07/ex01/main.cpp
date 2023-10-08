#include "iter.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

const int ARRAY_SIZE = 10;

void	func(int &i)
{
	i++;
}

int main() {
    std::srand(std::time(0));
    int randomArray[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        randomArray[i] = std::rand();
    }
    std::cout << "Random Array: ";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << randomArray[i] << " ";
    }
    std::cout << std::endl;

	::iter(randomArray, (size_t)ARRAY_SIZE, func);

	std::cout << "  iter Array: ";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << randomArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
