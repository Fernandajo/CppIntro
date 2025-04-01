#ifndef FORM_HPP
#define FORM_HPP

#include <string.h>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExec;
public:
	Form();
	Form(const std::string name, int gradeSign, int gradeExec);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	void beSigned(Bureaucrat &bureau);

	bool getSigned();
	const int getGradeToSign();
	const int getGradeToExec();
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

std::ostream &operator<<(std::ostream &out, const Form &other);

#endif