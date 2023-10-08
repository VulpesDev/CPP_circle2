#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern() : ran(0)
{
}

Intern::Intern( const Intern & src )
{
	ran = src.ran;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	if ( this != &rhs )
	{
		this->ran = rhs.ran;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Intern const & i )
{
	o << "Value = " << i.getRan();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

	AForm *	Intern::checkMakeForm(std::string name, std::string target) const
	{
		bool ret = false; size_t cori = 0;
		std::string	types[] =
		{
			"shrubbery creation",
			"robotomy request",
			"presidential pardon"
		};

		AForm*	forms[] =
		{
			new ShrubberyCreationForm(target),
			new RobotomyRequestForm(target),
			new PresidentialPardonForm(target)
		};
		for (size_t i = 0; i < 3; i++)
		{
			if (types[i] == name)
			{
				cori = i; ret = true;
			}
		}
		for (size_t i = 0; i < 3; i++)
				if (i != cori)
					delete(forms[i]);
		if (ret)
			return forms[cori];
		else
			delete(forms[cori]);
		throw FormNameException();
		
	}

	AForm *	Intern::makeForm(std::string name, std::string target) const
	{
		try
		{
			return checkMakeForm(name, target);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Make form exception: " << e.what() << std::endl;
		}
		return NULL;
	}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int	Intern::getRan() const
{
	return ran;
}


/* ************************************************************************** */