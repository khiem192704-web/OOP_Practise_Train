#include <iostream>
#include <string>
using namespace std;
class Exp{
    protected:
        string msg;
    public:
        Exp(string = "");
        virtual ~Exp();
        friend ostream& operator << (ostream&, const Exp&);
};
