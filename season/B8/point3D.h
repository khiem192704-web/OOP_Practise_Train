#include"point.h"
class Point3D : public Point{
    protected:
        int zVal;
    public:
        Point3D(const int& = 1, const int& =1, const int& =1);
        ~Point3D();
        void show3D();
        void show() override; // override giúp cho trình biên dịch luôn xác định đa hình
        // A() A(int)
        void A() override;
};
