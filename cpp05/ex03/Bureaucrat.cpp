#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat( const Bureaucrat & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	if (this != &rhs)
	{
		this->grade = rhs.getGrade();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

	void		Bureaucrat::incGrade()
	{
		grade--;
		if (grade < 1)
			throw GradeTooHighException();
	}

	void		Bureaucrat::decGrade()
	{
		grade++;
		if (grade > 150)
			throw GradeTooLowException();
	}

	void		Bureaucrat::signForm( AForm & rhs ) const
	{
		try
		{
			rhs.beSigned(*this);
			if (rhs.getSign())
				std::cout << name << " signed " << rhs.getName() << std::endl;
			else
				std::cout << name << " couldn't sign " << rhs.getName() << " because unknown" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << name << " couldn't sign " << rhs.getName() << " because " << e.what() << std::endl;
		}
		

	}

	void		Bureaucrat::executeForm(AForm const & form) const
	{
		try{
			std::cout << name << " executed " << form.getName() << std::endl;
			form.execute(*this);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Execution error: " << e.what() << std::endl;
		}
	}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

	int			Bureaucrat::getGrade() const
	{
		return grade;
	}

	std::string	Bureaucrat::getName() const
	{
		return name;
	}

/* ************************************************************************** */