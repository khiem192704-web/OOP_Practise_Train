#ifndef DATE_H
#define DATE_H
#include<stdbool.h>
class date{
    private:
        int ngay, thang, nam;
    public:
        date(int ngay = 20, int thang = 2, int nam = 2003);
        void setNgay(int ngay);
        int getNgay();
        void setThang(int thang);
        int getThang();
        void setNam(int nam);
        int getNam();
        bool isLeapYear(int nam);
        int monthDays();
        void nextDay();
};
#endif