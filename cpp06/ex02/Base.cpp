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

Base * Base::generate(void)
{
	Base * result;
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	int randomN = std::rand() % 3;

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
