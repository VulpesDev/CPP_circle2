#ifndef FLOATVALUECONVERTER_HPP
# define FLOATVALUECONVERTER_HPP

# include "AValueConverter.hpp"
# include <cmath>
# include <cfloat>
# include <string>

class FloatValueConverter : public AValueConverter
{

	public:

		FloatValueConverter(std::string s);
		FloatValueConverter(FloatValueConverter const & src);
		FloatValueConverter &	operator=(FloatValueConverter const & rhs);
		float	getValue() const;
	private:
		float value;

};

#endif /* ********************************************* FLOATVALUECONVERTER_H */