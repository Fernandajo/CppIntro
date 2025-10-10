#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../includes/MutantStack.hpp"

static void basic_demo() {
    std::cout << "=== Basic push/pop + iteration ===\n";
    MutantStack<int> ms;

    ms.push(5);
    ms.push(17);
    std::cout << "top: " << ms.top() << "\n";
    ms.pop();
    std::cout << "size after pop: " << ms.size() << "\n";

    ms.push(3);
    ms.push(5);
    ms.push(737);
    ms.push(0);

    std::cout << "Forward iteration: ";
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "Reverse iteration: ";
    for (MutantStack<int>::reverse_iterator rit = ms.rbegin(); rit != ms.rend(); ++rit)
        std::cout << *rit << " ";
    std::cout << "\n\n";
}

static void const_iter_demo() {
    std::cout << "=== Const iteration (read-only) ===\n";
    MutantStack<int> ms;
    ms.push(10); ms.push(20); ms.push(30);

    const MutantStack<int>& cms = ms;
    int sum = 0;
    for (MutantStack<int>::const_iterator it = cms.begin(); it != cms.end(); ++it)
        sum += *it;

    std::cout << "sum: " << sum << "\n\n";
}

static void random_fill_demo() {
    std::cout << "=== Random fill, iterate, and verify LIFO ===\n";
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    MutantStack<int> ms;
    for (int i = 0; i < 10; ++i)
        ms.push(std::rand() % 100);

    std::cout << "Forward iteration: ";
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "Popping all (LIFO order): ";
    while (!ms.empty()) {
        std::cout << ms.top() << " ";
        ms.pop();
    }
    std::cout << "\n\n";
}

static void copy_assign_demo() {
    std::cout << "=== Copy & assignment semantics ===\n";
    MutantStack<std::string> a;
    a.push("alpha"); a.push("beta"); a.push("gamma");

    MutantStack<std::string> b(a); // copy-ctor
    b.push("delta");

    MutantStack<std::string> c;
    c = b; // copy-assign

    std::cout << "a: ";
    for (MutantStack<std::string>::iterator it = a.begin(); it != a.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "b: ";
    for (MutantStack<std::string>::iterator it = b.begin(); it != b.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "c: ";
    for (MutantStack<std::string>::iterator it = c.begin(); it != c.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n\n";
}

int main() {
    basic_demo();
    const_iter_demo();
    random_fill_demo();
    copy_assign_demo();

    // Bonus: show interoperability with std::stack API
    std::cout << "=== Using as a std::stack ===\n";
    MutantStack<int> ms;
    for (int i = 1; i <= 5; ++i) ms.push(i);

    std::cout << "top: " << ms.top() << "\n";
    ms.pop();
    std::cout << "size: " << ms.size() << "\n";

    std::cout << "Iterate remaining: ";
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    return 0;
}
