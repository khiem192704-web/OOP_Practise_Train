#include <iostream>
using namespace std;

class Point
{
protected:
    int xVal;
    int yVal;

public:
    Point(const Point&);
    Point(const int& = 2, const int& = 2);
    virtual ~Point();
    friend ostream& operator<<(ostream&, const Point&);
    friend istream& operator>>(istream&, Point&);
};

Point::Point(const Point& p) : xVal(p.xVal), yVal(p.yVal)
{
}

Point::Point(const int& x, const int& y) : xVal(x), yVal(y)
{
}

Point::~Point()
{
}

ostream& operator<<(ostream& o, const Point& p)
{
    o << p.xVal << ", " << p.yVal << endl;
    return o;
}

istream& operator>>(istream& in, Point& p)
{
    cout << "xVal = ";
    in >> p.xVal;
    cout << "yVal = ";
    in >> p.yVal;
    return in;
}