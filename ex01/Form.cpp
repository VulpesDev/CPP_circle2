#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(std::string name, int reqsign, int reqexec) : name(name), reqsign(reqsign), reqexec(reqexec)
{
	if (reqsign > 150 || reqexec > 150)
		throw GradeTooLowException();
	else if (reqsign < 1 || reqexec < 1)
		throw GradeTooHighException();
	sign = false;
}

Form::Form( const Form & src ) : reqsign(150), reqexec(150)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o<< "Name: " << i.getName() << std::endl;
	o<< "Sign: " << i.getSign() << std::endl;
	o<< "Grade required to sign: " << i.getReqsign()<< std::endl;
	o<< "Grade required to execute: " << i.getReqexec()<< std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

	void	Form::beSigned( Bureaucrat const & rhs )
	{
		if (rhs.getGrade() <= reqsign)
			sign = true;
		else
			throw GradeTooLowException();
	}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

	std::string	Form::getName() const
	{
		return name;
	}

	bool		Form::getSign() const
	{
		return sign;
	}

	int		Form::getReqsign() const
	{
		return reqsign;
	}

	int		Form::getReqexec() const
	{
		return reqexec;
	}


/* ************************************************************************** */