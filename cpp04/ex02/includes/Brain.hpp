#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string.h>
class Brain
{
protected:
	std::string _ideas[100];
public:
	Brain();
	~Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);

	void	setIdeas(int count, std::string idea);
	std::string	getIdeas(int i) const;
};




#endif