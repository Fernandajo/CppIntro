#ifndef AFORM_HPP
#define AFORM_HPP

#include <string.h>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	const int _gradeToSign;
	const int _gradeToExec;
	bool _signed;
public:
	AForm();
	AForm(const std::string name, int gradeSign, int gradeExec);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();

	virtual void beSigned(Bureaucrat *bureau) = 0;
	virtual void execute(Bureaucrat const & executor) const = 0;

	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
	const std::string getName() const;

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &other);

#endif