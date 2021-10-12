#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdio.h>

using namespace std;

class HCN
{
    float D, R;

public:
    void NHAP();
    void VE();
    float DIENTICH();
    float CHUVI();
};
void HCN::NHAP()
{
    cout << "Chieu dai : ";
    cin >> D;
    cout << "Chieu rong: ";
    cin >> R;
}
void HCN::VE()
{
    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < R; j++)
            cout << "*";
        cout << endl;
    }
}
float HCN::DIENTICH()
{
    return D * R;
}
float HCN::CHUVI()
{
    return 2 * (D + R);
}
int main()
{
    HCN x;
    x.NHAP();
    x.VE();
    cout << "Dien tich HCN: " << x.DIENTICH() << endl;
    cout << "Chu vi HCN : " << x.CHUVI();
    return 0;
}
