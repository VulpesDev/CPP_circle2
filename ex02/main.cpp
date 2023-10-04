#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

// int	main( void )
// {
// 	Bureaucrat	steve("Steve", 122);
// 	ShrubberyCreationForm f("home");
// 	std::cout << f << std::endl;
// 	steve.signForm(f);
// 	steve.executeForm(f);
//  	return (0);
//  }

//  int	main( void )
// {
// 	Bureaucrat	steve("Steve", 122);
// 	ShrubberyCreationForm f("home");
// 	std::cout << f << std::endl;
// 	//steve.signForm(f);
// 	steve.executeForm(f);
//  	return (0);
//  }
 
//   int	main( void )
// {
// 	Bureaucrat	steve("Steve", 138);
// 	ShrubberyCreationForm f("home");
// 	std::cout << f << std::endl;
// 	steve.signForm(f);
// 	steve.executeForm(f);
//  	return (0);
//  }

//    int	main( void )
// {
// 	Bureaucrat	steve("Steve", 150);
// 	ShrubberyCreationForm f("home");
// 	std::cout << f << std::endl;
// 	steve.signForm(f);
// 	steve.executeForm(f);
//  	return (0);
//  }

//    int	main( void )
// {
// 	Bureaucrat	steve("Steve", 1);
// 	RobotomyRequestForm r("home");
// 	std::cout << r << std::endl;
// 	steve.signForm(r);
// 	steve.executeForm(r);
//  	return (0);
//  }

   int	main( void )
{
	Bureaucrat	nasty("Nasty", 149);
	Bureaucrat	steve("Steve", 55);
	Bureaucrat	pete("Pete", 44);
	RobotomyRequestForm r("home");
	std::cout << r << std::endl;
	nasty.signForm(r);
	steve.signForm(r);
	steve.executeForm(r);
	pete.executeForm(r);
 	return (0);
 }