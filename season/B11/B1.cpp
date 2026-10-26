#include<iostream>
using namespace std;

template<typename T>
void HV(T& a,T& b){
    T temp = a;
    a = b;
    b = temp;
}

void HV(double a, double b){
    double temp = a;
    a = b;
    b = temp;
}

template<typename T, typename U>
void A(T a, U b){
    cout<<a<<","<<b<<endl;
}

int main(){
    int x = 1, y=2;
    double x1 = 1.1,  y1 = 2.2;
    HV<int>(x,y);
    HV(x1,y1);
    cout<<x<<","<<y<<endl;
    cout<<x1<<","<<y1<<endl;
    A<int, double>(1,1.1);
    A<int, int>(1,2);
}