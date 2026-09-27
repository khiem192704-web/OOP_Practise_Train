class RealSet;
class IntSet{
    private:
        int *p;
        int n;
    public:
        IntSet(const int&);
        ~IntSet();
        void Show();
        void SetToReal(RealSet&);
};