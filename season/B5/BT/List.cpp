#include"List.h"
#include"Sinhvien.h"
List::List(){
    Sinhvien* sv = new Sinhvien[capacity];
}
List::List(const List& SV){
    this->sv = new Sinhvien[SV.capacity];
    this->n = SV.n;
    this->capacity = SV.capacity;
}

void List::show() const {
    for (int i = 0; i < n; i++) {
        sv[i].Sinhvien::Show();
    }
}

void List::add(const Sinhvien& newSv, int k) {
        if (k < 0 || k > n) {
            std::cout << "Vi tri khong hop le!\n";
            return;
        }
        for (int i = n; i > k; i--) {
            p[i] = p[i - 1];
        }
        p[k] = sv;
        n++;
    }

void List::update(const Sinhvien& updatedSv) {
    for (int i = 0; i < n; i++) {
        if (sv[i].getMssv() == updatedSv.getMssv()) {
            sv[i] = updatedSv;
            break;
        }
    }
}

void List::remove(const Sinhvien& svToRemove) {
    for (int i = 0; i < n; i++) {
        if (sv[i].getMssv() == svToRemove.getMssv()) {
            for (int j = i; j < n - 1; j++) {
                sv[j] = sv[j + 1];
            }
            n--;
            break;
        }
    }
}

void List::search(std::string name) const {
    for (int i = 0; i < n; i++) {
        if (sv[i].getHoten() == name) {
            sv[i].Show();
        }
    }
}
bool List::tangDan(float a, float b) {
    return a < b;
}
bool List::giamDan(float a, float b) {
    return a > b;
}
void List::sort(bool (*cmp)(float, float)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (!cmp(sv[j].getGpa(), sv[j + 1].getGpa())) {
                std::swap(sv[j], sv[j + 1]);
            }
        }
    }
}