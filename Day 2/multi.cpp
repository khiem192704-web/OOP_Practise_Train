#include<bits/stdc++.h>
using namespace std;
class A{
    public:
        A(){
            cout << "Constructor cua lop A\n";
        }
        ~A(){
            cout << "Destructor cua lop A";
        }
        void xinchao(){
            cout << "Xin chao A\n";
        }
};

class B : public A{
    public:
        B(){
            cout << "Constructor cua lop B\n";
        }
        ~B(){
            cout << "Destructor cua lop B";
        }
        void xinchao(){
            cout << "Xin chao B\n";
        }
};

class C : public B, public A{
    public:
        C(){
            cout << "Constructor cua lop C\n";
        }
        ~C(){
            cout << "Destructor cua lop C";
        }
        void xinchao(){
            cout << "Xin chao C\n";
        }
};

int main(){
    C obj;
    obj.xinchao();
}