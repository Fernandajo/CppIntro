#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

Form::Form() : _name("Default"), _gradeToSign(150), _gradeToExec(150)
{
	_signed = false;
	std::cout << "Form Default was created with minimum grade to sign and execute" << std::endl;
}

Form::Form(const std::string name, int gradeSign, int gradeExec) : _name(name), _gradeToSign(gradeSign), _gradeToExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	else if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
	_signed = false;
	std::cout << "Form called: " << _name << " was created with " << _gradeToSign << " grade needed to sign and " << _gradeToExec << " grade needed to execute" << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec), _signed(other._signed)
{
	std::cout << "Copy constructor of Form called: " << _name << " was called!" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Form called: " << _name << " was destroyed!" << std::endl;
}

void Form::beSigned(Bureaucrat *bureau)
{
	if (!bureau)
	{
		std::cerr << "Error: Bureaucrat pointer is null!" << std::endl;
		return ;
	}
	if (bureau->getGrade() > _gradeToSign)
		throw GradeTooLowException();
	else
		_signed = true;
}

bool Form::getSigned() const { return _signed; }

int Form::getGradeToSign() const { return _gradeToSign; }

int Form::getGradeToExec() const { return _gradeToExec; }

const std::string Form::getName() const { return _name; }

std::ostream &operator<<(std::ostream &out, const Form &other)
{
	out << "Form: " << other.getName() << " has grade to sign of: " << other.getGradeToSign() << " and grade to execute of: " << other.getGradeToExec() << ", is the form signed? " << other.getSigned() << std::endl;
	return (out);
}

const char* Form::GradeTooHighException::what() const throw() { return "Grade is too high!"; }
const char* Form::GradeTooLowException::what() const throw() { return "Grade is too low!"; }