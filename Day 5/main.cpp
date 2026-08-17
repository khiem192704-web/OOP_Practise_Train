#include<iostream>
#include"complex.h"
#include"date.h"
using namespace std;
int main(){
    complex c1(3,4);
    complex c2(2,9); 
    complex tong = c1.addition(c2);
    tong.printComplex();
}