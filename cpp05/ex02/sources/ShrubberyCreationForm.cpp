#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137)
{
	_target = "Unknown";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string &target): AForm("Shrubbery Creation Form", 145, 137)
{
	_target = target;
	//creates a file and writes a ASCII tree insite it
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::beSigned(Bureaucrat *bureau)
{

}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{

}