#ifndef _MAY_CPP
#define _MAY_CPP
#include <iostream>

using namespace std;

class May{
private:
    string maMay;
    string kieuMay;
    string tinhTrang;
public:
    string getMaMay() {
    	return this->maMay;
    }
    string getKieuMay() {
    	return this->kieuMay;
    }
    string getTinhTrang() {
    	return this->tinhTrang;
    }
    void nhap();
    void xuat();
    virtual ~May() {}
};

void May::nhap() {
    cout << "Nhap ma may: ";    fflush(stdin);  getline(cin, maMay);
    cout << "Nhap kieu may: ";    fflush(stdin);  getline(cin, kieuMay);
    cout << "Nhap tinh trang: ";    fflush(stdin);  getline(cin, tinhTrang);
}

void May::xuat() {
    cout << "Ma may: " << maMay << endl;
    cout << "Kieu may: " << kieuMay << endl;
    cout << "Tinh trang: " << tinhTrang << endl;
}
 #endif //_MAY_CPP

