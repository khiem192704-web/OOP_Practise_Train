#include"point3D.h"
class Point4D : public Point3D{
    private:
        int tVal;
    public:
        Point4D(const int& = 3, const int& = 3, const int& = 3, const int& = 3);
        ~Point4D();
        void show();
};
