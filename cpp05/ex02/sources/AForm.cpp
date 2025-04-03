#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _gradeToSign(150), _gradeToExec(150)
{
	_signed = false;
	std::cout << "AForm Default was created with minimum grade to sign and execute" << std::endl;
}

AForm::AForm(const std::string name, int gradeSign, int gradeExec) : _name(name), _gradeToSign(gradeSign), _gradeToExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	else if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
	_signed = false;
	std::cout << "AForm called: " << _name << " was created with " << _gradeToSign << " grade needed to sign and " << _gradeToExec << " grade needed to execute" << std::endl;
}

AForm::AForm(const AForm &other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec), _signed(other._signed)
{
	std::cout << "Copy constructor of AForm called: " << _name << " was called!" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm called: " << _name << " was destroyed!" << std::endl;
}

// void AForm::beSigned(Bureaucrat *bureau)
// {
// 	if (!bureau)
// 	{
// 		std::cerr << "Error: Bureaucrat pointer is null!" << std::endl;
// 		return ;
// 	}
// 	if (bureau->getGrade() > _gradeToSign)
// 		throw GradeTooLowException();
// 	else
// 		_signed = true;
// }

bool AForm::getSigned() const { return _signed; }

int AForm::getGradeToSign() const { return _gradeToSign; }

int AForm::getGradeToExec() const { return _gradeToExec; }

const std::string AForm::getName() const { return _name; }

std::ostream &operator<<(std::ostream &out, const AForm &other)
{
	out << "AForm: " << other.getName() << " has grade to sign of: " << other.getGradeToSign() << " and grade to execute of: " << other.getGradeToExec() << ", is the Aform signed? " << other.getSigned() << std::endl;
	return (out);
}

const char* AForm::GradeTooHighException::what() const throw() { return "Grade is too high!"; }
const char* AForm::GradeTooLowException::what() const throw() { return "Grade is too low!"; }