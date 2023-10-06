#ifndef INTVALUECONVERTER_HPP
# define INTVALUECONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>

class IntValueConverter
{

	public:

		IntValueConverter(std::string s);
		IntValueConverter( IntValueConverter const & src );
		~IntValueConverter();

		IntValueConverter &		operator=( IntValueConverter const & rhs );

		int	getValue() const;
		std::string	getS_rec() const;

	private:
		std::stringstream	s_rep;
		int	value;
};

std::ostream &			operator<<( std::ostream & o, IntValueConverter const & i );

#endif /* *********************************************** INTVALUECONVERTER_H */