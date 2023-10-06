#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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

//    int	main( void )
// {
// 	Bureaucrat	nasty("Nasty", 149);
// 	Bureaucrat	steve("Steve", 55);
// 	Bureaucrat	pete("Pete", 44);
// 	RobotomyRequestForm r("home");
// 	std::cout << r << std::endl;
// 	nasty.signForm(r);
// 	steve.signForm(r);
// 	steve.executeForm(r);
// 	pete.executeForm(r);
//  	return (0);
//  }

//    int	main( void )
// {
// 	Bureaucrat	nasty("Nasty", 149);
// 	Bureaucrat	steve("Steve", 22);
// 	Bureaucrat	pete("Pete", 1);
// 	PresidentialPardonForm r("home");
// 	std::cout << r << std::endl;
// 	nasty.signForm(r);
// 	steve.signForm(r);
// 	steve.executeForm(r);
// 	pete.executeForm(r);
//  	return (0);
//  }

   int	main( void )
{
	Bureaucrat	boss("Kurt", 1);
	Intern someRandomIntern;
	AForm* rrf;
	AForm* pres;
	AForm* shrub;
	AForm* thub;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	pres = someRandomIntern.makeForm("presidential pardon", "Cooper");
	shrub = someRandomIntern.makeForm("shrubbery creation", "home");
	thub = someRandomIntern.makeForm("thub", "t");
	
	boss.signForm(*shrub);
	boss.signForm(*pres);
	boss.executeForm(*shrub);
	boss.executeForm(*pres);
	delete(rrf);
	delete(shrub);
	delete(pres);
 	return (0);
 }