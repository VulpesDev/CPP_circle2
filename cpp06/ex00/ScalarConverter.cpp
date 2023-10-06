#include "ScalarConverter.hpp"
#include "IntValueConverter.hpp"


void	ScalarConverter::convert(std::string s)
{
	IntValueConverter vint(s);
	//int	vint = std::stoi(s);
	//float	vfloat = std::stof(s);
	//double	vdouble = std::stod(s);
	if (vint.getValue() >= 32 && vint.getValue() <= 126)
		std::cout << "char: " << (char)vint.getValue() << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << vint << std::endl;
	// std::cout << std::fixed << std::setprecision(1) << "float: " << vfloat << 'f' << std::endl;
	// std::cout << "double: " << vdouble << std::endl;
}