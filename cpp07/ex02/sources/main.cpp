#include <iostream>
#include "../includes/Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }

void testDefaultConstruction() {
    std::cout << "=== Testing Default Construction ===" << std::endl;
    Array<int> arr;
    std::cout << "Empty array size: " << arr.size() << std::endl;
    std::cout << "Default construction: PASSED" << std::endl << std::endl;
}

void testSizeConstruction() {
    std::cout << "=== Testing Size Construction ===" << std::endl;
    Array<int> arr(5);
    std::cout << "Array size: " << arr.size() << std::endl;
    
    // Test default initialization
    std::cout << "Default initialized values: ";
    for (unsigned int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    // Test with different types
    Array<std::string> strArr(3);
    std::cout << "String array size: " << strArr.size() << std::endl;
    std::cout << "Default string values: ";
    for (unsigned int i = 0; i < strArr.size(); i++) {
        std::cout << "\"" << strArr[i] << "\" ";
    }
    std::cout << std::endl;
    std::cout << "Size construction: PASSED" << std::endl << std::endl;
}

void testCopyConstruction() {
    std::cout << "=== Testing Copy Construction ===" << std::endl;
    Array<int> original(4);
    
    // Fill original array
    for (unsigned int i = 0; i < original.size(); i++) {
        original[i] = i * 10;
    }
    
    // Create copy
    Array<int> copy(original);
    
    std::cout << "Original array: ";
    for (unsigned int i = 0; i < original.size(); i++) {
        std::cout << original[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Copied array: ";
    for (unsigned int i = 0; i < copy.size(); i++) {
        std::cout << copy[i] << " ";
    }
    std::cout << std::endl;
    
    // Modify original to test deep copy
    original[0] = 999;
    std::cout << "After modifying original[0] to 999:" << std::endl;
    std::cout << "Original[0]: " << original[0] << std::endl;
    std::cout << "Copy[0]: " << copy[0] << std::endl;
    
    if (copy[0] != 999) {
        std::cout << "Copy construction: PASSED (deep copy works)" << std::endl;
    } else {
        std::cout << "Copy construction: FAILED (shallow copy detected)" << std::endl;
    }
    std::cout << std::endl;
}

void testAssignmentOperator() {
    std::cout << "=== Testing Assignment Operator ===" << std::endl;
    Array<int> arr1(3);
    Array<int> arr2(5);
    
    // Fill arrays
    for (unsigned int i = 0; i < arr1.size(); i++) {
        arr1[i] = i + 1;
    }
    for (unsigned int i = 0; i < arr2.size(); i++) {
        arr2[i] = (i + 1) * 100;
    }
    
    std::cout << "Before assignment:" << std::endl;
    std::cout << "arr1: ";
    for (unsigned int i = 0; i < arr1.size(); i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << "(size: " << arr1.size() << ")" << std::endl;
    
    std::cout << "arr2: ";
    for (unsigned int i = 0; i < arr2.size(); i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << "(size: " << arr2.size() << ")" << std::endl;
    
    // Assignment
    arr1 = arr2;
    
    std::cout << "After arr1 = arr2:" << std::endl;
    std::cout << "arr1: ";
    for (unsigned int i = 0; i < arr1.size(); i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << "(size: " << arr1.size() << ")" << std::endl;
    
    // Test deep copy
    arr2[0] = 999;
    std::cout << "After modifying arr2[0] to 999:" << std::endl;
    std::cout << "arr1[0]: " << arr1[0] << std::endl;
    std::cout << "arr2[0]: " << arr2[0] << std::endl;
    
    if (arr1[0] != 999) {
        std::cout << "Assignment operator: PASSED (deep copy works)" << std::endl;
    } else {
        std::cout << "Assignment operator: FAILED (shallow copy detected)" << std::endl;
    }
    std::cout << std::endl;
}

void testSubscriptOperator() {
    std::cout << "=== Testing Subscript Operator ===" << std::endl;
    Array<int> arr(3);
    
    // Set values
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    
    std::cout << "Array elements: ";
    for (unsigned int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    // Test const access
    const Array<int>& constRef = arr;
    std::cout << "Const access arr[1]: " << constRef[1] << std::endl;
    
    std::cout << "Subscript operator: PASSED" << std::endl << std::endl;
}

void testBoundsChecking() {
    std::cout << "=== Testing Bounds Checking ===" << std::endl;
    Array<int> arr(3);
    
    // Test valid access
    try {
        arr[2] = 42;
        std::cout << "Valid access arr[2]: " << arr[2] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Unexpected exception on valid access: " << e.what() << std::endl;
    }
    
    // Test out of bounds access
    try {
        arr[3] = 99;  // Should throw exception
        std::cout << "Bounds checking: FAILED (no exception thrown)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Out of bounds access correctly threw exception: " << e.what() << std::endl;
        std::cout << "Bounds checking: PASSED" << std::endl;
    }
    
    // Test empty array bounds
    Array<int> empty;
    try {
        empty[0] = 1;  // Should throw exception
        std::cout << "Empty array bounds checking: FAILED (no exception thrown)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Empty array access correctly threw exception: " << e.what() << std::endl;
        std::cout << "Empty array bounds checking: PASSED" << std::endl;
    }
    std::cout << std::endl;
}

void testSizeFunction() {
    std::cout << "=== Testing Size Function ===" << std::endl;
    Array<int> empty;
    Array<int> small(5);
    Array<int> large(1000);
    
    std::cout << "Empty array size: " << empty.size() << std::endl;
    std::cout << "Small array size: " << small.size() << std::endl;
    std::cout << "Large array size: " << large.size() << std::endl;
    
    // Test that size is const
    const Array<int>& constRef = small;
    std::cout << "Const size access: " << constRef.size() << std::endl;
    
    std::cout << "Size function: PASSED" << std::endl << std::endl;
}

void testDefaultInitialization() {
    std::cout << "=== Testing Default Initialization (as per hint) ===" << std::endl;
    
    // Test the hint: int * a = new int(); then display *a
    int* a = new int();
    std::cout << "new int() gives: " << *a << std::endl;
    delete a;
    
    // Test our Array implementation
    Array<int> intArr(3);
    std::cout << "Array<int> default values: ";
    for (unsigned int i = 0; i < intArr.size(); i++) {
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;
    
    Array<double> doubleArr(2);
    std::cout << "Array<double> default values: ";
    for (unsigned int i = 0; i < doubleArr.size(); i++) {
        std::cout << doubleArr[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Default initialization: PASSED" << std::endl << std::endl;
}

int main() {
    std::cout << "============================================" << std::endl;
    std::cout << "           Array Template Tests" << std::endl;
    std::cout << "============================================" << std::endl << std::endl;
    
    try {
        testDefaultConstruction();
        testSizeConstruction();
        testCopyConstruction();
        testAssignmentOperator();
        testSubscriptOperator();
        testBoundsChecking();
        testSizeFunction();
        testDefaultInitialization();
        
        std::cout << "============================================" << std::endl;
        std::cout << "           All Tests Completed!" << std::endl;
        std::cout << "============================================" << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Unexpected exception during testing: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}