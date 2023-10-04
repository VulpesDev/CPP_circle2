#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat;
# include "AForm.hpp"

class Bureaucrat
{

	public:

		Bureaucrat(std::string name, int grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );

		int			getGrade() const;
		std::string	getName() const;

		void		incGrade();
		void		decGrade();

		void		signForm( AForm & rhs ) const;
		void		executeForm(AForm const & form) const;

		class GradeTooHighException : public std::exception {
			public :
				const char* what() const noexcept override{
					return "Grade is too high";
				}
		};

		class GradeTooLowException : public std::exception {
			public :
				const char* what() const noexcept override{
					return "Grade is too low";
				}
		};

	private:
		const std::string	name;
		int					grade;
};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */