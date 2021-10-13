#ifndef _QUANLY_CPP
#define _QUANLY_CPP
#include <iostream>

using namespace std;

class QuanLy {
private:
    string maql;
    string hoTen;
public:
    string getMaql() {
    	return this->maql;
    }
    string getHoTen() {
    	return this->hoTen;
    }
    void nhap();
    void xuat();
    virtual ~QuanLy() {}
};

void QuanLy::nhap() {
    cout << "Nhap ma quan ly: ";    fflush(stdin);  getline(cin, maql);
    cout << "Nhap ho ten: ";    fflush(stdin);  getline(cin, hoTen);
}

void QuanLy::xuat() {
    cout << "Ma quan ly: " << maql << endl;
    cout << "Ho ten: " << hoTen << endl;
}
#endif // _QUANLY_CPP
