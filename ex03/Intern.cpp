#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern( const Intern & src )
{
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
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Intern const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

	AForm *	Intern::checkMakeForm(std::string name, std::string target) const
	{
		bool ret = false; int cori = 0;
		std::string	types[] =
		{
			"shrubbery creation",
			"robotomy request",
			"presidental pardon"
		};

		AForm*	forms[] =
		{
			new ShrubberyCreationForm(target),
			new RobotomyRequestForm(target),
			new PresidentialPardonForm(target)
		};
		for (size_t i = 0; i < 3; i++)
		{
			if (types[i] == forms[i]->getName())
			{
				cori = i; ret = true;
			}
		}
		if (ret)
		{
			for (size_t i = 0; i < 3; i++)
				if (i != cori)
					delete(forms[i]);
			return forms[cori];
		}
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


/* ************************************************************************** */