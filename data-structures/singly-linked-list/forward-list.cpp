#include "forward-list.h"

Node::Node(int data)
    :data(data),
    next(nullptr)
{}

LinkedList::LinkedList() 
    :head(nullptr)
{}

LinkedList::LinkedList(int data)
    :head(new Node(data))
{}

LinkedList::~LinkedList(){
    clear(); 
}

void LinkedList::push_front(int data){
    Node* tmp = new Node(data);
    tmp->next = head;
    head = tmp;
}

void LinkedList::pop_front(){
    if(is_empty()){
        throw std::out_of_range("List is empty");
    }
    Node* tmp = head;
    head = head->next;
    delete tmp;
}

void LinkedList::insert_after(Node* prev_node, int data){
    if(prev_node != nullptr){
        Node* new_node = new Node(data);
        new_node->next = prev_node->next;
        prev_node->next = new_node;
    }
}

void LinkedList::erase_after(Node* prev_node){
    if (prev_node == nullptr || prev_node->next == nullptr) {
        std::cerr << "Error: Previous node or its next node cannot be null.\n";
        return;
    }
    Node* tmp = prev_node->next;
    prev_node->next = tmp->next;
    delete tmp;
}

void LinkedList::clear(){
    while(head != nullptr){
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

bool LinkedList::is_empty() const{
    return head == nullptr;
}

int LinkedList::front() const{
    if(head != nullptr){
        return head->data;
    }
    std::cerr << "Error: List is empty.\n";
    return -1;
}

void LinkedList::reverse(){
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while(current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void LinkedList::merge(LinkedList& other_list){
    if(head == nullptr){
        head = other_list.head;
    }
    if(other_list.head == nullptr){
        return;
    }
    Node* current = head;
    while(current->next != nullptr){
        current = current->next;
    }
    current->next = other_list.head;
    other_list.head = nullptr;
}

void LinkedList::sort(){
    Node* current = head;
    Node* ind = nullptr;
    int tmp;

    if(head == nullptr){
        return;
    } 
    else{
        while(current != nullptr){
            ind = current->next;
            while(ind != nullptr){
                if(current->data > ind->data){
                    tmp = current->data;
                    current->data = ind->data;
                    ind->data = tmp;
                }
                ind = ind->next;
            }
            current = current->next;
        }
    }
}

void LinkedList::unique(){
    Node* current = head;
    while(current != nullptr && current->next != nullptr){
        if(current->data == current->next->data){
            Node* tmp = current->next;
            current->next = current->next->next;
            delete tmp;
        } 
        else{
            current = current->next;
        }
    }
}

Node* LinkedList::get_head() const {
    return head;
}

void LinkedList::print_list() const{
    Node* current = head;
    while(current != nullptr){
        std::cout << current->data << "->";
        current = current->next;
    }
    std::cout <<  "None" << std::endl;
}