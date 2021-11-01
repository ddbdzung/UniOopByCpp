#include <iostream>

using namespace std;

class Printer {
protected:
    double trongLuong;
    string hangSX;
    int namSX;
    int tocDo;
public:
    virtual ~Printer() {}
};

class DotPrinter : public Printer {
private:
    int matDoKim;
public:
    void nhap();
    void xuat();
    virtual ~DotPrinter() {}
};

void DotPrinter::nhap() {
    cout << "Nhap trong luong: ";   cin >> trongLuong;
    cout << "Nhap hang san xuat: "; fflush(stdin);  getline(cin, hangSX);
    cout << "Nhap nam san xuat: "; cin >> namSX;
    cout << "Nhap toc do: ";    cin >> tocDo;
    cout << "Nhap mat do kim: ";    cin >> matDoKim;
}
void DotPrinter::xuat() {
    cout << "Trong luong: " << trongLuong << endl;
    cout << "Hang SX: " << hangSX << endl;
    cout << "Nam SX: " << namSX << endl;
    cout << "Toc do: " << tocDo << endl;
    cout << "Mat do kim: " << matDoKim << endl;
}

class LaserPrinter : public Printer {
private:
    int doPhanGiai;
public:
    void nhap();
    void xuat();
    virtual ~LaserPrinter() {}
};

void LaserPrinter::nhap() {
    cout << "Nhap trong luong: ";   cin >> trongLuong;
    cout << "Nhap hang san xuat: "; fflush(stdin);  getline(cin, hangSX);
    cout << "Nhap nam san xuat: "; cin >> namSX;
    cout << "Nhap toc do: ";    cin >> tocDo;
    cout << "Nhap do phan giai: ";    cin >> doPhanGiai;
}
void LaserPrinter::xuat() {
    cout << "Trong luong: " << trongLuong << endl;
    cout << "Hang SX: " << hangSX << endl;
    cout << "Nam SX: " << namSX << endl;
    cout << "Toc do: " << tocDo << endl;
    cout << "Do phan giai: " << doPhanGiai << endl;
}

int main() {

    cout << "Nhap vao thong tin may in laser: ";
    LaserPrinter a;
    a.nhap();
    cout << "\n";
    a.xuat();
    cout << "\n";
    cout << "Nhap vao thong tin may in kim: ";
    DotPrinter b;
    b.nhap();
    cout << "\n";
    b.xuat();
    cout << "\n";

    return 0;
}