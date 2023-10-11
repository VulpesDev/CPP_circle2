#ifndef DOUBLEVALUECONVERTER_HPP
# define DOUBLEVALUECONVERTER_HPP

# include "AValueConverter.hpp"
# include <cmath>
# include <cfloat>
# include <string>

class DoubleValueConverter : public AValueConverter
{

	public:

		DoubleValueConverter(std::string s);
		DoubleValueConverter( DoubleValueConverter const & src );
		DoubleValueConverter &		operator=( DoubleValueConverter const & rhs );

		double	getValue() const;
	private:
		double value;

};

#endif /* ******************************************** DOUBLEVALUECONVERTER_H */