#include <iostream>

using namespace std;

class Date {
private:
    int d;
    int m;
    int y;
public:
    friend class Hang;
};

class Hang {
private:
    string maHang;
    string tenHang;
    Date ngaySx;
public:
    void nhap();
    void xuat();
    virtual ~Hang() {}
};

void Hang::nhap() {
    cout << "Nhap ma hang: ";   fflush(stdin);  getline(cin, maHang);
    cout << "Nhap ten hang: ";   fflush(stdin);  getline(cin, tenHang);
    cout << "Nhap ngay/thang/nam san xuat: ";   cin >> ngaySx.d >> ngaySx.m >> ngaySx.y;
}

void Hang::xuat() {
    cout << "Ma hang: " << maHang << endl;
    cout << "Ten hang: " << tenHang << endl;
    cout << "Ngay san xuat: " << ngaySx.d << "/" << ngaySx.m << "/" << ngaySx.y << endl;
}

int main() {

    Hang *p;
    int n;
    cout << "Nhap so luong mat hang: "; cin >> n;
    p = new Hang[n];
    for (int i = 0; i < n; i++) {
        (p + i)->nhap();
    }
    cout << "\nCac mat hang san xuat trong nam 2017:\n";
    for (int i = 0; i < n; i++) {
        (p + i)->xuat();
        cout << "\n";
    }


    return 0;
}
