#include <iostream>

using namespace std;

class Nsx {
private:
    string mansx;
    string tennsx;
    string dcnsx;
    friend class Hang;
};

class Hang {
private:
    string maHang;
    string tenHang;
    long donGia;
    double trongLuong;
    Nsx x;
public:
    void nhap();
    void xuat();
    virtual ~Hang() {}
};

void Hang::nhap() {
    cout << "Nhap ma hang: ";   fflush(stdin);  getline(cin, maHang);
    cout << "Nhap ten hang: ";   fflush(stdin);  getline(cin, tenHang);
    cout << "Nhap don gia: ";   cin >> donGia;
    cout << "Nhap trong luong: ";   cin >> trongLuong;
    cout << "Nhap ma nha san xuat: ";   fflush(stdin);  getline(cin, x.mansx);
    cout << "Nhap ten nha san xuat: ";   fflush(stdin);  getline(cin, x.tennsx);
    cout << "Nhap dia chi nha san xuat: ";   fflush(stdin);  getline(cin, x.dcnsx);
}

void Hang::xuat() {
    cout << "Nhap ma hang: " << maHang << endl;
    cout << "Nhap ten hang: " << tenHang << endl;
    cout << "Nhap don gia: " << donGia << endl;
    cout << "Nhap trong luong: " << trongLuong << endl;
    cout << "Nhap ma nha san xuat: " << x.mansx << endl;
    cout << "Nhap ten nha san xuat: " << x.tennsx << endl;
    cout << "Nhap dia chi nha san xuat: " << x.dcnsx << endl;
}

int main() {

    Hang a;
    a.nhap();
    cout << "\n\n";
    a.xuat();

    return 0;
}
