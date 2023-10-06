#include "FloatValueConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FloatValueConverter::FloatValueConverter(std::string s)
{
	s_rep << "float: ";
	try
	{
		value = std::stof(s);
		s_rep << std::fixed << std::setprecision(1) << value << "f";
	}
	catch(const std::out_of_range& e)
	{
		if (s.at(0) == '-')
			s_rep << "-inff";
		else
			s_rep << "+inff";
	}
	catch(const std::exception& e)
	{
		value = 0;
		s_rep << "nanf";
	}
}

FloatValueConverter::FloatValueConverter(FloatValueConverter const & src)
{
	value = src.value;
}

FloatValueConverter &	FloatValueConverter::operator=(FloatValueConverter const & rhs)
{
	value = rhs.value;
	return *this;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

float	FloatValueConverter::getValue() const
{
	return value;
}

/* ************************************************************************** */