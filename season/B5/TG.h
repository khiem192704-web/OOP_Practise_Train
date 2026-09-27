#include<B4/Point.h>
class TG{
    private:
        Point A,B,C;
    public:
        TG(const Point&, const Point&, const Point&);
        TG(const int&, const int&, const int&, const int&, const int&, const int&);
        ~TG();
        void show();
}