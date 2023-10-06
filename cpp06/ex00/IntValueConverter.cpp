#include "IntValueConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

IntValueConverter::IntValueConverter(std::string s)
{
	s_rep << "int: ";
	try
	{
		value = std::stoi(s);
		s_rep << value;
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
		s_rep << "impossible";
	}
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
