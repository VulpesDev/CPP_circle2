#include "DoubleValueConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DoubleValueConverter::DoubleValueConverter(std::string s)
{
	s_rep << "double: ";
	value = std::atof(s.c_str());
	if (s.at(0) == '-' && s.length() > 11)
		s_rep << "-inf";
	else if (s.at(0) != '-' && s.length() > 10)
		s_rep << "+inf";
	else if (s == "nan")
	{
		value = 0;
		s_rep << "nan";
	}
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