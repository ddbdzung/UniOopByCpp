#include <iostream>
#include <iomanip>

using namespace std;

class SinhVien {
private:
    string masv;
    string hoten;
    double diemToan;
    double diemLy;
    double diemHoa;
public: 
    SinhVien() {}
    void nhap();
    void danhMuc();
    void xuat();
    double getTongDiem();
    virtual ~SinhVien() {}
};

void SinhVien::nhap() {
    cout << "Nhap ma sinh vien: ";  fflush(stdin);  getline(cin, masv);
    cout << "Nhap ho ten sinh vien: ";  fflush(stdin);  getline(cin, hoten);
    cout << "Nhap diem toan: "; cin >> diemToan;
    cout << "Nhap diem ly: "; cin >> diemLy;
    cout << "Nhap diem hoa: "; cin >> diemHoa;
}

double SinhVien::getTongDiem() {
    return (diemToan + diemLy + diemHoa);
}

void SinhVien::danhMuc() {
    cout << setw(15) << left << "MaSV";
    cout << setw(15) << left << "Ho ten";
    cout << setw(15) << left << "Diem toan";
    cout << setw(15) << left << "Diem ly";
    cout << setw(15) << left << "Diem hoa";
    cout << setw(15) << right << "Tong diem\n";
}

void SinhVien::xuat() {
    cout << setw(15) << left << masv;
    cout << setw(15) << left << hoten;
    cout << setw(15) << left << diemToan;
    cout << setw(15) << left << diemLy;
    cout << setw(15) << left << diemHoa;
    cout << setw(15) << right << getTongDiem() << endl;
}

int main() {

    SinhVien *p;
    int n;
    cout << "Nhap tong so sinh vien: "; cin >> n;
    p = new SinhVien[n];
    for (int i = 0; i < n; i++) {
        (p + i)->nhap();
    }
    p->danhMuc();
    for (int i = 0; i < n; i++) {
        (p + i)->xuat();
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (p[j].getTongDiem() > p[j + 1].getTongDiem()) {
                SinhVien tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;
            }
        }
    }
    cout << "\nSau khi sap xep:\n";
    p->danhMuc();
    for (int i = 0; i < n; i++) {
        (p + i)->xuat();
    }
    return 0;
}