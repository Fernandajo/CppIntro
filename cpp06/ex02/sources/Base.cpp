#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

Base::~Base() {}

Base* generate(void)
{
	int r = rand() % 3;
	switch (r) {
		case 0: return new A;
		case 1: return new B;
		case 2: return new C;
	}
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type C" << std::endl;
}

void identify(Base& p)
{
	Base T;
	try
	{
		T = dynamic_cast<A&>(p);
		std::cout << "Type A" << std::endl;
	}
	catch(const std::exception& e) {}
	
	try
	{
		T = dynamic_cast<B&>(p);
		std::cout << "Type B" << std::endl;
	}
	catch(const std::exception& e) {}
	
	try
	{
		T = dynamic_cast<C&>(p);
		std::cout << "Type C" << std::endl;
	}
	catch(const std::exception& e) {}
	
}