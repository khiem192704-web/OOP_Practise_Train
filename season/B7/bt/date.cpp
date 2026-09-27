#include"date.h"

Date::Date(int d, int m, int y) : day(d), month(m), year(y){}
Date::Date(const Date& date) : day(date.day), month(date.month), year(date.year) { }
Date::~Date() { }
Date& Date::operator++() {
    this->day++;
    if(this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12) {
        if(this->day > 31) {
            this->day = 1;
            this->month++;
            if(this->month > 12) {
                this->month = 1;
                this->year++;
            }
        }
    } else if(this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11) {
        if(this->day > 30) {
            this->day = 1;
            this->month++;
        }
    } else if(this->month == 2) {
        if((this->year % 4 == 0 && this->year % 100 != 0) || this->year % 400 == 0) {
            if(this->day > 29) {
                this->day = 1;
                this->month++;
            }
        } else {
            if(this->day > 28) {
                this->day = 1;
                this->month++;
            }
        }
    }
    return *this;
}

const Date Date::operator++(int) {
    Date temp = *this;
    ++(*this);
    return temp;
}

Date& Date::operator--() {
    this->day--;
    if(this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12) {
        if(this->day < 1) {
            this->day = 31;
            this->month--;
            if(this->month < 1) {
                this->month = 12;
                this->year--;
            }
        }
    } else if(this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11) {
        if(this->day < 1) {
            this->day = 30;
            this->month--;
        }
    } else if(this->month == 2) {
        if((this->year % 4 == 0 && this->year % 100 != 0) || this->year % 400 == 0) {
            if(this->day < 1) {
                this->day = 29;
                this->month--;
            }
        } else {
            if(this->day < 1) {
                this->day = 28;
                this->month--;
            }
        }
    }
    return *this;
}

const Date Date::operator--(int) {
    Date temp = *this;
    --(*this);
    return temp;
}

Date& Date::operator+=(int days) {
    if (days < 0) {
        return *this -= -days;
    }
    this->day += days;
    while (true) {
        if (this->month == 1 || this->month == 3 || this->month == 5 ||
            this->month == 7 || this->month == 8 || this->month == 10) {
            if (this->day > 31) {
                this->day -= 31;
                this->month++;
            } else break;
        } else if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11) {
            if (this->day > 30) {
                this->day -= 30;
                this->month++;
            } else break;
        } else if (this->month == 2) {
            if ((this->year % 4 == 0 && this->year % 100 != 0) || this->year % 400 == 0) {
                if (this->day > 29) {
                    this->day -= 29;
                    this->month++;
                } else break;
            } else {
                if (this->day > 28) {
                    this->day -= 28;
                    this->month++;
                } else break;
            }
        }
        if (this->month > 12) {
            this->month = 1;
            this->year++;
        }
    }
    return *this;
}

Date& Date::operator-=(int days) {
    if (days < 0) {
        return *this += -days;
    }
    this->day -= days;
    while (true) {
        if (this->month == 1 || this->month == 3 || this->month == 5 ||
            this->month == 7 || this->month == 8 || this->month == 10) {
            if (this->day < 1) {
                this->day += 31;
                this->month--;
            } else break;
        } else if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11) {
            if (this->day < 1) {
                this->day += 30;
                this->month--;
            } else break;
        } else if (this->month == 2) {
            if ((this->year % 4 == 0 && this->year % 100 != 0) || this->year % 400 == 0) {
                if (this->day < 1) {
                    this->day += 29;
                    this->month--;
                } else break;
            } else {
                if (this->day < 1) {
                    this->day += 28;
                    this->month--;
                } else break;
            }
        }
        if (this->month < 1) {
            this->month = 12;
            this->year--;
        }
    }
    return *this;
}
ostream& operator<<(ostream& out, const Date& d) {
    out << (d.day < 10 ? "0" : "") << d.day << "/"
        << (d.month < 10 ? "0" : "") << d.month << "/"
        << d.year;
    return out;
}

istream& operator>>(istream& in, Date& d) {
    in >> d.day >> d.month >> d.year;
    return in;
}
