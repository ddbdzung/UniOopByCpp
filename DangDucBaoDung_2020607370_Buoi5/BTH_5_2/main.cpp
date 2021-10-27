#include <iostream>
#include <iomanip>

using namespace std;

class MonHoc {
private:
    string ten;
public:
    MonHoc() {}
    string getTen() {
    	return this->ten;
    }
    int soTrinh;
    float diem;
    int getSoTrinh() {
    	return this->soTrinh;
    }
    float getDiem() {
    	return this->diem;
    }
    void nhap();
    virtual ~MonHoc() {}
};

void MonHoc::nhap() {
    cout << "Nhap ten mon hoc: ";   fflush(stdin);  getline(cin, ten);
    cout << "Nhap so trinh: ";  cin >> soTrinh;
    cout << "Nhap diem: ";  cin >> diem;
}

class SinhVien {
private:
    string MSV;
    string ten;
    string lop;
    string khoa;
public:
    SinhVien() {}
    string getMSV() {
    	return this->MSV;
    }
    string getTen() {
    	return this->ten;
    }
    string getLop() {
    	return this->lop;
    }
    string getKhoa() {
    	return this->khoa;
    }
    void nhap();
    virtual ~SinhVien() {}
};

void SinhVien::nhap() {
    cout << "Nhap ma sinh vien: ";  fflush(stdin);  getline(cin, MSV);
    cout << "Nhap ten sinh vien: ";  fflush(stdin);  getline(cin, ten);
    cout << "Nhap lop sinh vien: ";  fflush(stdin);  getline(cin, lop);
    cout << "Nhap khoa sinh vien: ";  fflush(stdin);  getline(cin, khoa);
}

class PhieuBaoDiem {
private:
    SinhVien x;
    MonHoc *ds;
    int n;
public:
    PhieuBaoDiem() {
        cout << "Nhap so luong mon hoc: ";  cin >> n;
        ds = new MonHoc[n];
    }
    void nhap();
    float dtb();
    void xuat();
    virtual ~PhieuBaoDiem() {}
};

void PhieuBaoDiem::nhap() {
    cout << "\nNhap thong tin cho phieu bao diem:..\n";
    cout << "\nThong tin sinh vien: \n";
    x.nhap();
    cout << "\nNhap thong tin cac mon hoc:..\n";
    for (int i = 0; i < n; i++) {
        ds[i].nhap();
    }
}

float PhieuBaoDiem::dtb() {
    float x = 0;
    float res, y = 0;
    for (int i = 0; i < n; i++) {
        x += (ds[i].getSoTrinh() * ds[i].getDiem());
        y += ds[i].getSoTrinh();
    }
    res = x * 1.0 / y;
    return res;
}

void PhieuBaoDiem::xuat() {
    cout << setw(36) << right << "PHIEU BAO DIEM";
    cout << "\n\n";
    cout << setw(10) << left << "Ma sinh vien: " << x.getMSV();
    cout << setw(20) << right << "Ten sinh vien: " << x.getTen() << "\n";
    cout << setw(10) << left << "Lop: " << x.getLop();
    cout << setw(20) << right << "Khoa: " << x.getKhoa() << "\n";
    cout << "Bang diem: \n";
    cout << setw(20) << left << "Ten mon";
    cout << setw(10) << left << "So trinh";
    cout << setw(10) << right << "Diem" << "\n";

    for (int i = 0; i < n; i++) {
        cout << setw(20) << left << ds[i].getTen();
        cout << setw(10) << left << ds[i].getSoTrinh();
        cout << setw(10) << right << ds[i].getDiem() << "\n";
    }
    cout << setw(30) << right << "Diem trung binh";
    cout << setw(10) << right << dtb() << "\n";
}

int main() {
    PhieuBaoDiem p;
    p.nhap();
    cout << "\n";
    p.xuat();
}
