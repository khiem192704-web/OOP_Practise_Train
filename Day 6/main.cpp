#include<iostream>
using namespace std;
#include"nganxep.h"
int main(){
    stack S;

    while(1){
        cout<<"Lua chon"<<endl;
        cout<<"1. Them"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. So luong phan tu"<<endl;
        cout<<"4. In"<<endl;
        cout<<"0. Thoat"<<endl;
        int choice;
        cout<<"Nhap lua chon:"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                int value;
                int n;
                cout<<"Nhap so luong cac phan tu:"<<endl;
                cin>>n;
                cout<<"Nhap cac phan tu:"<<endl;
                for(int i = 0; i < n; i++){
                    cin>>value;
                    S.push(value);
                }
                break;
            case 2:
                S.pop();
                cout<<"Cac phan tu hien tai:"<<endl;
                S.print();
                break;
            case 3:
                cout<<"So luong phan tu hien tai la:"<<S.numOfElement()<<endl;
                break;
            case 4:
                S.print();
                break;
            case 0: break;
            default: break;
        }
    }
}
