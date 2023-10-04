#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
#include <iostream>
#include <fstream>

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{

	public:

		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		~ShrubberyCreationForm();

		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );

		void	execute( Bureaucrat const & executor ) const override;

		std::string getTarget();

		class FileCreationException : public std::exception {
			public :
				const char* what() const noexcept override{
					return "Could not create a file, sorry";
				}
		};

	private:
		std::string	target;
};

//std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i );

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */