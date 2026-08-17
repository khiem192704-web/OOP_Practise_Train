#include<iostream>
using namespace std;
/* mỗi khi gọi hàm thì thời gian tồn tại các biến sẽ tồn tại từ khi gọi hàm đó tới khi kết thúc 
khi gọi hàm thì biến cục bộ động khi kết thúc gọi hàm sẽ giải phóng còn biến cục bộ tĩnh vẫn giưc nguyên
biến cục bộ tĩnh chỉ được gọi 1 lần
*/
/*
int z = 2;
void A(){
    int x = 3; // biến cục bộ động
    static int y = 5; // biến cục bộ tĩnh
    x++; y++;
    cout<<"x ="<<x<<",y ="<<y<<endl;
}
int main(){
    A();
    A();
    int z = 1;
    cout<<z<<","<<::z<<endl;
}

int main(){
    int x = 1;
    cout <<"x = "<< x <<",&x = "<< &x <<endl;
    int &y = x;
    y = 2;
    cout << "&x = " << &x <<",&y = "<< &y <<", x = " << x <<endl;
    int  *p = &x;
    cout<< *p <<","<< x <<endl;
    cout<< p <<","<< &x <<endl;
    cout<<&p<<endl;
}
*/
void HV(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

int main(){
    int a,b;
    cin>>a>>b;
    HV(a,b);
    cout<<a<<" "<<b<<endl;
}
