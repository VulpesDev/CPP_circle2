#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

// int	main( void )
// {
// 	Form	f1("form1", 55, 56);

// 	std::cout << f1 << std::endl;
//  	return (0);
//  }

//  int	main( void )
// {
// 	Form	f1("form1", 151, 56);

// 	std::cout << f1 << std::endl;
//  	return (0);
//  }

//   int	main( void )
// {
// 	Form	f1("form1", 0, 56);

// 	std::cout << f1 << std::endl;
//  	return (0);
//  }

//    int	main( void )
// {
// 	Form	f1("form1", 55, 151);

// 	std::cout << f1 << std::endl;
//  	return (0);
//  }

//     int	main( void )
// {
// 	Form	f1("form1", 55, 0);

// 	std::cout << f1 << std::endl;
//  	return (0);
//  }

// int	main( void )
// {
// 	Form	f1("form1", 55, 56);
// 	Bureaucrat Josh("Josh", 54);
// 	std::cout << Josh << std::endl << std::endl;
// 	std::cout << f1 << std::endl;
// 	Josh.signForm(f1);
//  	return (0);
//  }

int	main( void )
{
	Form	f1("form1", 53, 56);
	Bureaucrat Josh("Josh", 54);
	std::cout << Josh << std::endl << std::endl;
	std::cout << f1 << std::endl;
	Josh.signForm(f1);
 	return (0);
 }