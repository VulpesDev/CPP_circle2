#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <string>
# include <sstream>
# include <climits>
# include <stdlib.h>
# include <cstdlib>
# include <cctype>

class BitcoinExchange
{

	public:

		BitcoinExchange(std::string datafName, std::string inputfName);
		BitcoinExchange( BitcoinExchange const & src );
		~BitcoinExchange();

		BitcoinExchange &		operator=( BitcoinExchange const & rhs );
		
		std::multimap<std::string, std::string>	csv_data;
		std::multimap<std::string, std::string>	input_data;
		int format_check(const std::map<std::string, std::string>::const_iterator it,
							long double bitCount) const;

	private:
		std::string datafName;
		std::string inputfName;
		std::string	noSpace(const std::string &s);
		int    		err(const std::string &s) const;
		void		getColumnData(const std::string &filename,
							int columnKey, int columnValue,
							std::multimap<std::string, std::string> &result,
							char denom);
		int			date_format_check( std:: string s ) const;
};

std::ostream &			operator<<( std::ostream & o, BitcoinExchange const & i );

#endif /* ************************************************* BITCOINEXCHANGE_H */