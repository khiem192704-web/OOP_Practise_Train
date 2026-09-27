//Khai báo lớp
class Point
{
    //quyền truy cập: public, private, protected
public:
    int xVal;
    int yVal;
public:
    //Constructor
    Point();
    Point(const Point&);
    Point(const int&, const int&);
    //Destructor
    ~Point();
    void TT(const int&);
    void Show();
};
