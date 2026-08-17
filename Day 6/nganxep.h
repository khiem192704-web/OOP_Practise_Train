#ifndef STACK_H
#define STACK_H

class stack{
    private:
        typedef struct Node{
            int item;
            struct Node*next;
        }Node;
        Node *top;
        int size;
    public:
        int push();
        Node *pop();
        bool isEmpty();
        int numOfElement();
        void print();
};

#endif