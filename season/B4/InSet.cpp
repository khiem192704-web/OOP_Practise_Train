#include <iostream>
#include "IntSet.h"
using namespace std;
IntSet::IntSet(const int& n) : n(n)
{
    this->p = new int[this->n];
    for (int i = 0; i < this->n; i++)
    {
        cout << "p[" << i << "] = ";
        cin >> *(this->p + i);
    }
}
IntSet::~IntSet()
{
    delete[] this->p;
}
void IntSet::Show()
{
    for (int i = 0; i < this->n; i++)
    {
        cout << *(this->p + i) << " ";
    }
    cout << endl;
}
void IntSet::SetToReal(RealSet& r)
{
    r.m = this->n;
    delete[] r.q;
    r.q = new double[r.m];
    for (int i = 0; i < this->n; i++)
    {
        *(r.q + i) = *(this->p + i);
    }
}