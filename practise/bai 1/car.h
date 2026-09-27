#pragma once
#include"transport.h"

class car : public transport{
    private:
        int seats;
        string engine_type;
    public:
        car(){};
        car(const string&, const string&, int, float, int, const string&);
        ~car(){};

        void setSeats(int);
        void setEngine_type(const string&);

        int getSeats() const;
        string getEngine_type() const;
        float speed_base() const;
        bool operator > (const car&);
        friend ostream& operator<<(ostream&, const car&);
        friend istream& operator>>(istream&, car&);
};
