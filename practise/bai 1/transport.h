#pragma once
#include<iostream>
#include<string.h>
using namespace std;
class transport{
    private:
        string manufacturer;
        string name;
        int year;
        float max_speed;
    public:
        transport(){};
        transport(const string&, const string&, int, float){};
        ~transport();
        void SetManufacturer(const string&);
        void SetName(const string&);
        void SetYear(int);
        void SetMaxSpeed(float);

        string GetManufacturer() const;
        string GetName() const;
        int GetYear() const;
        float GetMaxSpeed() const;

        friend istream& operator>>(istream&,transport& );
        friend ostream& operator<<(ostream&, const transport& );
};
