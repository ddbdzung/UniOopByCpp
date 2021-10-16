#include <iostream>

using namespace std;

class NSX {
private:
    string mansx;
    string tennsx;
    string dcnsx;
public:
    void nhap();
    void xuat();
    virtual ~NSX() {}
};

void NSX::nhap() {
    cout << "Nhap ma nha san xuat: ";    fflush(stdin);  getline(cin, mansx);
    cout << "Nhap ten nha san xuat: ";   fflush(stdin);  getline(cin, tennsx);
    cout << "Nhap dia chi nha san xuat: ";   fflush(stdin);  getline(cin, dcnsx);
};

void NSX::xuat() {
    cout << "Ma nha san xuat: " << mansx << endl;    
    cout << "Ten nha san xuat: " << tennsx << endl;
    cout << "Dia chi nha san xuat: " << dcnsx << endl;
}

class Hang {
private:
    string maHang;
    string tenHang;
    NSX x;
public:
    void nhap();
    void xuat();
    virtual ~Hang() {}
};

void Hang::nhap() {
    cout << "Nhap ma hang: ";   fflush(stdin);  getline(cin, maHang);
    cout << "Nhap ten hang: ";  fflush(stdin);  getline(cin, tenHang);
    x.nhap();
}

void Hang::xuat() {
    cout << "Ma hang: " << maHang << endl;
    cout << "Ten hang: " << tenHang << endl;
    x.xuat();   
}

int main() {

    Hang a;
    a.nhap();
    cout << "\n\n\n";
    a.xuat();

    return 0;
}