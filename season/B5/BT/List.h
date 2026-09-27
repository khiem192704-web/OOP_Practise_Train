#include"Sinhvien.h"
class List{
    private:
        Sinhvien* sv;
        int n;
        int capacity;
    public:
        List();
        List(const List&);
        ~List();
        void show() const;
        void add(const Sinhvien&, int);
        void addFirt(const Sinhvien&);
        void addLast(const Sinhvien&);
        void update(const Sinhvien&);
        void remove(const Sinhvien&);
        void search(std::string) const;
        bool tangDan(float a, float b);
        bool giamDan(float a, float b);
        void sort(bool (*cmp)(float, float));
};