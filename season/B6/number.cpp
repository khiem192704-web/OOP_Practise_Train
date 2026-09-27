#include"number.h"
number::number(const double& d) : data(d){}

number::~number(){}

number::operator int(){
    return int(this->data);
}

number::operator double(){
    return this->data;
}
