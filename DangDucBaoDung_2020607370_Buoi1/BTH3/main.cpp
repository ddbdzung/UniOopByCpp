#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>

using namespace std;

class HANG
{
    char MAHANG[10];
    char TENHANG[20];
    float DONGIA;
    int SOLUONG;

public:
    void NHAP();
    void XUAT();
};
void HANG::NHAP()
{
    cout << "Ma hang : ";
    fflush(stdin);
    gets(MAHANG);
    cout << "Ten hang : ";
    fflush(stdin);
    gets(TENHANG);
    cout << "Don gia : ";
    cin >> DONGIA;
    cout << "So luong : ";
    cin >> SOLUONG;
}
void HANG::XUAT()
{
    cout << setw(10) << MAHANG << setw(20) << TENHANG << setw(10) << DONGIA << setw(10) << SOLUONG << setw(20) << DONGIA * SOLUONG << endl;
}
int main()
{
    int n;
    cout << "Nhap so mat hang: ";
    cin >> n;
    HANG *x = new HANG[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap hang " << i + 1 << endl;
        x[i].NHAP();
    }
    cout << setw(10) << "MA HANG" << setw(20) << "TEN HANG" << setw(10) << "DONGIA" << setw(10) << "SO LUONG" << setw(20) << "THANH TIEN" << endl;
    for (int i = 0; i < n; i++)
        x[i].XUAT();
    return 0;
}
