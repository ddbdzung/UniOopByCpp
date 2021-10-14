#include <iostream>
#include <iomanip>

using namespace std;

class Hang {
private:
    string maHang;
    string tenHang;
    int donGia;
public:
    string getMaHang() {
    	return this->maHang;
    }
    string getTenHang() {
    	return this->tenHang;
    }
    int getDonGia() {
    	return this->donGia;
    }
    void nhap();
    void xuat();
    virtual ~Hang() {}
};

void Hang::nhap() {
    cout << "Nhap ma hang: ";   fflush(stdin);  getline(cin, maHang);
    cout << "Nhap ten hang: ";  fflush(stdin);  getline(cin, tenHang);
    cout << "Nhap don gia: ";   cin >> donGia;
}

void Hang::xuat() {
    cout << "Ma hang: " << maHang << endl;
    cout << "Ten hang: " << tenHang << endl;
    cout << "Don gia: " << donGia << endl;
}

class Phieu {
private:
    string maPhieu;
    Hang *x;
    int n;
public:
    Phieu() {
        cout << "Nhap so luong mat hang: "; cin >> n;
        x = new Hang[n];
    }
    void nhap();
    void xuat();
    virtual ~Phieu() {}
};

void Phieu::nhap() {
    cout << "Nhap ma phieu: ";    fflush(stdin);  getline(cin, maPhieu);
    for (int i = 0; i < n; i++) {
        cout << "Nhap mat hang thu " << i + 1 << ":\n";
        x[i].nhap();
    }
};

void Phieu::xuat() {
    cout << "Ma phieu: " << maPhieu << endl;    
    cout << setw(15) << left << "ma hang";
    cout << setw(15) << left << "ten hang";
    cout << setw(15) << right << "don gia" << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(15) << left << x[i].getMaHang();
        cout << setw(15) << left << x[i].getTenHang();
        cout << setw(15) << right << x[i].getDonGia() << endl;
    }
}

int main() {

    Phieu a;
    a.nhap();
    cout << "\n\n\n";
    a.xuat();

    return 0;
}