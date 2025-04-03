#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "Bureaucrat default with minimium grade was created!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
	std::cout << "Bureaucrat " << _name << " with grade: " << _grade << " was created!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	*this = other;
	std::cout << "Copy constructor of Bureaucrat " << _name << " was called!" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		_grade = other._grade;
	}
	return *this;
	std::cout << "Copy assignment operator of Bureaucrat " << _name << " was called!" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor of Bureaucrat " << getName() << " was called!" << std::endl;
}

const std::string Bureaucrat::getName() const { return (_name); }

int Bureaucrat::getGrade() const { return (_grade); }

const char* Bureaucrat::GradeTooHighException::what() const throw() { return "Grade is too high!"; }

const char* Bureaucrat::GradeTooLowException::what() const throw() { return "Grade is too low!"; }

// grade 1 is the highest, grade 150 is the lowest
void Bureaucrat::incrementGrade()
{
	if((_grade - 1) <= 0)
		throw GradeTooHighException();
	else
		_grade--;
}

void Bureaucrat::decrementGrade()
{
	if((_grade + 1) >= 150)
		throw GradeTooLowException();
	else
		_grade++;
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat& other)
{
	out << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
	return (out);
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{

}