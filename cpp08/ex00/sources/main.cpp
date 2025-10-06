#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "../includes/easyfind.hpp"

// ANSI color codes for pretty output
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"

template <typename T>
void printContainer(const T& container, const std::string& name)
{
    std::cout << CYAN << name << " contents: " << RESET;
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template <typename T>
void testEasyFind(T& container, int value, const std::string& name)
{
    std::cout << YELLOW << "Searching for " << value << " in " << name << "..." << RESET << std::endl;
    try {
        typename T::iterator it = easyfind(container, value);
        std::cout << GREEN << "✅ Found value: " << *it << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << "❌ " << e.what() << RESET << std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl;
}

int main()
{
    std::cout << "\n" << CYAN << "===== EASYFIND TEST SUITE =====" << RESET << "\n" << std::endl;

    // VECTOR TEST
    std::vector<int> vec;
    for (int i = 0; i < 5; ++i)
        vec.push_back(i * 10); // 0, 10, 20, 30, 40

    printContainer(vec, "Vector");
    testEasyFind(vec, 20, "Vector");
    testEasyFind(vec, 99, "Vector");

    // LIST TEST
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);

    printContainer(lst, "List");
    testEasyFind(lst, 3, "List");
    testEasyFind(lst, 42, "List");

    // DEQUE TEST
    std::deque<int> dq;
    dq.push_back(100);
    dq.push_back(200);
    dq.push_back(300);

    printContainer(dq, "Deque");
    testEasyFind(dq, 200, "Deque");
    testEasyFind(dq, -1, "Deque");

    std::cout << "\n" << CYAN << "===== END OF TESTS =====" << RESET << "\n" << std::endl;
    return 0;
}
