#include "Base.hpp"

int	main()
{
	Base *r, *r1, *r2;
	Base b;

	r = b.generate();
	r1 = b.generate();
	r2 = b.generate();
	b.identify(r);
	b.identify(r1);
	b.identify(r2);
	std::cout << "Phase2" << std::endl;
	b.identify(*r);
	b.identify(*r1);
	b.identify(*r2);
	delete(r);
	delete(r1);
	delete(r2);
	return (0);
}