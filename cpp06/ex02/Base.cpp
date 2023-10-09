#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"




Base::~Base()
{

}

void Base::getType()
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
	p->getType();
}

void Base::identify(Base& p)
{
	p.getType();
}
