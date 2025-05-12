#include "../includes/ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		ScalarConverter::convert(av[1]);
		return 0;
	}
	std::cout << "Invalid input" << std::endl;
	return 1;
}