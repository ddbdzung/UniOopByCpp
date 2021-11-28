#include <iostream>
#include <sstream>

using namespace std;

class Nguoi {
private:
    string hoTen;
    int tuoi;
public:
    void nhap();
    void xuat();
};

void Nguoi::nhap() {
    cout << "Nhap ho ten: ";    fflush(stdin);  getline(cin, hoTen);
    cout << "Nhap tuoi: ";  cin >> tuoi;
}

void Nguoi::xuat() {
    cout << "Ho ten: " << hoTen << endl;
    cout << "Tuoi: " << tuoi << endl;
}

class BenhVien {
public:
    string tenBenhVien;
    string diaChi;
    Nguoi giamDoc;
};

class BenhNhan : public Nguoi {
private:
    string ma;
    string tienSu;
    string chanDoan;
    BenhVien a;
public:
    void nhap();
    void xuat();
};

void BenhNhan::nhap() {
    cout << "Ma: "; fflush(stdin);  getline(cin, ma);
    cout << "Tien su: "; fflush(stdin);  getline(cin, tienSu);
    cout << "Chan doan: "; fflush(stdin);  getline(cin, chanDoan);
    cout << "Ten benh vien: ";  fflush(stdin);  getline(cin, a.tenBenhVien);
    cout << "Dia chi benh vien: ";  fflush(stdin);  getline(cin, a.diaChi);
    cout << "Giam doc benh vien:\n"; a.giamDoc.nhap();
}

void BenhNhan::xuat() {
    cout << "Ma: " << ma << endl;
    cout << "Tien su: " << tienSu << endl;
    cout << "Chan doan: " << chanDoan << endl;
    cout << "Ten benh vien: " << a.tenBenhVien << endl;
    cout << "Dia chi benh vien: " << a.diaChi << endl;
    cout << "Giam doc benh vien:\n";
    a.giamDoc.xuat();
}

int main() {
    BenhNhan *p;
    int n;
    cout << "Nhap vao so luong benh nhan: "; cin >> n;
    p = new BenhNhan[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap benh nhan thu " << i + 1 << ":\n";
        p[i].nhap();
    }
    cout << "\n\n";
    for (int i = 0; i < n; i++) {
        cout << "Nhap benh nhan thu " << i + 1 << ":\n";
        p[i].xuat();
    }
}
