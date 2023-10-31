#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <stack>
# include <sstream>

class RPN
{

	public:

		RPN();
		RPN( RPN const & src );
		~RPN();

		RPN &		operator=( RPN const & rhs );

		static int	calculate(std::string s);

		class InvalidSymbolException : public std::exception {
			public :
				const char* what() const throw(){
					return "Error";
				}
		};

		class DException : public std::exception {
			public :
				const char* what() const throw(){
					return "OutOfRange";
				}
		};

	private:
		static std::stack<int> num_stack;

};

std::ostream &			operator<<( std::ostream & o, RPN const & i );

#endif /* ************************************************************* RPN_H */