#include "../includes/iter.hpp"

// int main() {
//     int intArray[] = {1, 2, 3, 4, 5};
//     size_t intLen = sizeof(intArray) / sizeof(intArray[0]);

//     // std::cout << "Original int array: ";
//     // iter(intArray, intLen, printElement<int>);
//     // std::cout << "\n";

//     // std::cout << "Incrementing int array...\n";
//     // iter(intArray, intLen, increment<int>);

//     // std::cout << "After increment: ";
//     // iter(intArray, intLen, printElement<int>);
//     // std::cout << "\n";

//     // // Test with std::string array
//     // std::string strArray[] = {"hello", "world", "template"};
//     // size_t strLen = sizeof(strArray) / sizeof(strArray[0]);

//     // std::cout << "\nOriginal string array: ";
//     // iter(strArray, strLen, printElement<std::string>);
//     // std::cout << "\n";

// // Some functions might take const reference (read-only)
//     void display(const int& value) {
//     std::cout << value << std::endl;
//     }

// // Others might take non-const reference (can modify)
//     void increment(int& value) {
//     value++;
//     }
//     std::cout << "Original int array: ";
//     iter(intArray, intLen, display);
//     std::cout << 

//     return 0;
// }

#include <iostream>
#include <string>

// Assuming your iter function template is declared here
// template<typename T, typename F>
// void iter(T* array, size_t length, F func);

// Test functions that take const reference
void print_int(const int& value) {
    std::cout << value << " ";
}

void print_string(const std::string& value) {
    std::cout << "\"" << value << "\" ";
}

template<typename T>
void print_generic(const T& value) {
    std::cout << "[" << value << "] ";
}

// Test functions that take non-const reference (modify elements)
void increment_int(int& value) {
    value++;
}

void uppercase_first_char(std::string& str) {
    if (!str.empty()) {
        str[0] = std::toupper(str[0]);
    }
}

void double_value(int& value) {
    value *= 2;
}

// Test function that works with both const and non-const
void analyze_int(const int& value) {
    std::cout << "Value: " << value << " (even: " << (value % 2 == 0 ? "yes" : "no") << ") ";
}

int main() {
    std::cout << "=== Testing iter function template ===\n\n";

    // Test 1: Non-const int array with const function
    std::cout << "Test 1: Non-const int array with print function\n";
    int int_array[] = {1, 2, 3, 4, 5};
    size_t int_size = sizeof(int_array) / sizeof(int_array[0]);
    
    std::cout << "Original array: ";
    iter(int_array, int_size, print_int);
    std::cout << "\n\n";

    // Test 2: Non-const int array with modifying function
    std::cout << "Test 2: Modifying int array (increment each element)\n";
    std::cout << "Before increment: ";
    iter(int_array, int_size, print_int);
    std::cout << "\n";
    
    iter(int_array, int_size, increment_int);
    
    std::cout << "After increment: ";
    iter(int_array, int_size, print_int);
    std::cout << "\n\n";

    // Test 3: Const int array (should only work with const functions)
    std::cout << "Test 3: Const int array with const function\n";
    const int const_int_array[] = {10, 20, 25, 30, 40, 50};
    size_t const_int_size = sizeof(const_int_array) / sizeof(const_int_array[0]);
    
    std::cout << "Const array: ";
    iter(const_int_array, const_int_size, print_int);
    std::cout << "\n";
    
    std::cout << "Analysis: ";
    iter(const_int_array, const_int_size, analyze_int);
    std::cout << "\n\n";

    // Test 4: String array tests
    std::cout << "Test 4: String array tests\n";
    std::string string_array[] = {"hello", "world", "template", "test"};
    size_t string_size = sizeof(string_array) / sizeof(string_array[0]);
    
    std::cout << "Original strings: ";
    iter(string_array, string_size, print_string);
    std::cout << "\n";
    
    iter(string_array, string_size, uppercase_first_char);
    
    std::cout << "After uppercase: ";
    iter(string_array, string_size, print_string);
    std::cout << "\n\n";

    // Test 5: Template function as parameter
    std::cout << "Test 5: Using instantiated template function\n";
    double double_array[] = {1.1, 2.2, 3.3, 4.4};
    size_t double_size = sizeof(double_array) / sizeof(double_array[0]);
    
    std::cout << "Double array with generic print: ";
    iter(double_array, double_size, print_generic<double>);
    std::cout << "\n";
    
    std::cout << "Int array with generic print: ";
    iter(int_array, int_size, print_generic<int>);
    std::cout << "\n\n";

    // Test 6: Multiple modifications
    std::cout << "Test 6: Multiple modifications on same array\n";
    int test_array[] = {1, 2, 3, 4, 5};
    size_t test_size = sizeof(test_array) / sizeof(test_array[0]);
    
    std::cout << "Original: ";
    iter(test_array, test_size, print_int);
    std::cout << "\n";
    
    iter(test_array, test_size, double_value);
    std::cout << "After doubling: ";
    iter(test_array, test_size, print_int);
    std::cout << "\n";
    
    iter(test_array, test_size, increment_int);
    std::cout << "After increment: ";
    iter(test_array, test_size, print_int);
    std::cout << "\n\n";

    // Test 7: Different array types
    std::cout << "Test 7: Different array types\n";
    char char_array[] = {'a', 'b', 'c', 'd', 'e'};
    size_t char_size = sizeof(char_array) / sizeof(char_array[0]);
    
    std::cout << "Char array: ";
    iter(char_array, char_size, print_generic<char>);
    std::cout << "\n";

    // Test with const char array
    const char const_char_array[] = {'x', 'y', 'z'};
    size_t const_char_size = sizeof(const_char_array) / sizeof(const_char_array[0]);
    
    std::cout << "Const char array: ";
    iter(const_char_array, const_char_size, print_generic<char>);
    std::cout << "\n\n";

    std::cout << "=== All tests completed ===\n";

    return 0;
}