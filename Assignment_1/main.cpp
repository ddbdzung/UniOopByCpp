#include <iostream>
#include <iomanip>

using namespace std;

class SanPham {
private:
    string maSanPham;
    string tenSanPham;
    int soLuong;
    long donGia;
public:
    string getMaSanPham() {
    	return this->maSanPham;
    }
    string getTenSanPham() {
    	return this->tenSanPham;
    }
    int getSoLuong() {
    	return this->soLuong;
    }
    long getDonGia() {
    	return this->donGia;
    }
    void nhap() {
        cout << "Nhap ma san phan: ";
        fflush(stdin);
        getline(cin, maSanPham);    
        cout << "Nhap ten san pham: ";
        fflush(stdin);
        getline(cin, tenSanPham);    
        cout << "Nhap so luong: ";  cin >> soLuong;
        cout << "Nhap don gia: ";   cin >> donGia;
    }
    long getThanhTien() {
        return soLuong * donGia;
    }
    void xuat() {
        cout << "Ma san pham: " << maSanPham << endl;
        cout << "Ten san pham: " << tenSanPham << endl;
        cout << "So luong: " << soLuong << endl;
        cout << "Don gia: " << donGia << endl;
        cout << "Thanh tien: " << getThanhTien() << endl;
    }

    virtual ~SanPham() {}
};

class NhaCungCap {
private:
    string maNCC;
    string tenNCC;
    string diaChi;
    string SDT;
public:
    string getMaNCC() {
    	return this->maNCC;
    }
    string getTenNCC() {
    	return this->tenNCC;
    }
    string getDiaChi() {
    	return this->diaChi;
    }
    string getSDT() {
    	string res = SDT;
        for (int i = SDT.length() - 1; i >= SDT.length() - 4; i--) {
            res[i] = 'x';
        }
        return res;
    }
    void nhap() {
        cout << "Nhap ma nha cung cap: ";
        fflush(stdin);
        getline(cin, maNCC);    
        cout << "Nhap ten nha cung cap: ";
        fflush(stdin);
        getline(cin, tenNCC);    
        cout << "Nhap dia chi nha cung cap: ";
        fflush(stdin);
        getline(cin, diaChi);    
        cout << "Nhap SDT nha cung cap: ";
        fflush(stdin);
        getline(cin, SDT);    
    }
    void xuat() {
        cout << "Ma nha cung cap: " << maNCC << endl;
        cout << "Ten nha cung cap: " << tenNCC << endl;
        cout << "Dia chi: " << diaChi << endl;
        cout << "SDT: " << SDT << endl;
    }
    virtual ~NhaCungCap() {}
};

class Date {
private:
    int d;
    int m;
    int y;
public:
    int getD() {
    	return this->d;
    }
    int getM() {
    	return this->m;
    }
    int getY() {
    	return this->y;
    }
    void nhap(const string &s) {
        cout << "Nhap ngay/thang/nam " << s << ": ";
        cin >> d >> m >> y;
    }
    void nhap() {
        cin >> d >> m >> y;
    }
    void xuat() {
        cout << d << "/" << m << "/" << y;
    }
    virtual ~Date() {}
};

class Phieu {
private:
    string maPhieu;
    Date ngayLap;
public:
    string getMaPhieu() {
    	return this->maPhieu;
    }
    Date getNgayLap() {
        return this->ngayLap;
    }
    void nhap() {
        cout << "Nhap ma phieu: ";  
        fflush(stdin);  getline(cin, maPhieu);  
        ngayLap.nhap("lap phieu");
    }
    void xuat() {
        cout << "Ma phieu: " << maPhieu << endl;
        ngayLap.xuat();
    }
    virtual ~Phieu() {}
};

class NoiDungPhieu {
private:
    Phieu phieu;
    NhaCungCap ncc;
    SanPham *list;
public:
    int soLoaiSP;
    int tongTien = 0;
    void nhap() {
        phieu.nhap();
        ncc.nhap();
        cout << "Nhap so loai san pham: ";  cin >> soLoaiSP;
        list = new SanPham[soLoaiSP];
        for (int i = 0; i < soLoaiSP; i++) {
            list[i].nhap();
            tongTien += list[i].getThanhTien();
        }
    }
    void xuatPhieu() {
        cout << setw(50) << right << "PHIEU NHAP VAN PHONG PHAM" << endl << endl;

        cout << setw(25) << left << "Ma phieu: " << phieu.getMaPhieu();
        cout << setw(35) << right << "Ngay lap: "; phieu.getNgayLap().xuat();
        cout << endl;
        cout << setw(25) << left << "Ma nha cung cap: " << ncc.getMaNCC();
        cout << setw(35) << right << "Ten nha cung cap: " << ncc.getTenNCC() << endl;
        cout << setw(25) << left << "Dia chi: " << ncc.getDiaChi();
        cout << setw(35) << right << "SDT: " << ncc.getSDT() << endl << endl;

        cout << setw(15) << left << "Ma SP";
        cout << setw(20) << left << "Ten san pham";
        cout << setw(15) << left << "So luong";
        cout << setw(15) << left << "Don gia";
        cout << setw(20) << right << "Thanh tien" << endl;
        for (int i = 0; i < soLoaiSP; i++) {
            cout << setw(15) << left << list[i].getMaSanPham();
            cout << setw(20) << left << list[i].getTenSanPham();
            cout << setw(15) << left << list[i].getSoLuong();
            cout << setw(15) << left << list[i].getDonGia();
            cout << setw(20) << right << list[i].getThanhTien() << endl;
        }
        cout << setw(65) << right << "TONG   ";
        cout << setw(20) << right << tongTien << endl;
    }
    int task1() {
        int count = 0;
        for (int i = 0; i < soLoaiSP; i++) {
            if (list[i].getSoLuong() < 80) {
                count++;
            }
        }
        return count;
    }
    void task2() {
        for (int i = soLoaiSP - 1; i >= 0; i--) {
            for (int j = 0; j <= i - 1; j++) {
                if (list[j].getDonGia() > list[j + 1].getDonGia()) {
                    SanPham tmp = list[j];
                    list[j] = list[j + 1];
                    list[j + 1] = tmp;
                }
            }
        }
        xuatPhieu();
    }
};

int main() {
    
    NoiDungPhieu p;
    p.nhap();
    p.xuatPhieu();
    cout << "\n\n\n";
    cout << "So luong san pham phu hop la: " << p.task1();
    cout << "\n\n\n";
    p.task2();
    return 0;
}