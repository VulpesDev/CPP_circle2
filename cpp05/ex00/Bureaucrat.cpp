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