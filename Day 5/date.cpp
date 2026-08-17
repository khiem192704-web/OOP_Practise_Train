#include<iostream>
#include<stdbool.h>
#include"date.h"
using namespace std;
void date::setNgay(int ngay){
    this->ngay = ngay;
}

void date::setThang(int thang){
    this->thang = thang;
}

void date::setNam(int nam){
    this->nam = nam;
}
int date::getNgay(){return ngay;}
int date::getThang(){return thang;}
int date::getNam(){return nam;}

bool date::isLeapYear(int nam){
    if(nam % 400 == 0 || (nam % 100 == 0 && nam % 4 == 0)) return true;
    else return false;
}

int date::monthDays(){
    switch(thang){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:{
            if(isLeapYear(nam)) return 29;
            else return 28;
        }
        default: return 0;
    }
}

void date::nextDay(){
    if(ngay < monthDays()){
        ngay++;
    }
    else{
        ngay = 1;
        if(thang < 12){
            thang ++;
        }
        else{
            thang = 1;
            nam ++;
        }
    }
}