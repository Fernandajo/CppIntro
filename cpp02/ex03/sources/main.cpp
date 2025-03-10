#include "../includes/Point.hpp"

// int main( void ) {
// 	Fixed a;
// 	Fixed const b( 10 );
// 	Fixed const c( 42.42f );
// 	Fixed const d( b );
// 	// a = Fixed( 1234.4321f );
// 	std::cout << "a is " << a << std::endl;
// 	std::cout << "b is " << b << std::endl;
// 	std::cout << "c is " << c << std::endl;
// 	std::cout << "d is " << d << std::endl;
// 	std::cout << "b + d is " << b + d << std::endl;
// 	std::cout << "++a " << ++a << std::endl;
// 	std::cout << "is b bigger than c? " << (c < b) << std::endl;
// 	std::cout << "is c bigger than b? " << (c > b) << std::endl;
// 	std::cout << "is b bigger or equal to d? " << (b >= d) << std::endl;
// 	std::cout << "is b smaller or equal to d? " << (b <= d) << std::endl;
// 	std::cout << "is b bigger or equal to a? " << (b >= a) << std::endl;
// 	std::cout << "is b equal to d? " << (b == d) << std::endl;
// 	std::cout << "is b not equal to d? " << (b != d) << std::endl;
// 	std::cout << "is b bigger or equal to c? " << (b == c) << std::endl;
// 	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
// 	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
// 	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
// 	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
// 	return 0;
// 	}

// int main( void ) {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }

int	main()
{
	Point a(2, 3);
	std::cout << a.getValueX() << std::endl;
	std::cout << a.getValueY() << std::endl;
	return 0;
}