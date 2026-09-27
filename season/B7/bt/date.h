#include<iostream>
using namespace std;
class Date
{
private:
    int day,month,year;
public:
    Date(int d = 0, int m = 0, int y = 0);
    Date(const Date&);
    ~Date();

    Date& operator++();//++d
    const Date operator++(int );//d++
    Date& operator--();//--d
    const Date operator--(int);//d++
    Date& operator+=(int);
    Date& operator-=(int);
    friend istream& operator>>(istream&, Date&);
    friend ostream& operator<<(ostream&, const Date&);
};
