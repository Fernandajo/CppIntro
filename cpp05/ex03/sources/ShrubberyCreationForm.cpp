#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137)
{
	_target = "Unknown";
	std::cout << "Shrubbery Creation Form was created!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Creation Form", 145, 137)
{
	//creates a file and writes a ASCII tree inside it
	_target = target;
	std::cout << "Shrubbery Creation Form was created!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	_target = other._target;
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if(this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	std::cout << "Shrubbery Creation Form's copy assignment operator called!" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Creation Form destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if(!getSigned())
		throw NotSignedException();
	if(executor.getGrade() > getGradeToExec())
		throw GradeTooLowException();
	else{
		std::ofstream newfile((_target + "_shrubbery").c_str());
		if (newfile.is_open()){
			newfile << "       /\\ \n";
			newfile << "      /**\\ \n";
			newfile << "     /****\\ \n";
			newfile << "    /******\\ \n";
			newfile << "   /********\\ \n";
			newfile << "  /**********\\ \n";
			newfile << " /************\\ \n";
			newfile << "/**************\\ \n";
			newfile << "      |||| \n";
			newfile << "      ||||";
			newfile.close();
		}
		else
			throw std::ofstream::failure("Couldn't create file!");
	}
}