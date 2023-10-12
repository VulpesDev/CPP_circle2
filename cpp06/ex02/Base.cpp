#include "Base.hpp"

Base::~Base()
{

}

int	Base::generateRdmN(int numbers)
{
	uint8_t	randomByte;
	ssize_t	result = syscall(SYS_getrandom, &randomByte, sizeof(randomByte), 0);
	if (result == sizeof(randomByte))
	{
		return randomByte % numbers;
	}
	else
	{
		throw FatalException();
	}
}

Base * Base::generate(void)
{
	Base * result;

	int randomN = generateRdmN(3);

	switch (randomN)
	{
	case 0:
		result = new A();
		break;
	case 1:
		result = new B();
		break;
	case 2:
		result = new C();
		break;
	default:
		result = NULL;
		break;
	}
	return result;
}

void Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void Base::identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(...){}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch(...){}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch(...){}
}
