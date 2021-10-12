#include <iostream>
#include <iomanip>

using namespace std;

class Oto {
private:
    string maOTo;
    float giaMuaMoi;
    int soNamSuDung;
    float tiLeKhauHao;
public:
    string getMaOTo() {
    	return this->maOTo;
    }
    float getGiaMuaMoi() {
    	return this->giaMuaMoi;
    }
    int getSoNamSuDung() {
    	return this->soNamSuDung;
    }
    float getTiLeKhauHao() {
    	return this->tiLeKhauHao;
    }
    void nhap();
    float getGiaTriHienTai();
    virtual ~Oto() {}
};

void Oto::nhap() {
    cout << "Nhap ma o to: ";   fflush(stdin);  getline(cin, maOTo);
    cout << "Nhap gia mua moi: ";   cin >> giaMuaMoi;
    cout << "Nhap so nam su dung: ";    cin >> soNamSuDung;
    cout << "Nhap ti le khau hao tren nam: ";   cin >> tiLeKhauHao;
}

float Oto::getGiaTriHienTai() {
    float tmp = giaMuaMoi;
    for (int i = 0; i < soNamSuDung; i++) {
        tmp = tmp * (100 - tiLeKhauHao / 100);
    }
    return tmp;
}

class DanhSach {
private:
    int n;
    Oto *ds;
public:
    DanhSach() {
        cout << "Nhap so luong xe o to trong danh sach: ";  cin >> n;
        ds = new Oto[n];
        for (int i = 0; i < n; i++) {
            ds[i].nhap();
        }
    }
    void xuat();
    virtual ~DanhSach() {}
};

void DanhSach::xuat() {
    cout << setw(50) << "DANH SACH\n\n";
    cout << setw(15) << left << "Ma o to";
    cout << setw(15) << left << "Gia mua moi";
    cout << setw(15) << left << "So nam su dung";
    cout << setw(15) << left << "Ti le khau hao";
    cout << setw(15) << right << "Gia tri hien tai" << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(15) << left << ds[i].getMaOTo();
        cout << setw(15) << left << ds[i].getGiaMuaMoi();
        cout << setw(15) << left << ds[i].getSoNamSuDung();
        cout << setw(15) << left << ds[i].getTiLeKhauHao();
        cout << setw(15) << right << ds[i].getGiaTriHienTai() << endl;
    }
}

int main() {

    DanhSach p;
    p.xuat();

    return 0;
}
