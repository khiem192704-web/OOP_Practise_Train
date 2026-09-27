#include<iostream>
#include<algorithm>
using namespace std;
void nhap(int *A, int n){
    cout<<"Nhap gia tri cac phan tu cua mang:"<<endl;
    for(int i = 0; i < n; i++){
        cout<<"A["<<i+1<<"] =";
        cin>>A[i];
    }
}

void xuat(int A[], int n){
    cout<<"Gia tri cac phan tu cua mang:"<<endl;
    for(int i = 0; i < n; i++){
        cout<<"A["<<i+1<<"] ="<<A[i]<<endl;
    }
}

void chen(int* &A, int &n) {
    int k, target;
    cout << "Nhap vi tri can chen (1 den " << n + 1 << "): ";
    cin >> k;
    cout << "Nhap gia tri can chen: ";
    cin >> target;

    int *temp = new int[n + 1];
    for (int i = 0; i < k - 1; i++) temp[i] = A[i];
    temp[k - 1] = target;
    for (int i = k; i <= n; i++) temp[i] = A[i - 1];

    delete[] A;
    A = temp;
    n++;
}

void delete_arr(int *A, int &n){
    int k;
    cout<<"Nhap vi tri can xoa:"<<endl;
    cin>>k;
    for(int i = k - 1; i < n - 1; i++) A[i] = A[i+1];
    n--;
}


void linear_search(int *A,int target,int n){
    int check = 0;
    for (int i=0;i<n;i++){
        if (A[i] == target){
            cout << "Phan tu " << target << " o vi tri " << i << endl;
            check = 1;
        }
    }
    if (check == 0) cout << "Khong tim thay phan tu " << target << endl;
}
void binary_search(int A[], int n, int target){
    int l = 0, r = n-1;
    int check = 0;
    while(l <= r){
        int mid = (l+r)/2;
        if(A[mid] == target){
            cout << "Phan tu " << target << " o vi tri " << mid << endl;
            check = 1;
        }
        if(A[mid] > target) r = mid - 1;
        else l = mid + 1;
    }
    if (check == 0) cout << "Khong tim thay phan tu " << target << endl;
}

void update(int *&A, int n){
    int k;
    int target;
    cout<<"Nhap vi tri can thay doi:"<<endl;
    cin>> k;
    cout<<"Nhap gia tri can thay doi:"<<endl;
    cin>>target;
    A[k-1] = target;
}
void bubbleSort(int *A,int n){
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if (A[j] > A[j+1]){
                swap(A[j],A[j+1]);
            }
        }
    }
    cout << "Mang sau khi sap xep : ";
    xuat(A,n);
}

void insertionSort(int *A,int n){
    for (int i=1;i<n;i++){
        int key = A[i];
        int j = i-1;
        while (j >= 0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
    cout << "Mang sau khi sap xep : ";
    xuat(A,n);
}

void selectionSort(int *A,int n){
    for (int i=0;i<n-1;i++){
        int min_idx = i;
        for (int j=i+1;j<n;j++){
            if (A[j] < A[min_idx]){
                min_idx = j;
            }
        }
        swap(A[min_idx],A[i]);
    }
    cout << "Mang sau khi sap xep : ";
    xuat(A,n);
}

void mergesort(int *A,int l,int r){
    if (l < r){
        int m = l + (r-l)/2;
        mergesort(A,l,m);
        mergesort(A,m+1,r);
        int n1 = m-l+1;
        int n2 = r-m;
        int *L = new int[n1];
        int *R = new int[n2];
        for (int i=0;i<n1;i++) L[i] = A[l+i];
        for (int j=0;j<n2;j++) R[j] = A[m+1+j];
        int i=0,j=0,k=l;
        while (i < n1 && j < n2){
            if (L[i] <= R[j]){
                A[k] = L[i];
                i++;
            }
            else{
                A[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1){
            A[k] = L[i];
            i++;
            k++;
        }
        while (j < n2){
            A[k] = R[j];
            j++;
            k++;
        }
        delete[] L;
        delete[] R;
    }
}


void quicksort(int *A,int l,int r){
    if (l < r){
        int pivot = A[r];
        int i = l-1;
        for (int j=l;j<r;j++){
            if (A[j] < pivot){
                i++;
                swap(A[i],A[j]);
            }
        }
        swap(A[i+1],A[r]);
        int pi = i+1;
        quicksort(A,l,pi-1);
        quicksort(A,pi+1,r);
    }
}

int main(){
    int n;
    cout<<"Nhap so phan tu cua mang:"<<endl;
    cin>>n;
    int *A = new int[n];
    nhap(A,n);
    xuat(A,n);
    chen(A,n);
    delete_arr(A,n);
    int target;
    cout<<"nhap phan tu can tim kiem"<<endl;
    cin>>target;
    linear_search(A,target,n);
    update(A,n);

    delete[] A;
}
