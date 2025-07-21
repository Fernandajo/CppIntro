#include "../includes/whatever.hpp"
#include <string>
#include <iostream>

// int main()
// {
// 	std::cout << max<int>(3, 7) << std::endl;
// 	std::cout << min<int>(3, 7) << std::endl;
// 	int x = 4; 
// 	int y = 7;
// 	std::cout << max<int>(x, y) << std::endl;
// 	std::cout << "x: " << x << std::endl << "y: " << y << std::endl;
// 	swap(x, y);
// 	std::cout << "x: " << x << std::endl << "y: " << y << std::endl;
// 	return 0;
// }

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}