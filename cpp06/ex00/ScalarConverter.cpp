#include "ScalarConverter.hpp"
#include "IntValueConverter.hpp"
#include "FloatValueConverter.hpp"
#include "DoubleValueConverter.hpp"


void	ScalarConverter::convert(std::string s)
{
	IntValueConverter vint(s);
	FloatValueConverter vfloat(s);
	DoubleValueConverter vdouble(s);

	if (s == "nan")
		std::cout << "char: impossible" << std::endl;
	else if (vint.getValue() >= 32 && vint.getValue() <= 126)
		std::cout << "char: '" << (char)vint.getValue() << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << vint << std::endl;
	std::cout << vfloat << std::endl;
	std::cout << vdouble << std::endl;
}