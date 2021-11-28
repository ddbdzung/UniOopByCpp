#include <iostream>
#include <sstream>

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

class Khoa {
public:
    string maKhoa;
    string tenKhoa;
    string truongKhoa;
};

class Ban {
public:
    string maBan;
    string tenBan;
    Date ngayThanhLap;
};

class Truong {
protected:
    string maTruong;
    string tenTruong;
    string diaChi;
public:
    void nhap();
    void xuat();
};

void Truong::nhap() {
    cout << "Ma truong:"; fflush(stdin);  getline(cin, maTruong);
    cout << "Ten truong:"; fflush(stdin);  getline(cin, tenTruong);
    cout << "Dia chi: "; fflush(stdin);  getline(cin, diaChi);
}

void Truong::xuat() {
    cout << "Ma truong:" << maTruong << endl;
    cout << "Ten truong:" << tenTruong << endl;
    cout << "Dia chi: " << diaChi << endl;
}

class TruongDH : public Truong {
private:
    Khoa *x;
    int n;
    Ban *y;
    int m;
public:
    void nhap();
    void xuat();
};

void TruongDH::nhap() {
    Truong::nhap();
    cout << "Nhap so luong khoa: "; cin >> n;
    x = new Khoa[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap khoa thu " << i + 1 << ":\n";
        cout << "Ma khoa: "; fflush(stdin); getline(cin, x[i].maKhoa);
        cout << "Ten khoa: "; fflush(stdin);    getline(cin, x[i].tenKhoa);
        cout << "Truong khoa: "; fflush(stdin); getline(cin, x[i].truongKhoa);
    }
    cout << "Nhap so luong ban: ";  cin >> m;
    y = new Ban[m];
    for (int i = 0; i < m; i++) {
        cout << "Nhap khoa thu " << i + 1 << ":\n";
        cout << "Ma khoa: "; fflush(stdin); getline(cin, y[i].maBan);
        cout << "Ten khoa: "; fflush(stdin);    getline(cin, y[i].tenBan);
        cout << "Truong khoa: "; y[i].ngayThanhLap.typeDate();
    }
}

void TruongDH::xuat() {
    Truong::xuat();
    cout << "Co " << n << " khoa:\n";
    for (int i = 0; i < n; i++) {
        cout << "Khoa thu " << i + 1 << ":\n";
        cout << "Ma khoa: " << x[i].maKhoa << endl;
        cout << "Ten khoa: " << x[i].tenKhoa << endl;
        cout << "Truong khoa:" << x[i].truongKhoa << endl;
    }
    cout << "Co " << n << " ban:\n";
    for (int i = 0; i < m; i++) {
        cout << "Ban thu " << i + 1 << ":\n";
        cout << "Ma ban: " << y[i].maBan << endl;
        cout << "Ten ban: " << y[i].tenBan << endl;
        cout << "Ngay thanh lap:" << y[i].ngayThanhLap.getDate() << endl;
    }

}

int main() {
    TruongDH a;
    a.nhap();
    cout << endl;
    a.xuat();
}
