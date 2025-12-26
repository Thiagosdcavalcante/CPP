#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <cstring>
# include <limits>
# include <climits>
# include <cfloat>
# include <cctype>
# include <cmath>

# include <sstream>


class ScalarConverter{

private:
	ScalarConverter(void);
	~ScalarConverter(void);
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);

public:
	static void convert(const std::string &input);
};

#endif