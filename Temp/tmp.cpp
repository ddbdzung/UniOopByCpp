#include <iostream>
#include <iomanip>

using namespace std;

class Date {
private:
    string d;
    string m;
    string y;
public:
    void nhap();
    string xuat();
    virtual ~Date() {}
};

void Date::nhap() {
    cin >> d >> m >> y;
}

string Date::xuat() {
    string res = d + "/" + m + "/" + y;
    return res;
}

class Nguoi {
protected:
	string hoTen;
	Date ngaySinh;
	string queQuan;
public:
	string getHoTen() {
		return this->hoTen;
	}
	Date getNgaySinh() {
		return this->ngaySinh;
	}
	string getQueQuan() {
		return this->queQuan;
	}
	void nhap();
	void xuat();
	virtual ~Nguoi() {}
};

void Nguoi::nhap() {
	cout << "Nhap ho ten: ";	fflush(stdin);	getline(cin, hoTen);
	cout << "Nhap ngay thang nam sinh: ";	ngaySinh.nhap();
	cout << "Nhap que quan: ";	fflush(stdin);	getline(cin, queQuan);
}

void Nguoi::xuat() {
	cout << "Ho ten: " << hoTen << endl;
	cout << "Ngay sinh: " << ngaySinh.xuat() << endl;
	cout << "Que quan: " << queQuan << endl;
}

class SinhVien : public Nguoi {
private:
	string MSV;
	string nganhHoc;
	int khoaHoc;
public:
	string getMSV() {
		return this->MSV;
	}
	string getNganhHoc() {
		return this->nganhHoc;
	}
	int getKhoaHoc() {
		return this->khoaHoc;
	}
	void nhap();
	void xuat();
	virtual ~SinhVien() {}
};

void SinhVien::nhap() {
	Nguoi::nhap();
	cout << "Nhap ma sinh vien: ";	getline(cin, MSV);
	cout << "Nhap nganh hoc: ";	getline(cin, nganhHoc);
	cout << "Nhap khoa hoc: ";	cin >> khoaHoc;
}

void SinhVien::xuat() {
	Nguoi::xuat();
	cout << "Ma sinh vien: " << MSV << endl;
	cout << "Nganh hoc: " << nganhHoc << endl;
	cout << "Khoa hoc: " << khoaHoc << endl;
}

class LopHoc {
private:
	string maLH;
	string tenLH;
	Date ngayMo;
	SinhVien *x;
	int n;
	Nguoi giaoVien;
public:
	string getMaLH() {
		return this->maLH;
	}
	string getTenLH() {
		return this->tenLH;
	}
	Date getNgayMo() {
		return this->ngayMo;
	}
	SinhVien* getX() {
		return this->x;
	}
	int getN() {
		return this->n;
	}
	Nguoi getGiaoVien() {
		return this->giaoVien;
	}
	void nhap();
	void xuat();
	virtual ~LopHoc() {}
};

void LopHoc::nhap() {
	cout << "NHAP THONG TIN LOP HOC\n\n";
	cout << "Nhap ma lop: ";	fflush(stdin);	getline(cin, maLH);
	cout << "Nhap ten lop: ";	fflush(stdin);	getline(cin, tenLH);
	cout << "Nhap ngay mo lop: ";	ngayMo.nhap();
	cout << "Nhap so luong sinh vien trong lop: ";	cin >> n;
	x = new SinhVien[n];
	cout << "Nhap giao vien giang day: ";	giaoVien.nhap();
	for (int i = 0; i < n; i++) {
		cout << "Nhap thong tin sinh vien thu " << i + 1 << ":\n";
		x[i].nhap();
	}
}

void LopHoc::xuat() {
	cout << setw(50) << right << "THONG TIN LOP HOC\n\n";
	cout << setw(15) << left << "Ma LH: " << maLH;
	cout << setw(15) << right << "Ten LH: " << tenLH << endl;
	cout << setw(15) << left << "Ngay mo: " << ngayMo.xuat() << endl;
	cout << setw(20) << left << "Ho ten giao vien: " << giaoVien.getHoTen() << endl;
	cout << setw(15) << left << "Ngay sinh: " << giaoVien.getNgaySinh().xuat();
	cout << setw(15) << right << "Que quan: " << giaoVien.getQueQuan() << endl << endl;
	
	cout << setw(15) << left << "MSV";
	cout << setw(20) << left << "Ho ten";
	cout << setw(15) << left << "Ngay sinh";
	cout << setw(15) << left << "Que quan";
	cout << setw(15) << left << "Nganh hoc";
	cout << setw(15) << left << "Khoa hoc" << endl;

	for (int i = 0; i < n; i++) {
		cout << setw(15) << left << x[i].getMSV();
		cout << setw(20) << left << x[i].getHoTen();
		cout << setw(15) << left << x[i].getNgaySinh().xuat();
		cout << setw(15) << left << x[i].getQueQuan();
		cout << setw(15) << left << x[i].getNganhHoc();
		cout << setw(15) << left << x[i].getKhoaHoc() << endl;
	}
}

int main() {

	LopHoc p;
	p.nhap();
	p.xuat();
	cout << "\n\nSo sinh vien khoa 11 cua lop hoc la: ";
	int count = 0;
	for (int i = 0; i < p.getN(); i++) {
		if (p.getX()[i].getKhoaHoc() == 11) {
			count++;
		}
	}
	cout << count << "\n\nSap xep ds sinh vien chieu tang dan khoa hoc\n\n";
	for (int i = p.getN() - 1; i >= 0; i--) {
		for (int j = 0; j <= i - 1; j++) {
			if (p.getX()[j].getKhoaHoc() > p.getX()[j + 1].getKhoaHoc()) {
				SinhVien tmp = p.getX()[j];
				p.getX()[j] = p.getX()[j + 1];
				p.getX()[j + 1] = tmp;
			}
		}
	}
	p.xuat();

	return 0;
}