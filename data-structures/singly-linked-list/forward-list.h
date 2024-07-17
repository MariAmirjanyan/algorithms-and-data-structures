#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H
#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int data);
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();    
    LinkedList(int data);                                  
    ~LinkedList();                  

    void push_front(int data);      
    void pop_front();               
    void insert_after(Node* prev_node, int data);
    void erase_after(Node* prev_node); 
    void clear();                  
    bool is_empty() const;          
    int front() const;              
    void reverse();                 
    void merge(LinkedList& other_list); 
    void print_list() const;        
    void sort();                    
    void unique();     
    Node* get_head() const; 
};

#endif // FORWARD_LIST_H