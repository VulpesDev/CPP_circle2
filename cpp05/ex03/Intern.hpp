#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		Intern &		operator=( Intern const & rhs );

		AForm *	checkMakeForm(std::string name, std::string target) const;
		AForm *	makeForm(std::string name, std::string target) const;

		class FormNameException : public std::exception {
			public :
				const char* what() const throw(){
					return "Invalid name";
				}
		};

		enum	FormType{
			shrubberyCreation,
			robotomyRequest,
			presidentalPardon
		};

	private:
};

std::ostream &			operator<<( std::ostream & o, Intern const & i );

#endif /* ********************************************************** INTERN_H */