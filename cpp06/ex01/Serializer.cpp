#include "Serializer.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Serializer::Serializer() : in(0)
{
}

Serializer::Serializer( const Serializer & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Serializer::~Serializer()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Serializer &				Serializer::operator=( Serializer const & rhs )
{
	this->in = rhs.getIn();
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Serializer const & i )
{
	if (i.getIn())
	;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

	uintptr_t	Serializer::serialize(Data* ptr)
	{
		return reinterpret_cast<uintptr_t>(ptr);
	}

	Data*		Serializer::deserialize(uintptr_t raw)
	{
		return reinterpret_cast<Data*>(raw);
	}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int	Serializer::getIn() const
{
	return in;
}


/* ************************************************************************** */