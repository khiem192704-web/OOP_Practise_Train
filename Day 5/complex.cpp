#include<iostream>
#include"complex.h"
using namespace std;
void complex::setComplexNumber(double real, double imaginary){
    imaginaryPart = imaginary;
    realPart = real;
}
complex::complex(double real, double imaginary){
    setComplexNumber(real, imaginary);
}
void complex::printComplex(){
    cout<< realPart <<(imaginaryPart >= 0 ?"+":" ")<<imaginaryPart <<"i"<<endl;
}
void complex::addition(const complex &expression ){
    realPart += expression.realPart;
    imaginaryPart += expression.imaginaryPart;
}
complex complex::subtraction(const complex &expression){
    realPart -= expression.realPart;
    imaginaryPart -= expression.imaginaryPart;
}
