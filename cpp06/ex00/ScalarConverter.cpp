#include "ScalarConverter.hpp"


void	ScalarConverter::convert(std::string s)
{
	try
	{
		int	vint = std::stoi(s);
		float	vfloat = std::stof(s);
		double	vdouble = std::stod(s);

		if (vint >= 32 && vint <= 126)
			std::cout << "char: " << (char)vint << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << vint << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float: " << vfloat << 'f' << std::endl;
		std::cout << "double: " << vdouble << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}