#include "FloatValueConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FloatValueConverter::FloatValueConverter(std::string s)
{
	s_rep << "float: ";
	value = std::atof(s.c_str());
	if (!value)
	{
		s_rep << "nanf";
		return;
	}
	if (s.at(0) == '-' && s.length() > 11)
		s_rep << "-inff";
	else if (s.at(0) != '-' && s.length() > 10)
		s_rep << "+inff";
	else
		s_rep << value << "f";
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