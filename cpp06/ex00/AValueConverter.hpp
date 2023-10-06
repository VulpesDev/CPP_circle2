#ifndef AVALUECONVERTER_HPP
# define AVALUECONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>

class AValueConverter
{

	public:

		AValueConverter();
		AValueConverter( AValueConverter const & src );
		~AValueConverter();

		AValueConverter &		operator=( AValueConverter const & rhs );

		std::string	getS_rec() const;

	protected:
		std::stringstream	s_rep;

};

std::ostream &			operator<<( std::ostream & o, AValueConverter const & i );

#endif /* ************************************************* AVALUECONVERTER_H */