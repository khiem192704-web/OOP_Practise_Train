#include <iostream>
#include "Point.h"
using namespace std;
//class template
// Khai báo trước template class
// template<typename T, int U>
// class Vector;

// Khai báo trước toán tử xuất cho template
// template<typename T, int U>
// ostream& operator<<(ostream&, const Vector<T, U>&);
// template<typename T, int U>
// class Vector
// {
// private:
//     T *p;
//     int n;
// public:
//     Vector(const int& = 0);
//     ~Vector();
//     void Show();
//     T& operator[](const int&);
//     friend ostream& operator<< <T, U>(ostream&, const Vector<T, U>&);
// };

// template<typename T, int U>
// ostream& operator<<(ostream& o, const Vector<T, U>& v)
// {
//     for (int i = 0; i < v.n; i++)
//     {
//         o << *(v.p + i);
//     }
//     return o;
// }

// template<typename T, int U>
// T& Vector<T, U>::operator[](const int& index)
// {
//     return *(this->p + index);
// }

// template<typename T, int U>
// Vector<T, U>::Vector(const int& n) : n(U)//n(n)
// {
//     this->p = new T[this->n];
//     for (int i = 0; i < this->n; i++)
//     {
//         cin >> *(this->p + i);//(*this)[i]
//     }
// }

// template<typename T, int U>
// Vector<T, U>::~Vector()
// {
//     delete[] this->p;
// }

// template<typename T, int U>
// void Vector<T, U>::Show()
// {
//     for (int i = 0; i < this->n; i++)
//     {
//         cout << *(this->p + i) << " ";
//     }
// }

// template class Vector<int,2>;
// template class Vector<double,3>;
//template class Vector<Point>;

//class template
template<typename T>
class Vector;
template<typename T>
ostream& operator<<(ostream&, const Vector<T>&);
template<typename T>
class Vector
{
private:
    T *p;
    int n;
public:
    Vector(const int& = 0);
    ~Vector();
    void Show();
    T& operator[](const int&);
    friend ostream& operator<< <T>(ostream&, const Vector<T>&);
};
template<typename T>
ostream& operator<<(ostream& o, const Vector<T>& v)
{
    for (int i = 0; i < v.n; i++)
    {
        cout << *(v.p + i);
    }
    return o;
}
template<typename T>
T& Vector<T>::operator[](const int& index)
{
    return *(this->p + index);
}
template<typename T>
Vector<T>::Vector(const int& n) : n(n)
{
    this->p = new T[this->n];
    for (int i = 0; i < this->n; i++)
    {
        cin >> (*this)[i];
    }
}
template<typename T>
Vector<T>::~Vector()
{
    delete[] this->p;
}
template<typename T>
void Vector<T>::Show()
{
    for (int i = 0; i < this->n; i++)
    {
        cout << (*this)[i] << " ";
    }
}

template class Vector<int>;
template class Vector<double>;
template class Vector<Point>;