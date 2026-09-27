#ifndef STACK_H
#define STACK_H
typedef struct Node{
            int item;
            struct Node*next;
            Node(const int &Item) : item(Item), next(nullptr){}

}Node;
class stack{
    private:
        Node *top;
        int size;
    public:
        stack();
        stack(const stack &other);
        void push(const int& item);
        int pop();
        bool isEmpty() const ;
        int numOfElement() const ;
        void print() ;
    };
#endif
