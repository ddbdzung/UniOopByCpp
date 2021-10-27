#include <iostream>
#include <sstream>
#include <string>
#include <malloc.h>
#include <iomanip>

using namespace std;

class Date {
private:
    int d;
    int m;
    int y;
    string convertIntToString(int x) {
        stringstream ss;
        ss << x;
        string str_x;
        ss >> str_x;
        ss.str("");
        ss.clear();
        return str_x;
    }
public:
    Date() {
        setD(0);
        setM(0);
        setY(0);
    }
    int getD() {
        return this->d;
    }
    void setD(int d) {
        this->d = d;
    }
    int getM() {
    	return this->m;
    }
    void setM(int m) {
    	this->m = m;
    }
    int getY() {
    	return this->y;
    }
    void setY(int y) {
    	this->y = y;
    }
    void nhap() {
        cout << "Nhap ngay/thang/nam: ";
        cin >> this->d >> this->m >> this->y;
    }
    void xuat() {
        cout << "Ngay/thang/nam: " << getD() << '/' << getM() << '/' << getY() << endl;
    }
    string getBirthString() {
        string res = "";
        string str_d = convertIntToString(getD());
        string str_m = convertIntToString(getM());
        string str_y = convertIntToString(getY());
        if (str_d.length() == 2) {
            res += str_d;
        } else if (str_d.length() == 1) {
            res = res + '0' + str_d;
        }
        res += '/';
        if (str_m.length() == 2) {
            res += str_m;
        } else if (str_m.length() == 1) {
            res = res + '0' + str_m;
        }
        res += '/';
        res += str_y;
        return res;
    }
    virtual ~Date() {}
};

class PhongKiemKe {
private:
    string maPhong;
    string tenPhong;
    string tenTruongPhong;
public:
    string getMaPhong() {
    	return this->maPhong;
    }
    string getTenPhong() {
    	return this->tenPhong;
    }
    string getTenTruongPhong() {
    	return this->tenTruongPhong;
    }
    void nhap() {
        cout << "Nhap ten phong kiem ke: "; fflush(stdin);  getline(cin, tenPhong);
        cout << "Nhap ma phong kiem ke: ";  fflush(stdin);  getline(cin, maPhong);
        cout << "Nhap ten truong phong: ";  fflush(stdin);  getline(cin, tenTruongPhong);
    }
    virtual ~PhongKiemKe() {}
};

class NhanVien {
private:
    string tenNV;
    string chucVuNV;
public:
    string getTenNV() {
    	return this->tenNV;
    }
    string getChucVuNV() {
    	return this->chucVuNV;
    }
    void nhap() {
        cout << "Nhap ten nhan vien: ";     fflush(stdin);  getline(cin, tenNV);
        cout << "Nhap chuc vu nhan vien: "; fflush(stdin);  getline(cin, chucVuNV);
    }
    virtual ~NhanVien() {}
};

class Phieu {
private:
    string maPhieu;
    Date ngayKiemKe;
    NhanVien id_nvkk;
    PhongKiemKe id_pkk;
public:
    Date getNgayKiemKe() {
    	return this->ngayKiemKe;
    }
    string getMaPhieu() {
    	return this->maPhieu;
    }
    NhanVien getId_nvkk() {
    	return this->id_nvkk;
    }
    PhongKiemKe getId_pkk() {
    	return this->id_pkk;
    }
    void nhap() {
        cout << "Nhap ma phieu kiem ke: ";  fflush(stdin);  getline(cin, maPhieu);
        ngayKiemKe.nhap();
        id_nvkk.nhap();
        id_pkk.nhap();
    }
    virtual ~Phieu() {}
};

class TaiSan {
private:
    string tenTaiSan;
    int soLuong;
    string tinhTrang;
public:
    void setSoLuong(int soLuong) {
    	this->soLuong = soLuong;
    }
    string getTenTaiSan() {
    	return this->tenTaiSan;
    }
    int getSoLuong() {
    	return this->soLuong;
    }
    string getTinhTrang() {
    	return this->tinhTrang;
    }
    void nhap() {
        cout << "Nhap ten tai san: ";   fflush(stdin);  getline(cin, tenTaiSan);
        cout << "Nhap so luong: ";  cin >> soLuong;
        cout << "Nhap tinh trang tai san: ";    fflush(stdin);  getline(cin, tinhTrang);
    }
    virtual ~TaiSan() {}
};

class PhieuKiemKeTaiSan {
private:
    Phieu id_phieu;
    TaiSan *listId_taiSan;
    int soLuongTaiSanKK;
public:
    PhieuKiemKeTaiSan() {
        cout << "Nhap so luong tai san: ";  cin >> soLuongTaiSanKK;
        listId_taiSan = new TaiSan[soLuongTaiSanKK];
    }

    void nhap() {
        id_phieu.nhap();
        for (int i = 0; i < soLuongTaiSanKK; i++) {
            (listId_taiSan + i)->nhap();
        }
    }

    void bonus1() {
        for (int i = 0; i < soLuongTaiSanKK; i++) {
            if (listId_taiSan[i].getTenTaiSan() == "May vi tinh") {
                listId_taiSan[i].setSoLuong(20);
            }
        }
    }

    void bonus2() {
        for (int i = soLuongTaiSanKK - 1; i >= 0; i--) {
            for (int j = 0; j <= i - 1; j++) {
                if (listId_taiSan[j].getSoLuong() > listId_taiSan[j + 1].getSoLuong()) {
                    TaiSan tmp = listId_taiSan[j];
                    listId_taiSan[j] = listId_taiSan[j + 1];
                    listId_taiSan[j + 1] = tmp;
                }
            }
        }
    }

    int tongSo() {
        int res = 0;
        for (int i = 0; i < soLuongTaiSanKK; i++) {
            res += listId_taiSan[i].getSoLuong();
        }
        return res;
    }

    void xuatThongTinPhieu() {
        cout << setw(30) << ' ';
        cout << "PHIEU KIEM KE TAI SAN";
        cout << setw(30) << ' ';
        cout << "\n\n";
        cout << "Ma phieu: ";
        cout << setw(39) << left << id_phieu.getMaPhieu();
        cout << "Ngay kiem ke: ";
        cout << setw(30) << left << id_phieu.getNgayKiemKe().getBirthString() << endl;
        cout << "Nhan vien kiem ke: ";
        cout << setw(30) << left << id_phieu.getId_nvkk().getTenNV();
        cout << "Chuc vu: ";
        cout << setw(30) << left << id_phieu.getId_nvkk().getChucVuNV() << endl;
        cout << "Kiem ke tai phong: ";
        cout << setw(30) << left << id_phieu.getId_pkk().getTenPhong();
        cout << "Ma phong: ";
        cout << setw(30) << left << id_phieu.getId_pkk().getMaPhong() << endl;
        cout << "Truong phong: ";
        cout << setw(60) << left << id_phieu.getId_pkk().getTenTruongPhong() << endl;
    }
    void xuatDanhSachTaiSan() {
        cout << setw(20) << left << "|Ten tai san";
        cout << setw(20) << left << "|So luong";
        cout << setw(20) << left << "|Tinh trang        |" << endl;
        cout << setfill('-');
        cout << setw(60) << '-' << endl;
        cout << setfill(' ');
        for (int i = 0; i < soLuongTaiSanKK; i++) {
            cout << setw(20) << left << (listId_taiSan + i)->getTenTaiSan();
            cout << setw(20) << left << (listId_taiSan + i)->getSoLuong();
            cout << setw(20) << left << (listId_taiSan + i)->getTinhTrang() << endl;
        }
        cout << setw(20) << left << "So tai san da kiem ke: " << soLuongTaiSanKK;
        cout << setw(30) << right << "Tong so luong: " << tongSo() << endl;
    }
    void xuatPhieu() {
        xuatThongTinPhieu();
        cout << "\n";
        xuatDanhSachTaiSan();
    }
    virtual ~PhieuKiemKeTaiSan() {}
};

int main() {

    PhieuKiemKeTaiSan p;
    p.nhap();
    p.xuatPhieu();
    int choice;
    while (true) {
        cout << "1. bonus1\n2. bonus2\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            {
                p.bonus1();
                p.xuatPhieu();
                break;
            }
        case 2:
            {
                p.bonus2();
                p.xuatPhieu();
                break;
            }
        default:
            return 0;
        }
    }

    return 0;
}
