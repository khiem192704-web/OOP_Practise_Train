#include<bits/stdc++.h>
using namespace std;
class Person{
    private:
        string name;
        string address;
    public:
        Person(string name, string address){
            this->name = name;
            this->address = address;
        }
        void nhap(){
            getline(cin,name);
            getline(cin,address);
        }
        string getName(){
            return name;
        }
        string getAddress(){
            return address;
        }
        void setName(string name){
            this->name = name;
        }
        void setAddress(string address){
            this->address = address;
        }
        void in(){
            cout << name <<" "<< address <<" ";
        }
};

class Student : public Person{
    private:
        float gpa;
    public:
        Student(string name, string address, float gpa) : Person(name,address){
            this->gpa = gpa;
        }
        void nhap(){
            Person::nhap();
            cin >> gpa;
        }
        float getGpa(){
            return gpa;
        }
        void setGpa(float gpa){
            this->gpa = gpa;
        }
        void in(){
            Person::in();
            cout << fixed << setprecision(2) << gpa << endl;
        }
};

int main(){
    // Student s;
    // s.setName("Nguyen Van A");
    // s.setAddress("Hai Phong");
    // s.setGpa(2.8);
    // cout << s.getName() <<" "<< s.getAddress() <<" "<< s.getGpa() <<endl;
    //s.nhap();
    Student s("Nguyen Van A", "Hai Duong",3.5);
    s.in();
}