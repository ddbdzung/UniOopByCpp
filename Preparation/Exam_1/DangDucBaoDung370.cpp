#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class Date {
private:
    int d;
    int m;
    int y;
    string convertIntToString(const int &x) {
        stringstream ss;
        string str_x;
        ss << x;
        ss >> str_x;
        ss.str("");
        ss.clear();
        return str_x;
    }
public:
    Date() {}
    void typeDate();
    string getDate();
};

void Date::typeDate() {
    cout << "Nhap ngay/thang/nam: ";    cin >> d >> m >> y;
}

string Date::getDate() {
    string res = "";
    res = convertIntToString(d) + '/' + convertIntToString(m) + '/' + convertIntToString(y);
    return res;
}

class NguoiLap {
private:
    string maNguoiLap;
    string hoTen;
public:
    string getMaNguoiLap() {
    	return this->maNguoiLap;
    }
    void setMaNguoiLap(string maNguoiLap) {
    	this->maNguoiLap = maNguoiLap;
    }
    string getHoTen() {
    	return this->hoTen;
    }
    void setHoTen(string hoTen) {
    	this->hoTen = hoTen;
    }
    NguoiLap() {}
    void nhap();
    void xuat();
};

void NguoiLap::nhap() {
    cout << "Nhap ma nguoi lap phieu: ";   fflush(stdin);  getline(cin, maNguoiLap);
    cout << "Nhap ten nguoi lap phieu: ";   fflush(stdin);  getline(cin, hoTen);
}

void NguoiLap::xuat() {
    cout << "Nguoi lap: " << maNguoiLap << endl;
    cout << "Ho ten: " << hoTen << endl;
}

class Nha {
private:
    string maCanNha;
    double dienTich;
    long giaBan;
    string tinhTrang;
public:
    string getMaCanNha() {
    	return this->maCanNha;
    }
    void setMaCanNha(string maCanNha) {
    	this->maCanNha = maCanNha;
    }
    double getDienTich() {
    	return this->dienTich;
    }
    void setDienTich(double dienTich) {
    	this->dienTich = dienTich;
    }
    long getGiaBan() {
    	return this->giaBan;
    }
    void setGiaBan(long giaBan) {
    	this->giaBan = giaBan;
    }
    string getTinhTrang() {
    	return this->tinhTrang;
    }
    void setTinhTrang(string tinhTrang) {
    	this->tinhTrang = tinhTrang;
    }
    Nha() {}
    void nhap();
    void xuat();
};

void Nha::nhap() {
    cout << "Nhap ma can nha: "; fflush(stdin); getline(cin, maCanNha);
    cout << "Nhap dien tich: "; cin >> dienTich;
    cout << "Nhap gia ban: "; cin >> giaBan; 
    cout << "Nhap tinh trang: "; fflush(stdin); getline(cin, tinhTrang);
}

void Nha::xuat() {
    cout << "Ma can nha: " << maCanNha << endl;
    cout << "Dien tich: " << dienTich << endl;
    cout << "Gia ban: " << giaBan << endl;
    cout << "Tinh Trang: " << tinhTrang << endl;
}

class Phieu {
private:
    string maPhieu;
    Date ngayLap;
    NguoiLap x;
    Date tuNgay;
    Date denNgay;
public:
    int n;
    Nha *list;
    Phieu() {}
    void nhap();
    void xuat();
};

void Phieu::nhap() {
    cout << "Nhap ma phieu: ";   fflush(stdin);  getline(cin, maPhieu);
    cout << "Nhap ngay lap phieu: "; ngayLap.typeDate();
    x.nhap();
    cout << "Nhap khoang thoi gian:\nTu ngay: "; tuNgay.typeDate();
    cout << "Den ngay: "; denNgay.typeDate();
    cout << "Nhap so luong nha: "; cin >> n;
    list = new Nha[n];
    for (int i = 0; i < n; i++) {
        list[i].nhap();
    }
}

void Phieu::xuat() {
    cout << setw(50) << right << "THONG KE TINH TRANG BAN" << endl << endl;

    cout << setw(40) << left << "Ma phieu: " << maPhieu;
    cout << setw(40) << left << "  Ngay lap: " << ngayLap.getDate() << endl;
    cout << setw(40) << left << "Nguoi lap: " << x.getMaNguoiLap();
    cout << setw(40) << left << "  Ho ten: " << x.getHoTen() << endl;
    cout << setw(40) << left << "Tu ngay: " << tuNgay.getDate();
    cout << setw(40) << left << "  Den ngay: " << denNgay.getDate() << endl;
    cout << endl;
    cout << setw(20) << left << "Ma can";
    cout << setw(20) << left << "Dien tich";
    cout << setw(20) << left << "Gia ban";
    cout << setw(20) << left << "Tinh trang" << endl;
    long temp = 0;
    for (int i = 0; i < n; i++) {
        temp += list[i].getGiaBan();
        cout << setw(20) << left << list[i].getMaCanNha();
        cout << setw(20) << left << list[i].getDienTich();
        cout << setw(20) << left << list[i].getGiaBan();
        cout << setw(20) << left << list[i].getTinhTrang() << endl;
    }
    cout << setw(30) << left << "Tong so can ho: " << n;
    cout << setw(30) << left << "Tong gia ban: " << temp << endl << endl;
    cout << "\tTRUONG PHONG\t\tNGUOI LAP" << endl;
}

//BONUS 1;
void sua(Phieu p) {
    for (int i = 0; i < p.n; i++){
        if (p.list[i].getMaCanNha() == "K002") {
            p.list[i].setTinhTrang("Da ban");
        }
    }
}

//BONUS 2;
void sapXep(Phieu p)
{
    for (int i = p.n - 1; i >= 0; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (p.list[j].getGiaBan() > p.list[j+1].getGiaBan()) {
                Nha tmp = p.list[j];
                p.list[j] = p.list[j+1];
                p.list[j+1] = tmp;
            }
        }
    }
}

//BONUS 3; 
void dem(Phieu p)
{
    int dem = 0;
    for (int i = 0; i < p.n; i++) {
        if (p.list[i].getTinhTrang() == "Da ban") {
            dem++;
        }
    }
    cout << "So can ho da ban la: " << dem << endl;
}

int main() {

    Phieu p;
    p.nhap();
    p.xuat();
    cout << endl;
    cout << "------------------------BONUS 1------------------------" << endl;
    cout << endl;
    sua(p);
    cout << endl;
    p.xuat();
    cout << "------------------------BONUS 2------------------------" << endl;
    cout << endl;
    sapXep(p);
    cout << endl;
    p.xuat();
    cout << "------------------------BONUS 3------------------------" << endl;
    cout << endl;
    dem(p);

    return 0;
}