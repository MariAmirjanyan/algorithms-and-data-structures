#include <iostream>
#include "dynamic-array.h"

int main() {
    // Test default constructor
    DynamicArray<int> array1;
    std::cout << "Array1 (default constructor): " << array1 << std::endl;

    // Test parameterized constructor
    DynamicArray<int> array2(5);
    for (int i = 1; i <= 5; ++i) {
        array2.pushBack(i);
    }
    std::cout << "Array2 (parameterized constructor): " << array2 << std::endl;

    // Test initializer list constructor
    DynamicArray<int> array3 = {10, 20, 30};
    std::cout << "Array3 (initializer list constructor): " << array3 << std::endl;

    // Test copy constructor
    DynamicArray<int> array4 = array2;
    std::cout << "Array4 (copy constructor): " << array4 << std::endl;

    // Test move constructor
    DynamicArray<int> array5 = std::move(array3);
    std::cout << "Array5 (move constructor): " << array5 << std::endl;

    // Test copy assignment operator
    DynamicArray<int> array6;
    array6 = array4;
    std::cout << "Array6 (copy assignment operator): " << array6 << std::endl;

    // Test move assignment operator
    DynamicArray<int> array7;
    array7 = std::move(array5);
    std::cout << "Array7 (move assignment operator): " << array7 << std::endl;

    // Test subscript operator
    std::cout << "Element at index 2 in Array6: " << array6[2] << std::endl;

    // Test size-related functions
    std::cout << "Size of Array6: " << array6.getSize() << std::endl;
    std::cout << "Capacity of Array6: " << array6.getCapacity() << std::endl;
    std::cout << "Array6 is empty: " << array6.isEmpty() << std::endl;

    // Test modification functions
    array6.pushBack(6);
    std::cout << "Array6 after pushBack(6): " << array6 << std::endl;

    array6.popBack();
    std::cout << "Array6 after popBack(): " << array6 << std::endl;

    array6.insert(2, 99);
    std::cout << "Array6 after insert(2, 99): " << array6 << std::endl;

    array6.remove(1);
    std::cout << "Array6 after remove(1): " << array6 << std::endl;

    array6.clear();
    std::cout << "Array6 after clear(): " << array6 << std::endl;

    // Test operator<<
    std::cout << "Array4 using operator<<: " << array4 << std::endl;

    return 0;
}
