#include "../includes/Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern was created!" << std::endl;
}

Intern::Intern(const Intern &other)
{
	*this = other;
	std::cout << "Copy constructor of Intern called!" << std::endl;
}
Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
		*this = other;
	std::cout << "Intern's copy assignment operator called!" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern was destroyed!" << std::endl;
}

struct KeywordAction {
	const char* keyword;
	AForm* (*create)(const std::string&); // pointer to function returning a AForm*
};

AForm* Intern::createShrubbery(const std::string &target) { return new ShrubberyCreationForm(target); }
AForm* Intern::createRobotomy(const std::string &target) { return new RobotomyRequestForm(target); }
AForm* Intern::createPresidential(const std::string &target) { return new PresidentialPardonForm(target); }

AForm *Intern::makeForm(const std::string &nameForm, const std::string &nameTarget)
{
	KeywordAction actions[] = {
        { "Shrubbery", &Intern::createShrubbery },
        { "Robotomy", &Intern::createRobotomy },
        { "Presidential", &Intern::createPresidential }
    };

    for (int i = 0; i < 3; ++i) {
        if (nameForm.find(actions[i].keyword) != std::string::npos) {
			std::cout << "Intern creates form " << nameForm << std::endl;
            return actions[i].create(nameTarget); // return the object
        }
    }
	std::cout << "Form name " << nameForm << " not recognized" << std::endl;
    return NULL; // no match
}
