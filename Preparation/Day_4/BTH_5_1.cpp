#include <iostream>
#include <string>
#include <sstream>
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
        cin >> this->d >> this->m >> this->y;
    }
    void xuat() {
        cout << "Ngay/thang/nam: " << getD() << '/' << getM() << '/' << getY() << endl;
    }
    //  Give Tmp pointer as NULL so overload function can be run
    string xuat(int *tmp) {
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


class DiaChi {
private:
    string diaChi;
public:
    DiaChi() {
        setDiaChi("Unknown");
    }
    string getDiaChi() {
    	return this->diaChi;
    }
    void setDiaChi(string diaChi) {
        this->diaChi = diaChi;
    }
    void nhap() {
        cout << "Nhap dia chi: ";   fflush(stdin);   getline(cin, this->diaChi);
    }
    void xuat() {
        cout << "Dia chi: " << diaChi << endl;
    }
    virtual ~DiaChi() {}
};

class NhaCungCap {
private:
    string maNCC;
    string tenNCC;
    DiaChi dc;
public:
    NhaCungCap() {
        maNCC = "Unknown";
        tenNCC = "Unknown";
    }
    string getMaNCC() {
    	return this->maNCC;
    }
    void setMaNCC(string maNCC) {
    	this->maNCC = maNCC;
    }
    DiaChi getDc() {
    	return this->dc;
    }
    string getDc(int* tmp) {
        DiaChi diaChi = getDc();
        return diaChi.getDiaChi();
    }
    void setDc(DiaChi dc) {
    	this->dc = dc;
    }
    string getTenNCC() {
    	return this->tenNCC;
    }
    void setTenNCC(string tenNCC) {
    	this->tenNCC = tenNCC;
    }
    void nhap() {
        cout << "Nhap ma nha cung cap: ";   fflush(stdin);   getline(cin, this->maNCC);
        cout << "Nhap ten nha cung cap: ";  fflush(stdin);   getline(cin, this->tenNCC);
        dc.nhap();
    }
    void xuat() {
        cout << "Ma nha cung cap: " << getMaNCC() << endl;
        cout << "Ten nha cung cap: " << getTenNCC() << endl;
        dc.xuat();
    }
    friend class DiaChi;
    virtual ~NhaCungCap() {}
};

class PhieuNhap {
private:
    string maPhieu;
    Date ngayLap;
    NhaCungCap ncc;
public:
    PhieuNhap() {
        setMaPhieu("Unknown");
    }
    NhaCungCap getNcc() {
    	return this->ncc;
    }
    void setNcc(NhaCungCap ncc) {
    	this->ncc = ncc;
    }
    string getMaPhieu() {
    	return this->maPhieu;
    }
    void setMaPhieu(string maPhieu) {
    	this->maPhieu = maPhieu;
    }
    Date getNgayLap() {
    	return this->ngayLap;
    }
    void setNgayLap(Date ngayLap) {
    	this->ngayLap = ngayLap;
    }
    /*
        tmp pointer = NULL
    */
    string getNgayLap(int* tmp) {
        Date date = getNgayLap();
        return date.xuat(tmp);
    }
    void nhap() {
        cout << "Nhap ma phieu: ";  fflush(stdin);   getline(cin, this->maPhieu);
        cout << "Nhap ngay lap phieu: ";    ngayLap.nhap();
        ncc.nhap();
    }
    void xuat() {
        cout << "Ma phieu: " << getMaPhieu() << endl;
        ngayLap.xuat();
        ncc.xuat();
    }
    friend class Date;
    friend class NhaCungCap;
    virtual ~PhieuNhap() {}
};

class MaHang {
private:
    int maHang;
    string tenHang;
    double donGia;
    long soLuong;
public:
    static int counting;
    MaHang() {
        counting++;
        maHang = counting;
        // cout << counting<< endl;
    }
    int getMaHang() {
    	return this->maHang;
    }
    void setMaHang(int maHang) {
    	this->maHang = maHang;
    }
    string getTenHang() {
    	return this->tenHang;
    }
    void setTenHang(string tenHang) {
    	this->tenHang = tenHang;
    }
    double getDonGia() {
    	return this->donGia;
    }
    void setDonGia(double donGia) {
    	this->donGia = donGia;
    }
    long getSoLuong() {
    	return this->soLuong;
    }
    void setSoLuong(long soLuong) {
    	this->soLuong = soLuong;
    }
    void nhap() {
        fflush(stdin);
        cout << "Nhap ten hang: ";  getline(cin, this->tenHang);
        cout << "Nhap don gia: ";   fflush(stdin);  cin >> this->donGia;
        cout << "Nhap so luong: ";  fflush(stdin);  cin >> this->soLuong;
    }
    void xuat() {
        cout << "Ma hang: " << getMaHang() << endl;
        cout << "Ten hang: " << getTenHang() << endl;
        cout << "Don gia: " << getDonGia() << endl;
        cout << "So luong: " << getSoLuong() << endl;
    }
    // total = donGia * soLuong
    double getTotal() {
        return getDonGia() * getSoLuong();
    }
    virtual ~MaHang() {}
};

class NoiDungPhieuNhap {
private:
    int tongMaHang;
    PhieuNhap phieu;
    MaHang *danhSach;
public:
    NoiDungPhieuNhap(int n){
        tongMaHang=n;
        danhSach = new MaHang[getTongMaHang()];
    }
    NoiDungPhieuNhap() {}
    int getTongMaHang() {
    	return this->tongMaHang;
    }
    void setTongMaHang(int tongMaHang) {
    	this->tongMaHang = tongMaHang;
    }
    double getTongTien() {
        double res = 0;
        for (int i = 0; i < getTongMaHang(); i++) {
            res += (danhSach + i)->getTotal();
        }
        return res;
    }
    void nhap() {
        phieu.nhap();
        for (int i = 0; i < getTongMaHang(); i++) {
            (danhSach + i)->nhap();
        }
    }
    void xuat() {
        cout << "                              " << "PHIEU NHAP HANG" << "                            " << endl;
        cout << left << "Ma phieu: ";
        cout << setw(28) << phieu.getMaPhieu();
        cout << right << "Ngay lap: ";
        cout << setw(28)<< phieu.getNgayLap(NULL) << endl;
        cout << left << "Ma NCC: ";
        cout << setw(30) << phieu.getNcc().getMaNCC();
        cout << right << "Ten NCC: ";
        cout << setw(29) << phieu.getNcc().getTenNCC() << endl;
        cout << "Dia chi: " << phieu.getNcc().getDc(NULL) << "\n\n";

        cout << setw(20) << left << "Ten hang";
        cout << setw(20) << right << "Don gia";
        cout << setw(20) << right << "So luong";
        cout << setw(20) << right << "Thanh tien" << endl;

        cout << setfill('-');
        cout << setw(80) << '-';
        cout << setfill(' ') << endl;

        for (int i = 0; i < getTongMaHang(); i++) {
            cout << setw(20) << left << (danhSach + i)->getTenHang();
            cout << setw(20) << right << (danhSach + i)->getDonGia();
            cout << setw(20) << right << (danhSach + i)->getSoLuong();
            cout << setw(20) << right << setprecision(4) << (danhSach + i)->getTotal() << endl;
        }
        cout << setw(60) << right << "Tong tien:";
        cout << setw(20) << right << getTongTien() << endl;
    }

    friend class PhieuNhap;
    friend class MaHang;
    virtual ~NoiDungPhieuNhap() {}
};

int MaHang::counting = 0;

int main() {

    int n;
    cout << "Nhap so luong hang can nhap: ";    cin >> n;
    NoiDungPhieuNhap p(n);

    p.nhap();   
    p.xuat();
    return 0;
}