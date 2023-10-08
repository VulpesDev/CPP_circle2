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
		virtual ~AForm();

		AForm &		operator=( AForm const & rhs );

		std::string	getName() const;
		bool		getSign() const;
		int			getReqsign() const;
		int			getReqexec() const;
		std::string getTarget() const;

		std::ostream&	print(std::ostream& os) const;
		
		void	beSigned( Bureaucrat const & rhs );
		virtual void	execute( Bureaucrat const & executor ) const;

		class GradeTooHighException : public std::exception {
			public :
				const char* what() const throw(){
					return "Grade is too high";
				}
		};
		class GradeTooLowException : public std::exception {
			public :
				const char* what() const throw(){
					return "Grade is too low";
				}
		};
		class FormNotSignedException : public std::exception {
			public :
				const char* what() const throw(){
					return "Form is not signed";
				}
		};
		

	private:
		const std::string	name;
		bool				sign;
		const int			reqsign;
		const int			reqexec;

	protected:
		std::string	target;

};

std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif /* ************************************************************ AFORM_H */