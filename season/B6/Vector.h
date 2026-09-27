#include<iostream>
using namespace std;
class Vector{
    private:
        int n;
        int *data;
    public:
        Vector(const int& = 0);
        Vector(const Vector&);
        ~Vector();
        friend ostream& operator<<(ostream&, const Vector&);
        friend istream& operator>>(istream&, Vector&);
        int& operator[](const int&);
        const Vector& operator=(const Vector&);
};
