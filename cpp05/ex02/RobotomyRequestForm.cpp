#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robotomy request", 72, 45)
{
	std::cout << "*drilling noises*" << std::endl;
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) : AForm(src)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/


/*
** --------------------------------- METHODS ----------------------------------
*/

	void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const
	{
		AForm::execute(executor);
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		int rand = std::rand() % 2;

		if (rand)
			std::cout << target << " has been robotomized successfully" << std::endl;
		else
			std::cout << target << " robotomy failed" << std::endl;
	}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */