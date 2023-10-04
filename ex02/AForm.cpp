#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm(std::string name, int reqsign, int reqexec) : name(name), reqsign(reqsign), reqexec(reqexec)
{
	if (reqsign > 150 || reqexec > 150)
		throw GradeTooLowException();
	else if (reqsign < 1 || reqexec < 1)
		throw GradeTooHighException();
	sign = false;
}

AForm::AForm( const AForm & src ) : reqsign(150), reqexec(150)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream&	AForm::print(std::ostream& os) const
{
	os<< "Name: " << this->name << std::endl;
	os<< "Sign: " << this->sign << std::endl;
	os<< "Grade required to sign: " << this->reqsign << std::endl;
	os<< "Grade required to execute: " << this->reqexec << std::endl;
	return os;
}

std::ostream &			operator<<( std::ostream & o, AForm const & i )
{
	return i.print(o);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

	void	AForm::beSigned( Bureaucrat const & rhs )
	{
		if (rhs.getGrade() <= reqsign)
			sign = true;
		else
			throw GradeTooLowException();
	}

	void	AForm::execute( Bureaucrat const & executor ) const
	{
		if (executor.getGrade() > reqexec)
			throw GradeTooLowException();
		else if (!sign)
			throw FormNotSignedException();
	}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

	std::string	AForm::getName() const
	{
		return name;
	}

	bool		AForm::getSign() const
	{
		return sign;
	}

	int		AForm::getReqsign() const
	{
		return reqsign;
	}

	int		AForm::getReqexec() const
	{
		return reqexec;
	}
	std::string AForm::getTarget() const
	{
		return target;
	}

/* ************************************************************************** */