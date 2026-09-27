#include"transport.h"

transport::transport(){
    this->manufacturer = "";
    this->name = "";
    this->max_speed = 0;
    this->year = 0;
}

transport::transport(const string& manufacturer, const string& name, int year, float max_speed ) : manufacturer(manufacturer), name(name), year(year), max_speed(max_speed) {}

void transport::SetName(const string& name){
    this->name = name;
}

void transport::SetManufacturer(const string& manufacturer){
    this->manufacturer = manufacturer;
}

void transport::SetYear(int year){
    this->year = year;
}

void transport::SetMaxSpeed(float max_speed){
    this->max_speed = max_speed;
}

string transport::GetManufacturer() const{
    return this->manufacturer;
}

string transport::GetName() const{
    return this->name;
}

int transport::GetYear() const{
    return this->year;
}

float transport::GetMaxSpeed() const{
    return this->max_speed;
}

istream& operator >> (istream& in,transport& trans){
    cout<<"Nhap ten hang san xuat:";
    getline(in,trans.manufacturer);
    cout<<"Nhap ten phuong tien:";
    getline(in,trans.name);
    cout<<"Nhap nam san xuat:";
    in>>trans.year;
    cout<<"Nhap van toc toi da:";
    in>>trans.max_speed;
    return in;
}

ostream& operator << (ostream& out, const transport& trans) {
    out<<"Hang san xuat:"<<trans.manufacturer<<endl;
    out<<"Ten phuong tien:"<<trans.name<<endl;
    out<<"Nam san xuat:"<<trans.year<<endl;
    out<<"Toc do toi da:"<<trans.max_speed<<endl;
    return out;
}
