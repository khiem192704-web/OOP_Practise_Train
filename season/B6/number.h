class number{
    private:
        double data;
    public:
        number(const double& = 0.0);
        ~number();
        operator int();
        operator double();
};
