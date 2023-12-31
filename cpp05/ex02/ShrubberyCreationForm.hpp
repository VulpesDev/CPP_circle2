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

		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		~ShrubberyCreationForm();

		void	execute( Bureaucrat const & executor ) const;

		class FileCreationException : public std::exception {
			public :
				const char* what() const throw(){
					return "Could not create a file, sorry";
				}
		};

	private:
};


#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */