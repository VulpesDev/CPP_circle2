#include "ScalarConverter.hpp"
#include "CharValueConverter.hpp"
#include "IntValueConverter.hpp"
#include "FloatValueConverter.hpp"
#include "DoubleValueConverter.hpp"


void	ScalarConverter::convert(std::string s)
{
	CharValueConverter vchar(s);
	IntValueConverter vint(s);
	FloatValueConverter vfloat(s);
	DoubleValueConverter vdouble(s);

	std::cout << vchar << std::endl;
	std::cout << vint << std::endl;
	std::cout << vfloat << std::endl;
	std::cout << vdouble << std::endl;
}