#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
class Form;
# include "Bureaucrat.hpp"

class Form
{

	public:

		Form(std::string name, int reqsign, int reqexec);
		Form( Form const & src );
		~Form();

		Form &		operator=( Form const & rhs );

		std::string	getName() const;
		bool		getSign() const;
		int		getReqsign() const;
		int		getReqexec() const;

		void	beSigned( Bureaucrat const & rhs );

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
		bool				sign;
		const int			reqsign;
		const int			reqexec;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */