#ifndef INTVALUECONVERTER_HPP
# define INTVALUECONVERTER_HPP

#include "AValueConverter.hpp"

class IntValueConverter : public AValueConverter
{

	public:

		IntValueConverter(std::string s);
		IntValueConverter(IntValueConverter const & src);
		IntValueConverter &	operator=(IntValueConverter const & rhs);
		int	getValue() const;
	private:
		int value;

};

#endif /* *********************************************** INTVALUECONVERTER_H */