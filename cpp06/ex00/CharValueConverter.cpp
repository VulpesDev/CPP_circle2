#include "CharValueConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

CharValueConverter::CharValueConverter(std::string s)
{
	s_rep << "char: ";
	value = std::atoi(s.c_str());
	if (!value)
	{
		s_rep << "impossible";
		return;
	}
	if (value >= 32 && value <= 126)
		s_rep << "'" << (char)value << "'";
	else
		s_rep << "Non displayable";
}

CharValueConverter::CharValueConverter( const CharValueConverter & src )
{
	value = src.value;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

CharValueConverter &				CharValueConverter::operator=( CharValueConverter const & rhs )
{
	value = rhs.value;
	return *this;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int	CharValueConverter::getValue() const
{
	return value;
}

/* ************************************************************************** */