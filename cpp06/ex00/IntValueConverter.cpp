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
		//std::cerr << "Error: " << e.what() << std::endl;
		value = 0;
		if (s == "nan")
			s_rep << "impossible";
	}
	
}

IntValueConverter::IntValueConverter( const IntValueConverter & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

IntValueConverter::~IntValueConverter()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

IntValueConverter &				IntValueConverter::operator=( IntValueConverter const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, IntValueConverter const & i )
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

int	IntValueConverter::getValue() const
{
	return value;
}

std::string	IntValueConverter::getS_rec() const
{
	return s_rep.str();
}

/* ************************************************************************** */