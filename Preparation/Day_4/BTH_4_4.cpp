#include <iostream>
#include <math.h>

using namespace std;

class Ptb2 {
private:
    float a;
    float b;
    float c;
public:
    Ptb2() {
        this->a = 0;
        this->b = 0;
        this->c = 0;
    }
    Ptb2(float a, float b, float c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    void nhap();
    void giai();
    void xuat();
    virtual ~Ptb2() {}
};

void Ptb2::nhap() {
    cout << "Nhap vao cac he so a, b, c: "; cin >> a >> b >> c;
}

void Ptb2::giai() {
    float delta = b*b - 4*a*c;
    if (delta < 0) {
        cout << "Pt vo nghiem\n";
        return;
    }
    float x1 = (-b - sqrt(delta)) / (2 * a);
    float x2 = (-b + sqrt(delta)) / (2 * a);
    cout << "x1 = " << x1 << "\n";
    cout << "x2 = " << x2 << "\n";
}

void Ptb2::xuat() {
    cout << a << "x2 + " << b << "x + " << c << " = 0\n";
}

int main() {

    Ptb2 p(1, -3, 2);
    p.xuat();
    p.giai();
    cout << "\n";
    Ptb2 q;
    q.nhap();
    q.xuat();
    q.giai();

    return 0;
}