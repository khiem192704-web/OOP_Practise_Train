#include<bits/stdc++.h>
using namespace std;

// void show(int x, int y = 1, int z = 2){
//     cout<<x<<" "<<y<<" "<<z<<endl;
// }

// int main(){
//     show(1); //1,1,2
//     show(1,2); //1,2,2
// }
// int y = 1;
// int &A(){
//     static int x = 1;
//     return x;
// }

// int &B(){
//     return y;
// }

// const int& c(){
//     return y;
// }

// int main(){
//     cout<<A()<<" "<<B()<<endl;
//     A() = 3; B() = 4;
//     cout<<y<<" "<<A()<<endl;
// }

// int main(){
//     int x = 10, y = 29;
//     int *p1, *p2;
//     p1 = &x; p2 = &y;
//     cout<<" x= "<<x<<endl;
//     cout<<" y= "<<y<<endl;
//     cout<<" p1= "<<*p1<<endl;
//     cout<<" p2= "<<*p2<<endl;
//     *p1 = 50; *p2 = 90;
//     cout<<" x= "<<x<<endl;
//     cout<<" y= "<<y<<endl;
//     cout<<" p1= "<<*p1<<endl;
//     cout<<" p2= "<<*p2<<endl;
//     *p1 = *p2;
//     cout<<" x= "<<x<<endl;
//     cout<<" y= "<<y<<endl;
//     cout<<" p1= "<<*p1<<endl;
//     cout<<" p2= "<<*p2<<endl;
// }

// int main(){
//     int x = 1;
//     int y = 2;
//     const int *p1 = &x; //con trỏ hằng chỉ tương tác được 1 chiều nma được trỏ tới nhiều vùng nhớ
//     //(*p1)++;
//     p1 = &y;
//     cout<<*p1<<endl;
//     int* const p2 = &y; //hằng con trỏ chỉ trỏ tới duy nhất 1 vùng nhớ và tương tác được 2 chiều
//     // p2 = &x;
//     *p2 = 5;
//     cout<<*p2<<endl;
// }

// int &A(){
//     int x = 1;
//     return x;
// }

// void show(char *str){
//     cout << str;
// }

// int main(){
//     const char *str = "DUT";
//     //show(str);
//     show(const_cast<char*>(str));
// }
// int main(){
//     int A[3] = {6,4,5};
//     int *p = A;
//     for(int i = 0; i < 3; i++){
//         cout<<A[i]<<" ";
//     }

//     //A<->&A[0]
//     cout<<A<<","<<&A[0]<<endl;
//     //p<->A<->&A[0]
//     cout<<p<<","<<A<<","<<&A[0]<<endl;
//     //&A[i] <->&p[i]<->p+i => i =1
//     cout<<&A[1]<<","<<&p[1]<<","<<p+1<<endl;
//     //A[i] <-> p[i] <-> *(p+i)
//     cout<<A[1]<<","<<p{1}<<","<<*(p+1)<<endl;
// }

int sum(int a, int b){
    return a+b;
}

int sub(int a, int b){
    return a-b;
}

int TT(int a , int b, int (*p1)(int ,int)){
    return p1(a,b);
}

int main(){
    int (*p)(int, int);
    p = sum;
    cout << sum(1,2) <<"," << p(1,2)<<endl;
    p = sub;
    cout << sub(2,1) <<"," << p(2,1)<<endl;
    cout << TT(2,1,sum) <<"," << TT(2,1,sub)<<endl;
}