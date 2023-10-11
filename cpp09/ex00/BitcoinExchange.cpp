#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange(std::string datafName, std::string inputfName) : datafName(datafName), inputfName(inputfName)
{
	getColumnData(datafName, 1, 2, csv_data, ',');
	getColumnData(inputfName, 1, 2, input_data, '|');
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src )
{
	this->datafName = src.datafName;
	this->inputfName = src.inputfName;
	this->csv_data = src.csv_data;
	this->input_data = src.input_data;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &				BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	if ( this != &rhs )
	{
		this->datafName = rhs.datafName;
		this->inputfName = rhs.inputfName;
		this->csv_data = rhs.csv_data;
		this->input_data = rhs.input_data;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, BitcoinExchange const & i )
{
	for (std::map<std::string, std::string>::const_iterator it = i.input_data.begin(); it != i.input_data.end(); ++it)
    {
        double bitCount = 0, bitValue = 1;
        if (!it->first.empty() && !it->second.empty())
        {
            bitValue = std::strtod(i.csv_data.lower_bound(it->first)->second.c_str(), 0);
            bitCount = std::strtod(it->second.c_str(), 0);
        }
        if (!i.format_check(it, bitCount))
           	o << it->first << " => " << bitCount << " = " << bitCount*bitValue << std::endl;
    }
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

	std::string	BitcoinExchange::noSpace(const std::string &s)
	{
		std::string result;
    	for (size_t i = 0; i < s.length(); i++)
    	{
    	    if(s[i] != ' ')
    	        result += s[i];
    	}
    	return result;
	}

	int    		BitcoinExchange::err(const std::string &s) const
	{
		std::cerr << "Error: " << s << std::endl;
    	return (1);
	}

	int     	BitcoinExchange::format_check(const std::map<std::string, std::string>::const_iterator it,
							long double bitCount) const
	{
			if (it->first.empty() || it->second.empty())
   			     return err("bad input => " + (it->first.empty()? it->second.empty()? NULL : it->second : it->first));
   			 else if (bitCount < 0)
   			     return err("not a positive number.");
   			 else if (bitCount > 1000)
   			     return err("too large a number.");
   			 return (0);
	}

	void		BitcoinExchange::getColumnData(const std::string &filename,
							int columnKey, int columnValue,
							std::multimap<std::string, std::string> &result,
							char denom)
	{
		std::ifstream inputFile(filename.c_str());
   		 if (!inputFile.is_open()) {
   		     std::cerr << "Error: Could not open the file." << std::endl;
   		     return;
   		 }

   		 std::string line;
   		 while (std::getline(inputFile, line)) {
   		     std::stringstream ss(line);
   		     std::string token;
   		     std::string key = "", value = "";
   		     int currentColumn = 1;

   		     while (std::getline(ss, token, denom)) {
   		         if (currentColumn == columnKey) {
   		             key = noSpace(token);
   		         }
   		         if (currentColumn == columnValue) {
   		             value = noSpace(token);
   		         }
   		         currentColumn++;
   		     }
   		     result.insert(std::make_pair(key, value));
   		 }
   		 inputFile.close();
	}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */