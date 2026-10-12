#include<iostream>
using namespace std;
class Point{
    protected:
        int xVal;
        int yVal;
    public:
        Point(const Point&);
        Point(const int& = 0, const int& = 0);
        ~Point();
        virtual void show();
        //overload
        virtual void A();
        virtual void A(int);
};
