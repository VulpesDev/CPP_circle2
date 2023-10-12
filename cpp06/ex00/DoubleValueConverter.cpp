#include "DoubleValueConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DoubleValueConverter::DoubleValueConverter(std::string s)
{
	s_rep << std::fixed << std::setprecision(1);
	s_rep << "double: ";
	value = std::strtod(s.c_str(), 0);
	if (std::isnan(value) || (!value && s.at(0) != '0'))
		s_rep << "nan";
	else if (std::isinf(value))
	{
		if (s.at(0) == '-')
			s_rep << "-inf";
		else
			s_rep << "+inf";
	}
	else
		s_rep << static_cast<double>(value);
}

DoubleValueConverter::DoubleValueConverter( const DoubleValueConverter & src )
{
	value = src.value;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DoubleValueConverter &				DoubleValueConverter::operator=( DoubleValueConverter const & rhs )
{
	value = rhs.value;
	return *this;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

double	DoubleValueConverter::getValue() const
{
	return value;
}

/* ************************************************************************** */