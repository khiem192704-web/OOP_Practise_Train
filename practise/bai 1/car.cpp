#include"car.h"

car::car(){
    this->engine_type = "";
    this->seats = 0;
}

car::car(const string& manufacturer, const string& name, int year, float max_speed, int seats, const string& engine_type)
    : transport(manufacturer, name,year, max_speed ){
        this->seats = seats;
        this->engine_type = engine_type;
}

car::~car(){}

void car::setSeats(int seats){ this->seats = seats; }
void car::setEngine_type(const string& engine_type){ this->engine_type = engine_type; }

int car::getSeats() const{ return seats; }
string car::getEngine_type() const{ return engine_type; }

float car::speed_base() const{ return GetMaxSpeed()/4; }

bool car::operator>(const car& other){ }

ostream& operator<<(ostream& out, const car& Car){
    out<<"So cho ngoi cua xe:"<<Car.seats<<endl;
    out<<"Hang xe:"<<Car.engine_type<<endl;
    return out;
}
istream& operator>>(istream& in, car& Car){
    cout<<"Nhap so cho ngoi cua xe:";
    getline(in, Car.engine_type);
    cout<<"Nhap hang xe:";
    in>>Car.seats;
    in.ignore();
    return in;
}
