#include <iostream>
#include "Bureaucrat.hpp"

// int	main( void )
// {
// 	try {
// 	Bureaucrat hari("Hari", -1);
// 	std::cout << hari << std::endl;
// 	}
// 	catch (Bureaucrat::GradeTooLowException)
// 	{
// 		std::cout << "grade low" << std::endl;
// 		return (1);
// 	}
// 	catch (Bureaucrat::GradeTooHighException)
// 	{
// 		std::cout << "grade high" << std::endl;
// 		return (1);
// 	}

int	main( void )
{
	try {
	Bureaucrat hari("Hari", 151);
	std::cout << hari << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException)
	{
		std::cout << "grade low" << std::endl;
		return (1);
	}
	catch (Bureaucrat::GradeTooHighException)
	{
		std::cout << "grade high" << std::endl;
		return (1);
	}

 	return (0);
 }

// int	main( void )
// {
// 	Bureaucrat hari("Hari", 150);
// 	std::cout << hari << std::endl;
// 	hari.incGrade();
// 	std::cout << hari << std::endl;

// 	try {
// 		hari.decGrade();
// 		std::cout << hari << std::endl;
// 		hari.decGrade();
// 		std::cout << hari << std::endl;
// 	}
// 	catch (Bureaucrat::GradeTooLowException)
// 	{
// 		std::cout << "grade low" << std::endl;
// 		return (1);
// 	}
// 	catch (Bureaucrat::GradeTooHighException)
// 	{
// 		std::cout << "grade high" << std::endl;
// 		return (1);
// 	}
	

// 	return (0);
// }

// int	main( void )
// {
// 	Bureaucrat hari("Hari", 1);
// 	std::cout << hari << std::endl;
// 	hari.decGrade();
// 	std::cout << hari << std::endl;

// 	try {
// 		hari.incGrade();
// 		std::cout << hari << std::endl;
// 		hari.incGrade();
// 		std::cout << hari << std::endl;
// 	}
// 	catch (Bureaucrat::GradeTooLowException)
// 	{
// 		std::cout << "grade low" << std::endl;
// 		return (1);
// 	}
// 	catch (Bureaucrat::GradeTooHighException)
// 	{
// 		std::cout << "grade high" << std::endl;
// 		return (1);
// 	}
	

// 	return (0);
// }