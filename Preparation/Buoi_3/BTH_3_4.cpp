#include <iostream>
#include <iomanip>

using namespace std;

class May{
private:
    string maMay;
    string kieuMay;
    string tinhTrang;
public:
    string getMaMay() {
    	return this->maMay;
    }
    string getKieuMay() {
    	return this->kieuMay;
    }
    string getTinhTrang() {
    	return this->tinhTrang;
    }
    void nhap();
    void xuat();
    virtual ~May() {}
};

void May::nhap() {
    cout << "Nhap ma may: ";    fflush(stdin);  getline(cin, maMay);
    cout << "Nhap kieu may: ";    fflush(stdin);  getline(cin, kieuMay);
    cout << "Nhap tinh trang: ";    fflush(stdin);  getline(cin, tinhTrang);
}

void May::xuat() {
    cout << "Ma may: " << maMay << endl;
    cout << "Kieu may: " << kieuMay << endl;
    cout << "Tinh trang: " << tinhTrang << endl;
}

class QuanLy {
private:
    string maql;
    string hoTen;
public:
    string getMaql() {
    	return this->maql;
    }
    string getHoTen() {
    	return this->hoTen;
    }
    void nhap();
    void xuat();
    virtual ~QuanLy() {}
};

void QuanLy::nhap() {
    cout << "Nhap ma quan ly: ";    fflush(stdin);  getline(cin, maql);
    cout << "Nhap ho ten: ";    fflush(stdin);  getline(cin, hoTen);
}

void QuanLy::xuat() {
    cout << "Ma quan ly: " << maql << endl;
    cout << "Ho ten: " << hoTen << endl;
}

class PhongMay {
private:
    string maPhong;
    string tenPhong;
    double dienTich;   
    QuanLy x;
    May *y;
    int n;
public:
    PhongMay() {
        cout << "Nhap so luong may tinh: "; cin >> this->n;
        y = new May[n];
    }
    void nhap();
    void xuat();
    virtual ~PhongMay() {}
};

void PhongMay::nhap() {
    cout << "Nhap ma phong may: "; fflush(stdin);   getline(cin, maPhong);
    cout << "Nhap ten phong may: "; fflush(stdin);   getline(cin, tenPhong);
    cout << "Nhap dien tich phong may: ";   cin >> dienTich;
    x.nhap();
    for (int i = 0; i < n; i++) {
        cout << "Nhap may tinh thu " << i + 1 << ":\n";
        (y + i)->nhap();
    }
}

void PhongMay::xuat() {
    cout << setw(50) << "PHONG MAY\n\n";
    cout << setw(25) << left << "Ma phong: " << maPhong << endl;
    cout << setw(20) << left << "Ten phong: " << tenPhong;
    cout << setw(15) << right << "Dien tich: " << dienTich << endl;
    cout << setw(20) << left << "Ma quan ly: " << x.getMaql();
    cout << setw(15) << right << "Ten quan ly: " << x.getHoTen() << endl << endl;

    cout << setw(10) << left << "STT";
    cout << setw(15) << left << "Ma may";
    cout << setw(15) << left << "Kieu may";
    cout << setw(10) << right << "Tinh trang\n";

    for (int i = 0; i < n; i++) {
        cout << setw(10) << left << i + 1; 
        cout << setw(15) << left << y[i].getMaMay(); 
        cout << setw(15) << left << y[i].getKieuMay(); 
        cout << setw(10) << right << y[i].getTinhTrang() << endl; 
    }
}

int main() {

    PhongMay a;
    a.nhap();
    cout << "\n\n";
    a.xuat();

    return 0;
}
