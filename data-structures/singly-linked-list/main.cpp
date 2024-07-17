#include <iostream>
#include "forward-list.h"

int main() {
    // Create a LinkedList object
    LinkedList list;

    // Test push_front
    std::cout << "Testing push_front:\n";
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    list.print_list();  // Expected output: 30->20->10->None

    // Test pop_front
    std::cout << "Testing pop_front:\n";
    list.pop_front();
    list.print_list();  // Expected output: 20->10->None

    // Test insert_after
    std::cout << "Testing insert_after:\n";
    Node* secondNode = list.get_head()->next;
    list.insert_after(secondNode, 15);
    list.print_list();  // Expected output: 20->10->15->None

    // Test erase_after
    std::cout << "Testing erase_after:\n";
    list.erase_after(list.get_head());
    list.print_list();  // Expected output: 20->15->None

    // Test front
    std::cout << "Testing front:\n";
    std::cout << "Front element: " << list.front() << std::endl;  // Expected output: 20

    // Test is_empty
    std::cout << "Testing is_empty:\n";
    std::cout << "Is list empty? " << (list.is_empty() ? "Yes" : "No") << std::endl;  // Expected output: No

    // Test reverse
    std::cout << "Testing reverse:\n";
    list.reverse();
    list.print_list();  // Expected output: 15->20->None

    // Test merge
    std::cout << "Testing merge:\n";
    LinkedList other_list;
    other_list.push_front(50);
    other_list.push_front(40);
    other_list.push_front(30);
    list.merge(other_list);
    list.print_list();  // Expected output: 15->20->30->40->50->None

    // Test sort
    std::cout << "Testing sort:\n";
    list.sort();
    list.print_list();  // Expected output: 15->20->30->40->50->None

    // Test unique
    std::cout << "Testing unique:\n";
    list.push_front(15);  // Add duplicate element to test unique
    list.unique();
    list.print_list();  // Expected output: 15->20->30->40->50->None

    // Test clear
    std::cout << "Testing clear:\n";
    list.clear();
    list.print_list();  // Expected output: (empty list)
}