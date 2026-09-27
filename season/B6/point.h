#include<iostream>
using namespace std;
class point
{
    private:
        int xVal;
        int yVal;
    public:
        //point();
        point(const point&);
        point(const int& = 0, const int& = 0);
        point(const int&);
        ~point();
        void Show();
        friend point operator+(const point&, const point&);
        //p1-p2
        point operator-(const point&);
        friend ostream& operator<<(ostream&, const point&);
        friend istream& operator>>(istream&, point&);
        //prefix
        point& operator++();
        //postfix
        const point& operator++(int);
        //a==b
        bool operator==(const point&) const;
};
