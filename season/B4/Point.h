class Point
{
    //quyền truy cập: public, private, protected
// public:
//     static int n;
//     const static int m = 3;
private:
    int xVal;
    int yVal;
    // const int z = 0;
    // int& t = xVal;
public:
    //Constructor
    Point();
    Point(const Point&);
    Point(const int&, const int&);
    //Destructor
    ~Point();
    void TT(const int&);
    void Show();
    //get
    int Get_xVal() const;
    int Get_yVal() const;
    //set
    void Set_xVal(const int&);
    void Set_yVal(const int&);
    friend void Display(Point&);
};
