#include "Base.hpp"

int	main()
{
	Base *r;
	Base b;

	r = b.generate();
	b.identify(r);
	delete(r);
	return (0);
}