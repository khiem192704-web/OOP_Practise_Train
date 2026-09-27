//Định nghĩa lớp
#include <iostream>
#include "Point.h"
using namespace std;

void Point::TT(const int& x)
{
    xVal += x;
    yVal += x;
}

void Point::Show()
{
    cout << xVal << ", " << yVal << endl;
}

Point::Point()
{
    xVal = 0; yVal = 0;
}

Point::Point(const Point& p)
{
    xVal = p.xVal;
    yVal = p.yVal;
}

Point::Point(const int& x, const int& y)
{
    xVal = x; yVal = y;
}

Point::~Point()
{
    cout << "Huy Point: " << xVal << ", " << yVal << endl;
}
