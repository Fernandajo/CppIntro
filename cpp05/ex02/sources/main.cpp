#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
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
		Bureaucrat ana("Ana", 0);
		std::cout << ana;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	

	try
	{
		Bureaucrat Macious("Macious", 23);
		std::cout << Macious;
		Form r("R", 24, 23);
		Macious.signForm(r);
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
		Form a("amor", 50, 55);
		Form b(a);
		Ferni.signForm(b);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}

	try
	{
		Form k("job", 0, 42);
		std::cout << k;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}
	
	
	return 0;
}