#include <iostream>
#include <iomanip>

using namespace std;

class Date {
private:
    int d;
    int m;
    int y;
public:
    void nhap(const string &s);
    void xuat();
    virtual ~Date() {}
};

void Date::nhap(const string &s) {
    cout << "Nhap ngay/thang/nam " << s << ": ";
    cin >> d >> m >> y;
}

void Date::xuat() {
    cout << d << "/" << m << "/" << y;
}

class NhanSu {
private:
    string maNhanSu;
    string hoTen;
    Date ns;
public:
    void nhap();
    void xuat();
    virtual ~NhanSu() {}
};

void NhanSu::nhap() {
    cout << "Nhap ma nhan su: ";   fflush(stdin);   getline(cin, maNhanSu);
    cout << "Nhap ho ten: ";   fflush(stdin);   getline(cin, hoTen);
    ns.nhap("sinh cua nhan su");
}
void NhanSu::xuat() {
    cout << "Ma nhan su: " << maNhanSu << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "Ngay sinh: ";  ns.xuat();
    cout << endl;
}

int main() {

    NhanSu p;
    p.nhap();
    cout << "\n";
    p.xuat();

    return 0;
}
