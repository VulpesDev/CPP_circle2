#include "AValueConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AValueConverter::AValueConverter()
{
}

AValueConverter::AValueConverter( const AValueConverter & src )
{
	s_rep << src.s_rep.str();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AValueConverter::~AValueConverter()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AValueConverter &				AValueConverter::operator=( AValueConverter const & rhs )
{
	s_rep << rhs.s_rep.str();
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AValueConverter const & i )
{
	o << i.getS_rec();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	AValueConverter::getS_rec() const
{
	return s_rep.str();
}

/* ************************************************************************** */