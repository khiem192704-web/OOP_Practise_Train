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
complex complex::addition(const complex &expression ){
    realPart += expression.realPart;
    imaginaryPart += expression.imaginaryPart;
    return complex(realPart,imaginaryPart);
}
complex complex::subtraction(const complex &expression){
    realPart -= expression.realPart;
    imaginaryPart -= expression.imaginaryPart;
    return complex(realPart,imaginaryPart);
}
