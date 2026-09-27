#include"date.h"
int main() {
    Date d(28, 2, 2024); // Năm nhuận
    cout << "Ngay ban dau: " << d << endl;
    ++d;
    cout << "Sau khi ++: " << d << endl;        // 29/02/2024
    d += 2;
    cout << "Sau khi += 2: " << d << endl;      // 02/03/2024
    d--;
    cout << "Sau khi d--: " << d << endl;       // 01/03/2024

    return 0;
}
