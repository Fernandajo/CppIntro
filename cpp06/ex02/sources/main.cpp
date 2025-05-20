#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

int main()
{
	srand(time(0));
	std::cout << "First Try: ";
	Base *t = generate();
	identify(t);
	std::cout << "Second Try: ";
	Base *o = generate();
	identify(*o);
	std::cout << "Third Try: ";
	identify(generate());
	std::cout << "Fourth Try: ";
	identify(*generate());
	Base *a = new A;
	identify(a);
	Base *b = new B;
	identify(*b);
	Base *c = new C;
	identify(*c);
	return 0;
}