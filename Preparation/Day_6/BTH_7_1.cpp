#include <iostream>

using namespace std;

class NSX {
private:   
    string tenNSX;
    string diaChi;
public:
    string getTenNSX() {
    	return this->tenNSX;
    }
    void setTenNSX(string tenNSX) {
    	this->tenNSX = tenNSX;
    }
    string getDiaChi() {
    	return this->diaChi;
    }
    void setDiaChi(string diaChi) {
    	this->diaChi = diaChi;
    }
    void nhap() {
        cout << "Nhap ten nha san xuat: "; fflush(stdin);   getline(cin, this->tenNSX);
        cout << "Nhap dia chi nha san xuat: "; fflush(stdin);   getline(cin, this->diaChi);
    }
    void xuat() {
        cout << "Ten nha san xuat: " << tenNSX << endl;
        cout << "Dia chi nha san xuat: " << diaChi << endl;
    }
    virtual ~NSX() {}
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
        cout << "Nhap ngay/thang/nam: ";    cin >> this->d >> this->m >> this->y;
    }
    void xuat() {
        cout << "Ngay/thang/nam: " << d << "/" << m << "/" << y << endl;
    }
    virtual ~Date() {}
};

class Hang {
private:
    string tenHang;
    NSX x;
    double donGia;
public:
    Hang() {}
    Hang(string tenHang, NSX x, double donGia) {
        setTenHang(tenHang);
        setX(x);
        setDonGia(donGia);
    }
    string getTenHang() {
    	return this->tenHang;
    }
    void setTenHang(string tenHang) {
    	this->tenHang = tenHang;
    }
    NSX getX() {
    	return this->x;
    }
    void setX(NSX x) {
    	this->x = x;
    }
    double getDonGia() {
    	return this->donGia;
    }
    void setDonGia(double donGia) {
    	this->donGia = donGia;
    }
    void nhap() {
        cout << "Nhap ten hang: ";  fflush(stdin);  getline(cin, this->tenHang);
        x.nhap();
        cout << "Nhap don gia: ";   cin >> donGia;
    }
    void xuat() {
        cout << "Ten hang: " << tenHang << endl;
        x.xuat();
        cout << "Don gia: " << donGia << endl;
    }
    virtual ~Hang() {}
};

class Tivi : public Hang {
private:
    double kichThuoc;
    Date ngayNhap;
public:
    Tivi() {}
    Tivi(string tenHang, NSX x, double donGia, double kichThuoc, Date ngayNhap) : Hang(tenHang, x, donGia) {
        setKichThuoc(kichThuoc);
        setNgayNhap(ngayNhap);
    }
    double getKichThuoc() {
    	return this->kichThuoc;
    }
    void setKichThuoc(double kichThuoc) {
    	this->kichThuoc = kichThuoc;
    }
    Date getNgayNhap() {
    	return this->ngayNhap;
    }
    void setNgayNhap(Date ngayNhap) {
    	this->ngayNhap = ngayNhap;
    }
    void nhap() {
        Hang::nhap();
        cout << "Nhap kich thuoc: ";  cin >> this->kichThuoc;
        cout << "Ngay nhap - ";
        ngayNhap.nhap();
    }
    void xuat() {
        Hang::xuat();
        cout << "Kich thuoc: " << kichThuoc << endl;
        cout << "Ngay nhap - ";
        ngayNhap.xuat();
    }
    virtual ~Tivi() {}
};

int main() {

    Tivi a;
    a.nhap();
    cout << "Thong tin tivi\n";
    a.xuat();

    return 0;
}