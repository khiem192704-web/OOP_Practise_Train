#ifndef COMPLEx_H
#define COMPLEX_H
class complex{
    private:
        double realPart;
        double imaginaryPart;
        void setComplexNumber(double r, double i);
    public:
        complex();
        complex(double real, double imaginary);
        void printComplex();
        complex addition(const complex &expression);
        complex subtraction(const complex &expression);
};
#endif
