#include <iostream>
#include "MyExp.h"
using namespace std;
int Chia(int a, int b)
{
    return a/b;
}
int main()
{
    int x, y;
    do
    {
        cout << "x = " ;
        cin >> x;
        cout << "y = ";
        cin >> y;
    try{

        //throw 1;
        //throw 1.3;
        //throw "Ngu 1em"1
        //throw Exp("Ngu Lam");
        //throw MyExp("Ngu Lem", 1);

        cout << Chia(w, y);
        }

        catch(int& e)
        {
        cout << "int: " << e << '\n';
        }

        catch(double& e)
        {
        cout << "double: " << e << "\n";
        }

        catch(MtyExp& e)
        {
        cout << e;
        }

        catch(Exp& e)
        {
        cout << e;
        }

        catch(...)
        {
            cout << "Do bat duoe roi";
        }
    } while (y == 0);
}
