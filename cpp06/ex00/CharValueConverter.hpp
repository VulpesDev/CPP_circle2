#ifndef CHARVALUECONVERTER_HPP
# define CHARVALUECONVERTER_HPP

# include "AValueConverter.hpp"

class CharValueConverter : public AValueConverter
{

	public:

		CharValueConverter(std::string s);
		CharValueConverter( CharValueConverter const & src );
		CharValueConverter &		operator=( CharValueConverter const & rhs );

		int	getValue() const;
	private:
		int value;

};

#endif /* ******************************************** CharVALUECONVERTER_H */