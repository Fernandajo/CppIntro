#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../includes/Span.hpp"

int main() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    try {
        std::cout << "=== Basic tests ===" << std::endl;
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;

        std::cout << "\n=== Attempt to overfill ===" << std::endl;
        try {
            sp.addNumber(42);
        } catch (std::exception &e) {
            std::cout << "Expected exception: " << e.what() << std::endl;
        }

        std::cout << "\n=== Small span test ===" << std::endl;
        Span small(2);
        small.addNumber(1);
        small.addNumber(100);
        std::cout << "Shortest span: " << small.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << small.longestSpan() << std::endl;

        std::cout << "\n=== Exception with too few elements ===" << std::endl;
        Span empty(5);
        try {
            empty.shortestSpan();
        } catch (std::exception &e) {
            std::cout << "Expected exception: " << e.what() << std::endl;
        }

        empty.addNumber(10);
        try {
            empty.longestSpan();
        } catch (std::exception &e) {
            std::cout << "Expected exception: " << e.what() << std::endl;
        }

        std::cout << "\n=== Large test with 10,000 numbers ===" << std::endl;
        unsigned int N = 10000;
        Span big(N);
        big.addMultiNumbers();
        std::cout << "Shortest span: " << big.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << big.longestSpan() << std::endl;

        std::cout << "\n=== Custom fill with duplicates ===" << std::endl;
        Span dup(5);
        dup.addNumber(42);
        dup.addNumber(42);
        dup.addNumber(42);
        dup.addNumber(43);
        dup.addNumber(41);
        std::cout << "Shortest span: " << dup.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << dup.longestSpan() << std::endl;

    } catch (std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
