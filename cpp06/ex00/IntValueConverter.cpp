#include "IntValueConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

IntValueConverter::IntValueConverter(std::string s)
{
	s_rep << "int: ";
	value = std::atoi(s.c_str());
	if (!value)
	{
		s_rep << "impossible";
		return;
	}
	if (s.at(0) == '-' && s.length() > 11)
		s_rep << "-inf";
	else if (s.at(0) != '-' && s.length() > 10)
		s_rep << "+inf";
	else
		s_rep << value;
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
