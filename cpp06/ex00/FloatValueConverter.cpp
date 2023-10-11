#include "FloatValueConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FloatValueConverter::FloatValueConverter(std::string s)
{
	s_rep << std::fixed << std::setprecision(1);
	s_rep << "float: ";
	value = std::strtold(s.c_str(), 0);
	if (std::isnan(value) || (!value && s.at(0) != '0'))
		s_rep << "nanf";
	else if (std::isinf(value))
	{
		if (s.at(0) == '-')
			s_rep << "-inff";
		else
			s_rep << "+inff";
	}
	else
		s_rep << (double)value << "f";
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