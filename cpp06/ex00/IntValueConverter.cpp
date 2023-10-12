#include "IntValueConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

IntValueConverter::IntValueConverter(std::string s)
{
	s_rep << "int: ";
	long	v = std::atol(s.c_str());
	value = std::atoi(s.c_str());
	if (!value && s.at(0) != '0')
	{
		s_rep << "impossible";
		return;
	}
	if (s.at(0) == '-' && (s.length() > 11 || v < INT_MIN))
		s_rep << "-inf";
	else if (s.at(0) != '-' && (s.length() > 10 || v > INT_MAX))
		s_rep << "+inf";
	else
		s_rep << static_cast<int>(value);
}

IntValueConverter::IntValueConverter(IntValueConverter const & src)
{
	value = src.value;
}

IntValueConverter &	IntValueConverter::operator=(IntValueConverter const & rhs)
{
	value = rhs.value;
	return *this;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int	IntValueConverter::getValue() const
{
	return value;
}

/* ************************************************************************** */
