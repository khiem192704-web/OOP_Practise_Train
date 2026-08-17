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
        void addition(const complex &expression);
        void subtraction(const complex &expression);
};
#endif