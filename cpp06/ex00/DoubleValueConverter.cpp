#include "DoubleValueConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DoubleValueConverter::DoubleValueConverter(std::string s)
{
	s_rep << "double: ";
	long v = std::atol(s.c_str());
	value = std::atof(s.c_str());
	if (!value || !v)
	{
		s_rep << "nan";
		return;
	}
	if (s.at(0) == '-' && (s.length() > 11 || v < -2147483648))
		s_rep << "-inf";
	else if (s.at(0) != '-' && (s.length() > 10 || v > 2147483647))
		s_rep << "+inf";
	else
		s_rep << value;
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