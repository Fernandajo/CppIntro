#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

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
		RobotomyRequestForm r("R");
		Macious.signForm(r);
		Macious.executeForm(r);
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
		ShrubberyCreationForm a("amor");
		Ferni.signForm(a);
		Ferni.executeForm(a);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}

	try
	{
		PresidentialPardonForm k("job");
		std::cout << k;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}
	
	
	return 0;
}