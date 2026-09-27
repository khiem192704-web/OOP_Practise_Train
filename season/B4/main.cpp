#include <iostream>
#include "Point.h"
using namespace std;

int main()
{
    cout << Point::n << endl;
    cout << Point::m << endl;
    Point p1;
    cout << Point::n << ", " << p1.n << endl;
    cout << Point::m << ", " << p1.m << endl;
    Point *p = new Point;
    cout << Point::n << ", " << p1.n << ", " << p->n << endl;
    cout << Point::m << ", " << p1.m << ", " << p->m << endl;
    delete p;
    cout << Point::n << ", " << p1.n << endl;
    cout << Point::m << ", " << p1.m << endl;
}
