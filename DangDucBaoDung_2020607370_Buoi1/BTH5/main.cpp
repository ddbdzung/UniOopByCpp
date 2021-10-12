#include <bits/stdc++.h>

using namespace std;

class PTB2 {
private:
    float a;
    float b;
    float c;
public:
    void nhap() {
        cout << "Nhap a: "; cin >> a;
        cout << "Nhap b: "; cin >> b;
        cout << "Nhap c: "; cin >> c;
    }
    void giai() {
        if (a == 0) {
            cout << "Day khong phai phuong trinh bac 2";
        } else {
            float delta = b*b - 4*a*c;
            if (delta < 0) {
                cout << "Phuong trinh vo nghiem";
            } else {
                cout << "x1 = " << (-b + sqrt(delta)) / (2*a) << endl;
                cout << "x2 = " << (-b - sqrt(delta)) / (2*a) << endl;
            }
        }
    }
    void xuat() {
        cout << "Phuong trinh: " << a << "x" << (char) 253 << " + " << b << "x + " << c << " = 0\n";
    }
};

int main()
{
    PTB2 x;
    x.nhap();
    x.xuat();
    x.giai();
    return 0;
}
