#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5)
{
	_target = "Unknown";
	std::cout << "Presidential Pardon Form was created!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5)
{
	_target = target;
	std::cout << "Presidential Pardon Form was created!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
	_target = other._target;
	std::cout << "Presidential Pardon Form's copy constructor called!" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	std::cout << "Presidential Pardon Form's copy assignment operator called!" << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon Form's destructor called!" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if(!getSigned())
		throw NotSignedException();
	if(executor.getGrade() > getGradeToExec())
		throw GradeTooLowException();
	else
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}