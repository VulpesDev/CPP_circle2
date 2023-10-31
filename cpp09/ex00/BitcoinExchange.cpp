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



// OTHER FUNCTIONS ////////////
std::tm ParseDate(const std::string& dateStr)
{
    std::tm parsedDate = {};
    strptime(dateStr.c_str(), "%Y-%m-%d", &parsedDate);
    return parsedDate;
}

bool DateLess(const std::string& dateStr1, const std::string& dateStr2)
{
    std::tm time1 = ParseDate(dateStr1);
    std::tm time2 = ParseDate(dateStr2);

    return std::difftime(std::mktime(&time1), std::mktime(&time2)) <= 0;
}

std::string	SearchLesserDay(std::string input_data, std::multimap<std::string, std::string> csv_data)
{
	for (std::multimap<std::string, std::string>::const_reverse_iterator it2 = csv_data.rbegin(); it2 != csv_data.rend(); ++it2)
   	{
		if (DateLess(it2->first, input_data) && it2->first != "date")
			return it2->first;
	}
	return csv_data.begin()->first;
}
// OTHER FUNCTIONS ////////////



std::ostream &			operator<<( std::ostream & o, BitcoinExchange const & i )
{
	for (std::multimap<std::string, std::string>::const_iterator it = i.input_data.begin(); it != i.input_data.end(); ++it)
    {
        double bitCount = 0, bitValue = 1;
        if (!it->first.empty() && !it->second.empty())
        {
            bitValue = std::strtod(i.csv_data.find(SearchLesserDay(it->first, i.csv_data))->second.c_str(), 0);
            bitCount = std::strtod(it->second.c_str(), 0);
        }
        if (it->first != "date" && it->second != "value" && !i.format_check(it, bitCount))
           	o << it->first << " => " << bitCount << " = " << bitCount*bitValue << std::endl;
    }
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/



// OTHER FUNCTIONS ////////////
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

	bool	isLeapYear(int year)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
   		     return true; // Leap year
   		 } else {
   		     return false; // Non-leap year
    }
	}

	bool isDigitsOnly(const std::string &str) {
	    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
	        if (!std::isdigit(*it)) {
	            return false;
	        }
	    }
	    return true;
	}

	int			date_format_check( std:: string s )
	{
		int y, m, d, counter = 0;
		std::istringstream ss(s);
		std::multimap<int, std::string> tokens;
		std::string token;

		while (std::getline(ss, token, '-'))
		{
			tokens.insert(std::make_pair(counter, token));
			counter++;
		}
		if (counter != 3)
			return 0;
		const char * y_str = tokens.find(0)->second.c_str(),
		* m_str = tokens.find(1)->second.c_str(),
		* d_str = tokens.find(2)->second.c_str();
		if (!isDigitsOnly(y_str) || !isDigitsOnly(m_str) || !isDigitsOnly(d_str))
			return 0;
		try
		{
			y = atoi(y_str);
			m = atoi(m_str);
			d = atoi(d_str);
		}
		catch(const std::exception& e)
		{
			return 0;
		}
		if (y < 1 || m < 1 || m > 12 || d < 1)
			return 0;
		static const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if (isLeapYear(y) && m == 2)
		{
		    if (d <= 29)
		        return 1;
		}
		 else
		 {
		     if (d <= daysInMonth[m])
		         return 1;
		 }
		return 0;
		
	}
		// OTHER FUNCTIONS ////////////




	int     	BitcoinExchange::format_check(const std::map<std::string, std::string>::const_iterator it,
							long double bitCount) const
	{
			if (it->first.empty() || it->second.empty() || !date_format_check(it->first))
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