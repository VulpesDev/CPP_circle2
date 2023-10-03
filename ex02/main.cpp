#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main( void )
{
	ShrubberyCreationForm f("Shrubbery form");
	std::cout << f << std::endl;
 	return (0);
 }