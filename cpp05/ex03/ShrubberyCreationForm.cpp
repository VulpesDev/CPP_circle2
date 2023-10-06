#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubbery creation", 145, 137)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) : AForm(src)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/


/*
** --------------------------------- METHODS ----------------------------------
*/

	void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
	{
		AForm::execute(executor);
		std::ofstream	out(target + "_shrubbery");
		int				levels = 5;
		char			trunkChar = '|';
		char			leafChar = '*';
		if (!out)
			throw FileCreationException();
		for (int i = 0; i < levels; i++)
		{
        	for (int j = 0; j < levels - i - 1; j++) {
        	    out << ' ';
        	}
        	for (int j = 0; j < 2 * i + 1; j++) {
        	    out << leafChar;
        	}
        	out << '\n';
    	}

    	for (int i = 0; i < levels - 1; i++)
		{
    	    for (int j = 0; j < levels - 1; j++) {
    	        out << ' ';
    	    }
    	    out << trunkChar << '\n';
    	}
		out.close();
	}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */