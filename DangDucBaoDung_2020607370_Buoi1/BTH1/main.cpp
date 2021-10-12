#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>

using namespace std;

class SINHVIEN
{
    char MASV[30];
    char HOTEN[50];
    int TUOI;
    float DIEM;

public:
    void NHAP();
    void XUAT();
};
void SINHVIEN::NHAP()
{
    cout << "Ma SV: ";
    fflush(stdin);
    gets(MASV);
    cout << "Ho Ten: ";
    fflush(stdin);
    gets(HOTEN);
    cout << "Tuoi: ";
    cin >> TUOI;
    cout << "Diem: ";
    cin >> DIEM;
}
void SINHVIEN::XUAT()
{
    cout << "Ma SV: " << MASV << endl;
    cout << "Ho ten: " << HOTEN << endl;
    cout << "Tuoi: " << TUOI << endl;
    cout << "Diem: " << DIEM << endl << endl;
}

int main()
{
    SINHVIEN a, b;
    cout << "Nhap thong tin cua sinh vien a:" << endl;
    a.NHAP();
    cout << "Nhap thong tin cua sinh vien b:" << endl;
    b.NHAP();
    cout << endl << "Sinh vien a" << endl;
    a.XUAT();
    cout << "Sinh vien b" << endl;
    b.XUAT();
    return 0;
}
