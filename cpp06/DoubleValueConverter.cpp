#include "DoubleValueConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DoubleValueConverter::DoubleValueConverter(std::string s)
{
	s_rep << "double: ";
	try
	{
		value = std::stod(s);
		s_rep << std::fixed << std::setprecision(1) << value;
	}
	catch(const std::out_of_range& e)
	{
		if (s.at(0) == '-')
			s_rep << "-inf";
		else
			s_rep << "+inf";
	}
	catch(const std::exception& e)
	{
		value = 0;
		s_rep << "nan";
	}
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