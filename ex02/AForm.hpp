#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
class AForm;
# include "Bureaucrat.hpp"

class AForm
{

	public:

		AForm(std::string name, int reqsign, int reqexec);
		AForm( AForm const & src );
		~AForm();

		AForm &		operator=( AForm const & rhs );

		std::string	getName() const;
		bool		getSign() const;
		int		getReqsign() const;
		int		getReqexec() const;

		void	beSigned( Bureaucrat const & rhs );
		std::ostream&	print(std::ostream& os) const;

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

std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif /* ************************************************************ AFORM_H */