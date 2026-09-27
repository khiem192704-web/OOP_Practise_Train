#include <iostream>
#include "Point.h"
using namespace std;

void Point::TT(const int& x)
{
    this->xVal += x;
    this->yVal += x;
}

void Point::Show()
{
    cout << this->xVal << ", " << this->yVal << endl;
}

Point::Point()
{
    this->xVal = 0; this->yVal = 0;
}

Point::Point(const Point& p)
{
    this->xVal = p.xVal;
    this->yVal = p.yVal;
}

Point::Point(const int& xVal, const int& y)
{
    this->xVal = xVal; this->yVal = y;
}

Point::~Point()
{
    cout << "Huy Point: " << this->xVal << ", " << this->yVal << endl;
}

//get
int Point::Get_xVal() const
{
    return this->xVal;
}

int Point::Get_yVal() const
{
    return this->yVal;
}

//set
void Point::Set_xVal(const int& x)
{
    this->xVal = x;
}

void Point::Set_yVal(const int& y)
{
    this->yVal = y;
}
int Point::n = 0;
void Point::TT(const int& x)
{
    this->xVal += x;
    this->yVal += x;
}
void Point::Show()
{
    cout << this->xVal << ", " << this->yVal << endl;
    cout << this->z << endl;
}
Point::Point()
    : xVal(1), yVal(1)//, z(2)
{
    //cout << this->xVal << ", " << this->yVal << endl;
    //this->xVal = 0; this->yVal = 0;
    //Point::n++;
}
void Display(Point& p)
{
    p.xVal = 2; p.yVal = 3;
    //p.Set_xVal(2);p.Set_yVal(3);
}
