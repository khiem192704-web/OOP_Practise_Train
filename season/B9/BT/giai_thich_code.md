# 📚 Giải thích chi tiết toàn bộ code — Quản lý Sinh viên (OOP)

## 🗺️ Sơ đồ tổng quan kiến trúc

```
MonHoc          ← lớp dữ liệu môn học
   ↑
  SV (abstract) ← lớp cha trừu tượng (base class)
  ↗     ↖
SVIT          SVCK    ← lớp con kế thừa (derived class)

QuanLi         ← lớp quản lý, chứa mảng con trỏ SV*
main.cpp       ← điểm vào chương trình, menu
```

---

## 📄 Mon.h — Khai báo lớp MonHoc

```cpp
#pragma once
```
> **Chỉ thị tiền xử lý (preprocessor directive):** Đảm bảo file header này chỉ được `#include` **một lần duy nhất** trong mỗi đơn vị biên dịch. Tránh lỗi khai báo trùng.

```cpp
#include <string>
using namespace std;
```
> Nạp thư viện `string` của C++. `using namespace std` cho phép dùng `string` thay vì `std::string`.

```cpp
class MonHoc {
```
> Khai báo lớp `MonHoc`. Lớp là một **khuôn mẫu (blueprint)** để tạo ra các đối tượng môn học.

```cpp
private:
    string tenmon;
    int tinchi = 0;
    double diem = 0.0;
```
> Các **thuộc tính private** (dữ liệu nội bộ). Chỉ code bên trong lớp mới truy cập được.
> - `tenmon`: tên môn học (chuỗi)
> - `tinchi`: số tín chỉ (số nguyên, mặc định 0)
> - `diem`: điểm số (số thực, mặc định 0.0)

```cpp
public:
    MonHoc(string ten = "", int tc = 0, double d = 0.0);
```
> **Constructor** (hàm khởi tạo) với tham số mặc định. Khi tạo `MonHoc` không truyền gì → dùng giá trị mặc định. Khai báo ở đây, định nghĩa trong `Mon.cpp`.

```cpp
    void nhap();
    void xuat() const;
    int getTinChi() const;
    double getDiem() const;
```
> **Phương thức (method):**
> - `nhap()`: nhập thông tin từ bàn phím
> - `xuat() const`: in thông tin ra màn hình — `const` nghĩa là hàm **không thay đổi** dữ liệu của object
> - `getTinChi()`, `getDiem()`: **getter** — trả về giá trị private từ bên ngoài

---

## 📄 Mon.cpp — Định nghĩa (implement) lớp MonHoc

```cpp
#include "Mon.h"
#include <iostream>
using namespace std;
```
> Nạp header của chính lớp và thư viện `iostream` để dùng `cout`, `cin`.

```cpp
MonHoc::MonHoc(string ten, int tc, double d) : tenmon(ten), tinchi(tc), diem(d) {}
```
> **Định nghĩa constructor** bằng **member initializer list** (`:` sau dấu ngoặc).
> Đây là cách khởi tạo nhanh, hiệu quả hơn gán trong thân hàm.
> Thân `{}` rỗng vì không cần làm gì thêm.

```cpp
void MonHoc::nhap() {
    cout << "Nhap ten mon: ";
    getline(cin >> ws, tenmon);
```
> In thông báo ra màn hình.
> `cin >> ws` — bỏ qua các **ký tự trắng** (whitespace, newline) còn sót trong buffer.
> `getline(...)` — đọc **cả dòng** kể cả khoảng trắng vào `tenmon`.

```cpp
    while (!(cin >> tinchi) || tinchi <= 0) {
        cout << "Tin chi khong hop le (phai > 0), nhap lai: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
```
> **Vòng lặp kiểm tra hợp lệ:**
> - `!(cin >> tinchi)`: đọc số nguyên. Nếu **thất bại** (nhập chữ) → `cin` ở trạng thái lỗi
> - `tinchi <= 0`: tín chỉ phải > 0
> - `cin.clear()`: **xóa cờ lỗi** của cin để dùng tiếp được
> - `cin.ignore(1000, '\n')`: **bỏ qua** tối đa 1000 ký tự cho đến khi gặp `'\n'` (xóa buffer bẩn)

```cpp
    while (!(cin >> diem) || diem < 0 || diem > 10) { ... }
```
> Tương tự — kiểm tra điểm phải trong đoạn [0, 10].

```cpp
void MonHoc::xuat() const {
    cout << "Ten mon: " << tenmon << " | Tin chi: " << tinchi << " | Diem: " << diem << '\n';
}
```
> In tất cả thông tin môn học ra màn hình. `const` → không sửa dữ liệu.

```cpp
int MonHoc::getTinChi() const { return tinchi; }
double MonHoc::getDiem() const { return diem; }
```
> **Getter** — trả về dữ liệu `private` từ bên ngoài lớp.

---

## 📄 SV.h — Khai báo lớp cơ sở trừu tượng SV

```cpp
#pragma once
#include "Mon.h"
#include <iostream>
#include <string>
using namespace std;
```
> Include header `Mon.h` (vì `SV` dùng `MonHoc`), và thư viện cần thiết.

```cpp
class SV {
protected:
    string MSSV;
    string Name;
    MonHoc *DSMH;
    int soMon;
```
> **`protected`** — khác với `private`: các lớp **con** (`SVIT`, `SVCK`) có thể **truy cập trực tiếp** các thuộc tính này, nhưng code bên ngoài lớp thì không.
> - `MSSV`, `Name`: mã số, tên sinh viên
> - `MonHoc *DSMH`: **con trỏ** trỏ đến mảng `MonHoc` (cấp phát động)
> - `soMon`: số lượng môn học

```cpp
public:
    virtual ~SV();
```
> **Destructor ảo (virtual destructor):** Cực kỳ quan trọng!
> Khi `delete` một con trỏ `SV*` mà thực chất trỏ đến `SVIT` hoặc `SVCK`,
> `virtual` đảm bảo **destructor của lớp con** được gọi đúng → không rò bộ nhớ.

```cpp
    virtual double GPA() const = 0;
    virtual bool XHB() const = 0;
    virtual void show() const = 0;
```
> **Hàm thuần ảo (pure virtual function)** — `= 0`.
> → Lớp `SV` trở thành **lớp trừu tượng (abstract class)**: **không thể tạo đối tượng `SV` trực tiếp**.
> → Bắt buộc các lớp con (`SVIT`, `SVCK`) **phải override** (ghi đè) các hàm này.
> - `GPA()`: tính điểm trung bình — mỗi khoa tính khác nhau
> - `XHB()`: kiểm tra có được học bổng không — tiêu chí mỗi khoa khác nhau
> - `show()`: hiển thị thông tin — mỗi loại SV hiển thị khác nhau

```cpp
    void nhapDanhSachMon();
    int tongTinChi() const;
    double tinhGPA() const;
```
> Các hàm **không ảo** — logic chung cho mọi sinh viên, không cần override.

```cpp
    int getSoMon() const { return this->soMon; }
    string getMSSV() const { return this->MSSV; }
    string getName() const { return this->Name; }
```
> **Getter** được định nghĩa **inline** ngay trong header (hàm ngắn).
> `this->` — con trỏ tự trỏ vào chính object hiện tại (có thể bỏ qua nhưng viết rõ ràng hơn).

---

## 📄 SV.cpp — Định nghĩa phần chung của lớp SV

```cpp
#include "SV.h"
```
> Nạp khai báo lớp `SV` để định nghĩa các phương thức của nó.

```cpp
SV::~SV() {
    delete[] DSMH;
}
```
> **Destructor** của `SV`: giải phóng mảng `MonHoc` được cấp phát động.
> `delete[]` — bắt buộc dùng khi cấp phát bằng `new[]`.

```cpp
void SV::nhapDanhSachMon() {
    if (this->DSMH != nullptr) {
        delete[] this->DSMH;
    }
```
> Nếu đã có mảng từ trước → **giải phóng cũ** trước khi cấp phát mới (tránh rò bộ nhớ).

```cpp
    int n;
    do {
        cout << "Nhap so mon hoc: ";
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
        } else if (n <= 0) {
            ...
        } else {
            break;
        }
    } while (true);
```
> Vòng `do-while(true)` — lặp mãi cho đến khi nhập hợp lệ.
> `cin.fail()` — kiểm tra xem `cin` có gặp lỗi khi đọc không (nhập chữ thay vì số).
> Khi nhập đúng (`n > 0`) → `break` thoát vòng lặp.

```cpp
    this->soMon = n;
    this->DSMH = new MonHoc[this->soMon];
```
> Lưu số môn. **Cấp phát động** mảng `n` phần tử `MonHoc`.
> `new MonHoc[n]` gọi **constructor mặc định** của `MonHoc` cho từng phần tử.

```cpp
    for (int i = 0; i < n; i++) {
        cout << "\n== Nhap mon hoc thu " << i + 1 << " ==\n";
        DSMH[i].nhap();
    }
```
> Vòng lặp nhập từng môn học bằng cách gọi `nhap()` của từng `MonHoc`.

```cpp
int SV::tongTinChi() const {
    int tong = 0;
    for (int i = 0; i < this->soMon; ++i) {
        tong += this->DSMH[i].getTinChi();
    }
    return tong;
}
```
> Tính **tổng tín chỉ** bằng cách duyệt qua từng môn và cộng dồn.

```cpp
double SV::tinhGPA() const {
    if (this->soMon == 0 || this->DSMH == nullptr)
        return 0.0;
    int tongTinChi = this->tongTinChi();
    double tongDiem = 0.0;
    if (tongTinChi == 0) return 0.0;
    for (int i = 0; i < this->soMon; ++i) {
        tongDiem += this->DSMH[i].getDiem() * this->DSMH[i].getTinChi();
    }
    return (tongTinChi == 0) ? 0.0 : (tongDiem / tongTinChi);
}
```
> Tính **GPA theo tín chỉ** (Weighted Average):
> `GPA = Σ(điểm_môn × tín_chỉ_môn) / Σ(tín_chỉ)`
> Kiểm tra chia cho 0 trước (guard clause).

```cpp
void SV::show() const {
    cout << "MSSV: " << this->MSSV << " | Ho ten: " << this->Name << endl;
    cout << "Danh sach mon hoc:\n";
    for (int i = 0; i < this->soMon; ++i) {
        this->DSMH[i].xuat();
    }
    cout << "GPA: " << this->tinhGPA() << endl;
}
```
> In thông tin **chung** của sinh viên. Lớp con sẽ gọi `SV::show()` và **bổ sung thêm** thông tin riêng.

---

## 📄 SVIT.h — Khai báo lớp SV Khoa IT

```cpp
#pragma once
#include "SV.h"
```
> Include `SV.h` vì `SVIT` kế thừa `SV`.

```cpp
class SVIT : public SV {
```
> `SVIT` **kế thừa public** từ `SV`.
> Nghĩa là tất cả `public` và `protected` của `SV` đều accessible trong `SVIT`.

```cpp
public:
    SVIT(const string &MSSV, const string &Name);
    ~SVIT();
    double GPA() const override;
    bool XHB() const override;
    void show() const override;
};
```
> **`override`** — từ khóa C++11, báo cho compiler biết hàm này đang ghi đè hàm ảo của lớp cha.
> Nếu tên hàm sai → compiler báo lỗi ngay (bảo vệ lập trình viên).
> `const string &` — tham chiếu hằng, không copy string, tiết kiệm bộ nhớ.

---

## 📄 SVIT.cpp — Định nghĩa lớp SVIT

```cpp
SVIT::SVIT(const string &MSSV, const string &Name) {
    this->MSSV = MSSV;
    this->Name = Name;
    this->DSMH = nullptr;
    this->soMon = 0;
}
```
> Constructor khởi tạo các thuộc tính được **kế thừa** từ `SV` (`protected`).
> `DSMH = nullptr`, `soMon = 0` vì chưa nhập môn học.

```cpp
SVIT::~SVIT() {}
```
> Destructor rỗng — việc giải phóng `DSMH` do destructor của **lớp cha** `SV::~SV()` lo.
> (Vì `SV::~SV()` được gọi tự động sau `SVIT::~SVIT()`).

```cpp
double SVIT::GPA() const {
    return this->tinhGPA();
}
```
> Implement hàm ảo `GPA()` — đơn giản là gọi hàm `tinhGPA()` dùng chung từ `SV`.

```cpp
bool SVIT::XHB() const {
    return (this->GPA() >= 8.0);
}
```
> **Tiêu chí học bổng SVIT**: GPA >= 8.0 là đủ.

```cpp
void SVIT::show() const {
    cout << "[Khoa: Cong nghe Thong tin]\n";
    SV::show();   // Gọi hàm show() của lớp cha
    cout << "Ket qua hoc bong: " << (XHB() ? "Dat hoc bong" : "Khong dat") << endl;
}
```
> In nhãn khoa, sau đó gọi `SV::show()` (ghi rõ tên lớp cha) để in thông tin chung.
> `SV::show()` — gọi trực tiếp hàm cha, không phải đệ quy.
> Toán tử 3 ngôi: `(điều_kiện) ? "đúng" : "sai"`.

---

## 📄 SVCK.cpp — Định nghĩa lớp SVCK (Cơ khí)

```cpp
bool SVCK::XHB() const {
    if (this->GPA() < 8.0) return false;
    for (int i = 0; i < soMon; ++i) {
        if (DSMH[i].getDiem() < 5.0) return false;
    }
    return true;
}
```
> **Tiêu chí học bổng SVCK nghiêm hơn**: GPA >= 8.0 **VÀ** không có môn nào dưới 5.0.
> So sánh với SVIT chỉ cần GPA >= 8.0 → Đây là **đa hình (polymorphism)** trong thực tế.

---

## 📄 QuanLi.h — Khai báo lớp Quản lý

```cpp
#pragma once
#include "SVIT.h"
#include "SVCK.h"
```
> Include cả hai lớp con vì `QuanLi` sẽ tạo đối tượng `SVIT` và `SVCK`.

```cpp
class QuanLi {
private:
    SV** DSSV;
    int n;
```
> `SV** DSSV` — **mảng con trỏ `SV*`**, cấp phát động.
> Đây là cốt lõi của **đa hình (polymorphism)**:
> Mỗi phần tử `DSSV[i]` có kiểu `SV*` nhưng thực chất trỏ đến `SVIT` hoặc `SVCK`.
> Khi gọi `DSSV[i]->show()` → **virtual dispatch** tự động gọi hàm đúng của lớp con.

```cpp
    QuanLi(int = 0);
```
> Constructor với tham số mặc định = 0. `int = 0` nghĩa là có thể gọi `QuanLi ql;` không truyền gì.

---

## 📄 QuanLi.cpp — Định nghĩa lớp QuanLi

```cpp
QuanLi::QuanLi(int n) : n(n) {
    DSSV = new SV*[n];
}
```
> Khởi tạo `n` bằng member initializer list. Cấp phát mảng `n` con trỏ `SV*`.
> Khi `n = 0` (mặc định) → cấp phát mảng rỗng.

```cpp
QuanLi::~QuanLi() {
    for (int i = 0; i < n; i++) {
        delete DSSV[i];   // Xóa từng đối tượng SVIT/SVCK
    }
    delete[] DSSV;        // Xóa mảng con trỏ
}
```
> Destructor **hai bước**: xóa từng object con rồi mới xóa mảng.
> Nếu chỉ `delete[] DSSV` → xóa mảng con trỏ nhưng **object bên trong vẫn rò bộ nhớ**.

```cpp
void QuanLi::nhapDSSV(int soLuong) {
    if (DSSV != nullptr) {
        for (int i = 0; i < n; i++) delete DSSV[i];
        delete[] DSSV;
    }
```
> Nếu đã có danh sách cũ → **dọn dẹp** trước khi tạo mới.

```cpp
    DSSV = new SV*[this->n];
    for (int i = 0; i < n; i++) {
        int type;
        cout << "Nhap loai sinh vien (1: SVIT, 2: SVCK): ";
        if (!(cin >> type)) {
            cin.clear(); cin.ignore(1000, '\n'); type = 0;
        }
        if (type != 1 && type != 2) {
            i--;    // Trừ lại để nhập lại lần này
            continue;
        }
```
> `i--` sau `continue` → vòng lặp `i++` rồi check lại `i < n` → index không tăng → nhập lại.

```cpp
        string MSSV, Name;
        cin >> MSSV;
        getline(cin >> ws, Name);
```
> `cin >> MSSV` — đọc MSSV (không có khoảng trắng).
> `getline(cin >> ws, Name)` — `cin >> ws` bỏ qua newline thừa, rồi đọc cả dòng tên.

```cpp
        if (type == 1)
            DSSV[i] = new SVIT(MSSV, Name);
        else
            DSSV[i] = new SVCK(MSSV, Name);
        DSSV[i]->nhapDanhSachMon();
```
> **Factory pattern đơn giản**: tạo đúng loại object theo `type`.
> Con trỏ `SV*` được gán địa chỉ của `SVIT` hoặc `SVCK` → **Upcasting**.

```cpp
void QuanLi::xoaSV(string MSSV) {
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (DSSV[i]->getMSSV() == MSSV && DSSV[i] != nullptr) {
            index = i; break;
        }
    }
```
> Tìm kiếm tuyến tính, lưu **index** của sinh viên cần xóa.

```cpp
    delete DSSV[index];          // Giải phóng object
    for (int i = index; i < n - 1; i++) {
        DSSV[i] = DSSV[i + 1];  // Dịch mảng sang trái
    }
    n--;
```
> Xóa object → **dịch chuyển** các phần tử phía sau lên → giảm `n`.
> Đây là kỹ thuật xóa phần tử trong mảng động (không dùng `vector`).

```cpp
void QuanLi::hienThiSVXHB() {
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (DSSV[i]->XHB()) {  // Gọi hàm ảo XHB()
            DSSV[i]->show();   // Gọi hàm ảo show()
            index++;
        }
    }
    if (index == 0)
        cout << "Khong co sinh vien nao dat hoc bong!" << endl;
    cout << "Tong so sinh vien dat hoc bong: " << index << endl;
}
```
> `DSSV[i]->XHB()` → **Virtual dispatch**: nếu SVIT gọi `SVIT::XHB()`, nếu SVCK gọi `SVCK::XHB()`.
> Đây là **đa hình thời gian chạy (runtime polymorphism)** — sức mạnh cốt lõi của OOP.

---

## 📄 main.cpp — Điểm vào chương trình

```cpp
#include "QuanLi.h"
```
> Include đủ toàn bộ cây kế thừa: QuanLi → SVIT/SVCK → SV → MonHoc.

```cpp
int main() {
    QuanLi ql;
```
> Tạo đối tượng `QuanLi` trên **stack**. Gọi `QuanLi::QuanLi(0)`.
> Khi `main` kết thúc → `ql` tự động bị hủy → `QuanLi::~QuanLi()` được gọi.

```cpp
    while (true) {
        // In menu...
        int choose;
        if (!(cin >> choose)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
```
> Vòng lặp menu vô hạn. Kiểm tra nếu nhập sai kiểu → xử lý lỗi và `continue` (lặp lại từ đầu).

```cpp
    switch (choose) {
        case 1: {
            int n;
            if (!(cin >> n) || n <= 0) { ...; break; }
            ql.nhapDSSV(n);
            break;
        }
```
> `switch-case` phân nhánh theo lựa chọn.
> `case 1` dùng `{}` tạo **scope mới** để khai báo biến `n` cục bộ.

```cpp
        case 0:
            cout << "Thoat chuong trinh.\n";
            return 0;
```
> `return 0` từ `main` → kết thúc chương trình. `ql` bị hủy → destructor dọn dẹp bộ nhớ.

```cpp
        default:
            cout << "Lua chon khong hop le! Vui long chon lai.\n";
```
> Xử lý khi nhập số không có trong menu.

---

## 🔑 Các khái niệm OOP cốt lõi trong bài

| Khái niệm | Thể hiện trong code |
|---|---|
| **Encapsulation** (Đóng gói) | `private` trong `MonHoc`, `QuanLi`; `protected` trong `SV` |
| **Inheritance** (Kế thừa) | `SVIT : public SV`, `SVCK : public SV` |
| **Polymorphism** (Đa hình) | `SV*` trỏ đến `SVIT`/`SVCK`; `virtual`, `override` |
| **Abstraction** (Trừu tượng) | `SV` là abstract class với `= 0` (pure virtual) |
| **Dynamic Memory** | `new`, `delete`, `new[]`, `delete[]` |
| **Virtual Destructor** | `virtual ~SV()` để destructor con được gọi đúng |
