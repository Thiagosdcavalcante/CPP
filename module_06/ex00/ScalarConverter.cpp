#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void){}

ScalarConverter::~ScalarConverter(void){}

ScalarConverter::ScalarConverter(const ScalarConverter &other){
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other){
	if (this == &other){
		return *this;
	}
	return *this;
}


static bool isSpecialLiteral(const std::string& input, double& value, std::string& pseudoStr) {
	if (input == "nan" || input == "nanf") {
		value = std::numeric_limits<double>::quiet_NaN();
		pseudoStr = "nan";
		return true;
	}
	if (input == "+inf" || input == "+inff") {
		value = std::numeric_limits<double>::infinity();
		pseudoStr = "+inf";
		return true;
	}
	if (input == "-inf" || input == "-inff") {
		value = -std::numeric_limits<double>::infinity();
		pseudoStr = "-inf";
		return true;
	}
	return false;
}

static bool isDisplayableChar(double value) {
	char c = static_cast<char>(value);
	return value >= 0 && value <= 127 && std::isprint(c);
}

static bool isInteger(double value) {
	return value == static_cast<int>(value);
}

static void printConversions(double value, bool isPseudo, const std::string& pseudoStr) {
	if (isPseudo || value < 0 || value > 127  || !isInteger(value))
		std::cout << "char: impossible" << std::endl;
	else if (!isDisplayableChar(value))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

	if (isPseudo || value < INT_MIN || value > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;

	std::cout << "float: ";
	if (isPseudo)
		std::cout << pseudoStr << "f" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;

	std::cout << "double: ";
	if (isPseudo)
		std::cout << pseudoStr << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}

void ScalarConverter::convert(const std::string& input) {
	double value = 0.0;
	bool isPseudo = false;
	std::string pseudoStr;

	if (input.length() == 1 && !std::isdigit(input[0])) {
		value = static_cast<double>(input[0]);
	}
	else if (isSpecialLiteral(input, value, pseudoStr)) {
		isPseudo = true;
	}
	else {
		std::string trimmed = input;
		if (input.length() > 1 && input[input.length() - 1] == 'f')
			trimmed = input.substr(0, input.length() - 1);

		std::istringstream ss(trimmed);
		ss >> value;

		if (ss.fail() || !ss.eof()) {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
	}

	printConversions(value, isPseudo, pseudoStr);
}