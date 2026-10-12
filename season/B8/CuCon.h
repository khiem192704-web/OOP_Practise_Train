#include"P1.h"
#include"P2.h"
class CuCon : public P1, public P2{
    protected:
        int z;
    public:
        CuCon(const int&, const int&, const int&);
        ~CuCon();
        void CC();
        void PP();
};
