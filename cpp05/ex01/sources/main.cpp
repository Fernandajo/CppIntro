#include "../includes/Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat bob("Bob", 150);
		std::cout << bob;
	} catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat Macious("Macious", 0);
		std::cout << Macious;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}
	
	try
	{
		Bureaucrat john("John", 151);
		std::cout << john;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}

	try
	{
		Bureaucrat Ferni("Ferni", 42);
		std::cout << Ferni;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}
	
	return 0;
}