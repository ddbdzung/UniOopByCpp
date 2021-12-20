#include <bits/stdc++.h>
using namespace std;
class TAMTHUC
{
    float a, b, c;

public:
    TAMTHUC();
    TAMTHUC(float x, float y, float z);
    TAMTHUC operator+(TAMTHUC y);
    TAMTHUC operator-(TAMTHUC y);
    TAMTHUC operator-();
    friend ostream &operator<<(ostream &x, TAMTHUC y);
};
TAMTHUC::TAMTHUC()
{
    a = b = c = 0;
}
TAMTHUC::TAMTHUC(float x, float y, float z)
{
    a = x;
    b = y;
    c = z;
}
TAMTHUC TAMTHUC::operator+(TAMTHUC y)
{
    TAMTHUC tg;
    tg.a = a + y.a;
    tg.b = b + y.b;
    tg.c = c + y.c;
    return tg;
}
TAMTHUC TAMTHUC::operator-(TAMTHUC y)
{
    TAMTHUC tg;
    tg.a = a - y.a;
    tg.b = b - y.b;
    tg.c = c - y.c;
    return tg;
}
TAMTHUC TAMTHUC::operator-()
{
    TAMTHUC tg;
    tg.a = -a;
    tg.b = -b;
    tg.c = -c;
    return tg;
}
ostream &operator<<(ostream &x, TAMTHUC y)
{
    x << y.a << " X" << (char)253;
    if (y.b >= 0)
        x << " + " << y.b << " X ";
    else
        x << " - " << -y.b << " X ";
    if (y.c >= 0)
        x << " + " << y.c;
    else
        x << " - " << -y.c;
    return x;
}
int main()
{
    TAMTHUC x(2, 5, 4), y(1, 4, 2);
    x = -x;
    y = -y;
    ofstream f("Tên tệp.txt", ios::out);
    f << "Tam thuc x da dao dau: " << x << endl;
    f << "Tam thuc y da dao dau: " << y << endl;
    TAMTHUC T = x + y;
    TAMTHUC H = x - y;
    f << "Tam thuc TONG: " << T << endl;
    f << "Tam thuc HIEU: " << H << endl;
    f.close();
    return 0;
}