#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45)
{
	_target = "Unknown";
	std::cout << "Robotomy Request Form was created!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45)
{
	_target = target;
	std::cout << "Robotomy Request Form was created!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
	_target = other._target;
	std::cout << "Robotomy Request Form's copy constructor called!" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Request Form's destructor called!" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	std::cout << "Robotomy Request Form's copy assignment operator called!" << std::endl;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if(!getSigned())
		throw NotSignedException();
	if(executor.getGrade() > getGradeToExec())
		throw GradeTooLowException();
	else{
		std::srand(std::time(0));
		if (std::rand() % 2 == 0) {
			std::cout << "* Making some drilling noises *   " << _target << " has been robotomized sucessufully!" << std::endl;
		} else {
			std::cout << "* Making some drilling noises *  ... " << _target << "'s robotomy has failed!" << std::endl;
		}
	}
}