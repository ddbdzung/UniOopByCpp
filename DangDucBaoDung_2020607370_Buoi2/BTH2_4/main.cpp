#include <iostream>
#include <iomanip>

using namespace std;

class Skill {
private:
    string tenDN;
    string diaChiDN;
    int soNV;
    double doanhThu;
public:
    Skill() {}
    string getTenDN() {
    	return this->tenDN;
    }
    string getDiaChiDN() {
    	return this->diaChiDN;
    }
    int getSoNV() {
    	return this->soNV;
    }
    double getDoanhThu() {
    	return this->doanhThu;
    }
    void nhap();
    virtual ~Skill() {}
};

void Skill::nhap() {
    cout << "Nhap ten DN: ";    fflush(stdin);  getline(cin, tenDN);
    cout << "Nhap dia chi DN: ";    fflush(stdin);  getline(cin, diaChiDN);
    cout << "Nhap so luong NV: ";   cin >> soNV;
    cout << "Nhap doanh thu: ";     cin >> doanhThu;
};

class List {
private:
    int n;
    Skill *l;
public:
    List() {}
    List(int n) {
        this->n = n;
        l = new Skill[n];
    }
    void nhap();
    void xuat();
};

void List::nhap() {
    for (int i = 0; i < n; i++) {
        cout << "Nhap doanh nghiep thu " << i + 1 << ":\n";
        l[i].nhap();
        cout << "\n";
    }
}

void List::xuat() {
    cout << setw(50) << "DANH SACH DOANH NGHIEP\n\n";
    cout << setw(20) << left << "Ten";
    cout << setw(20) << left << "Dia chi";
    cout << setw(10) << left << "So luong NV";
    cout << setw(15) << right << "Doanh thu" << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(20) << left << l[i].getTenDN();
        cout << setw(20) << left << l[i].getDiaChiDN();
        cout << setw(10) << left << l[i].getSoNV();
        cout << setw(15) << right << l[i].getDoanhThu() << endl;
    }
}

int main() {

    int n;
    cout << "Nhap so luong doanh nghiep: "; cin >> n;
    List p(n);
    p.nhap();
    cout << "\n";
    p.xuat();

    return 0;
}