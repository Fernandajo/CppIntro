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

void runTest(Point const &a, Point const &b, Point const &c, Point const &p, bool expected)
{
	bool result = bsp(a, b, c, p);
	std::cout << "Point(" << p.getFixedX() << ", " << p.getFixedY() << ") -> " << "Expected: " << (expected ? "true" : "false") << ", Got: " << (result ? "true" : "false") << std::endl;
}

int main()
{
    Point a(0, 0);
	Point b(5, 0);
	Point c(2, 5);

    // Inside cases
	std::cout << "=== Inside Cases ===" << std::endl;
    runTest(a, b, c, Point(2, 2), true);
    runTest(a, b, c, Point(1, 1), true);
    runTest(a, b, c, Point(2, 3), true);
    runTest(a, b, c, Point(3, 2), true);
    runTest(a, b, c, Point(2, 1), true);
    runTest(a, b, c, Point(1.5f, 2.5f), true);
    runTest(a, b, c, Point(2.2f, 2.2f), true);
    runTest(a, b, c, Point(1.8f, 1.8f), true);
    runTest(a, b, c, Point(1, 2), true);
    runTest(a, b, c, Point(3, 1), true);
    
    // Outside cases
	std::cout << "\n=== Outside Cases ===" << std::endl;
    runTest(a, b, c, Point(-1, -1), false);
    runTest(a, b, c, Point(6, 6), false);
    runTest(a, b, c, Point(0, 6), false);
    runTest(a, b, c, Point(5, 5), false);
    runTest(a, b, c, Point(6, 0), false);
    runTest(a, b, c, Point(-2, 2), false);
    runTest(a, b, c, Point(4, -1), false);
    runTest(a, b, c, Point(3, 4), false);
    runTest(a, b, c, Point(2, -1), false);
    runTest(a, b, c, Point(4, 5), false);
    
    // Edge cases
	std::cout << "\n=== Edge Cases ===" << std::endl;
    runTest(a, b, c, Point(2.5f, 0), false);
    runTest(a, b, c, Point(3.5f, 2.5f), false);
    runTest(a, b, c, Point(1, 0), false);
    runTest(a, b, c, Point(4, 0), false);
    
    // Vertex cases
	std::cout << "\n=== Vertex Cases ===" << std::endl;
    runTest(a, b, c, Point(0, 0), false);
    runTest(a, b, c, Point(5, 0), false);
    runTest(a, b, c, Point(2, 5), false);
    
    return 0;
}