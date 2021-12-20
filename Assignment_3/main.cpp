#include <bits/stdc++.h>

using namespace std;

class PhanSo
{
private:
    int tu;
    int mau;

public:
    PhanSo();
    PhanSo(int a, int b);
    PhanSo operator*(PhanSo b);
    double operator-();
    friend istream &operator>>(istream &is, PhanSo &obj);
    friend ostream &operator<<(ostream &os, PhanSo &obj);
};
PhanSo::PhanSo()
{
    this->tu = 0;
    this->mau = 0;
}

PhanSo::PhanSo(int a, int b)
{
    this->tu = a;
    this->mau = b;
}

PhanSo PhanSo::operator*(PhanSo b)
{
    PhanSo res;
    res.tu = this->tu * b.tu;
    res.mau = this->mau * b.mau;
    return res;
}

double PhanSo::operator-()
{
    return (double)this->tu / this->mau;
}

istream &operator>>(istream &is, PhanSo &obj)
{
    cout << "Nhap tu so: ";
    cin >> obj.tu;
    cout << "Nhau mau so: ";
    cin >> obj.mau;
    return is;
}

ostream &operator<<(ostream &os, PhanSo &obj)
{
    cout << obj.tu << "/" << obj.mau << endl;
    return os;
}

int main()
{

    PhanSo a, b;
    cin >> a >> b;
    PhanSo c = a * b;
    fstream f("PHANSO.txt", ios::app);
    f << "a * b = " << c << " = " << -c << endl;

    return 0;
}