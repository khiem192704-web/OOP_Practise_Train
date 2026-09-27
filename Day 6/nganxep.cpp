#include<iostream>
#include"nganxep.h"

stack::stack() : top(nullptr), size(0){}
stack::stack(const stack& other):top(nullptr), size(other.size){
    if(other.top == nullptr) return;
    top = new Node(other.top->item);
    Node* New = top;
    Node* currentOther = other.top->next;
    while(currentOther != nullptr){
        New->next = new Node(currentOther->item);
        New = New->next;
        currentOther = currentOther->next;
    }
}

void stack::push(const int& item){
    Node* node = new Node(item);
    node->next = top;
    top = node;
    size++;
}

int stack::pop(){
    if(isEmpty()) return -1;
    Node *temp = top;
    int value = temp->item;
    top = top->next;
    delete temp;
    size--;
    return value;
}
bool stack::isEmpty() const {return top == nullptr;}
int stack::numOfElement() const {return size;}
void stack::print(){
    while(top != nullptr||top->next != nullptr){
        std::cout<<top->item<<" ";
        top = top->next;
    }
}
