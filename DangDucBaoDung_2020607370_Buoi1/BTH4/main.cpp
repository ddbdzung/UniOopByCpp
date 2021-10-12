#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdio.h>

using namespace std;

class SACH
{
    char MASACH[10];
    char TENSACH[20];
    int SOTRANG;
    float GIATIEN;

public:
    void NHAP();
    void XUAT();
};
void SACH::NHAP()
{
    cout << "Ma sach : ";
    fflush(stdin);
    gets(MASACH);
    cout << "Ten sach : ";
    fflush(stdin);
    gets(TENSACH);
    cout << "So trang : ";
    cin >> SOTRANG;
    cout << "Gia tien : ";
    cin >> GIATIEN;
}
void SACH::XUAT()
{
    cout << setw(10) << MASACH << setw(20) << TENSACH << setw(10) << SOTRANG << setw(10) << GIATIEN << endl;
}
int main()
{
    int n;
    cout << "Nhap so sach: ";
    cin >> n;
    SACH *x = new SACH[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap sach thu " << i + 1 << endl;
        x[i].NHAP();
    }
    cout << setw(10) << "MA SACH" << setw(20) << "TEN SACH" << setw(10) << "SOTRANG" << setw(10) << "GIA TIEN" << endl;
    for (int i = 0; i < n; i++)
        x[i].XUAT();
    return 0;
}
