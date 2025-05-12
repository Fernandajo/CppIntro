#include "../includes/ScalarConverter.hpp"
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cerrno>
#include <cmath>

static void printChar(double d)
{
	std::cout << "char: ";
	if(d >= 0 && d <= 127){
		char c = static_cast<char>(d);
		if(isprint(c))
			std::cout << '\'' << c << '\'' << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
		std::cout << "Impossible" << std::endl;
}

static void printInt(double d)
{
	std::cout << "int: ";
	if(std::isnan(d) || std::isinf(d) || d > INT_MAX || d < INT_MIN)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
}

static void printDouble(double d)
{
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

static void printFloat(double d)
{
	float f = static_cast<float>(d);
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
	double d = 0.0;

	if (literal.length() == 1 && isascii(literal[0]) && !isdigit(literal[0]))
		d = static_cast<double>(literal[0]);
	else if (literal == "+inf" || literal == "+inff")
		d = std::numeric_limits<double>::infinity();
	else if (literal == "-inf" || literal == "-inff") 
		d = -std::numeric_limits<double>::infinity();
	else if (literal == "nan" || literal == "nanf")
		d = std::numeric_limits<double>::quiet_NaN();
	else {
		char *endptr = NULL;
		errno = 0;
		d = std::strtod(literal.c_str(), &endptr);
		if ((*endptr != '\0' && *endptr != 'f') || (*endptr == 'f' && *(endptr + 1) != '\0')) {
			std::cout << "Invalid input" << std::endl;
			return ;
		}
	}
	printChar(d);
	printInt(d);
	printDouble(d);
	printFloat(d);
	}