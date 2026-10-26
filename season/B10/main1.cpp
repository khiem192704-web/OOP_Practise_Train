#include <iostream>
#include <exception>
#include "MyExp.h"
using namespace std;
int Chia(int a, int b)
{
    int c;
    try
    {
        if(b == 0)
            //throw Exp("Ngu lam");
            throw invalid_argument("Van ngu lam");
        else
            c = a / b;
    }
    catch(MyExp& e)
    {
        cout << "Chia: " << e;
        throw;
    }
    catch(Exp& e)
    {
        cout << "Chia: " << e;
        throw;
    }
    catch(invalid_argument& e)
    {
        cout << e.what();
        throw;
    }
    catch(exception& e)
    {
        cout << e.what();
        throw;
    }
    return c;
}
void A(int a, int b)
{
    try
    {
        cout << Chia(a, b);
    }
    catch(MyExp& e)
    {
        cout << "A: " << e;
        throw;
    }
    catch(Exp& e)
    {
        cout << "A: " << e;
        throw;
    }
    catch(invalid_argument& e)
    {
        cout << e.what();
        throw;
    }
    catch(exception& e)
    {
        cout << e.what();
        throw;
    }
}
int main()
{
    int x = 3, y = 0;
    try
    {
        A(x, y);
    }
    catch(MyExp& e)
    {
        cout << "main: " << e;
    }
    catch(Exp& e)
    {
        cout << "main: " << e;
    }
    catch(invalid_argument& e)
    {
        cout << e.what();
    }
    catch(exception& e)
    {
        cout << e.what();
    }
}
