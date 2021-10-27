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
    cout << "Nhap ngay thang nam sinh: ";   cin >> d >> m >> y;
}

string Date::xuat() {
    string res = d + "/" + m + "/" + y;
    return res;
}

class Person {
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
    virtual ~Person() {}
};

class KySu : public Person {
private:
    string nganh;
    int namTN;
public:
    string getNganh() {
    	return this->nganh;
    }
    int getNamTN() {
        return this->namTN;
    }
    void nhap();
    void xuat();
    virtual ~KySu() {}
};

void KySu::nhap() {
    cout << "Nhap ho ten: ";    fflush(stdin);  getline(cin, Person::hoTen);
    Person::ngaySinh.nhap();
    cout << "Nhap que quan: ";  fflush(stdin);  getline(cin, Person::queQuan);
    cout << "Nhap nganh hoc: "; fflush(stdin);  getline(cin, nganh);    
    cout << "Nhap nam tot nghiep: ";    cin >> namTN;
}

void KySu::xuat() {
    cout << "Ho ten: " << hoTen << endl;
    cout << "Ngay sinh: " << ngaySinh.xuat() << endl;
    cout << "Que quan: " << queQuan << endl;
    cout << "Nganh hoc: " << nganh << endl;
    cout << "Nam tot nghiep: " << namTN << endl;
}

int main() {
    int n;
    cout << "Nhap so luong ky su: ";    cin >> n;
    KySu *p = new KySu[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin ky su thu " << i + 1 << ":\n";
        p[i].nhap();
    }
    cout << endl;
    cout << setw(20) << left << "Ho ten";
    cout << setw(10) << left << "Ngay sinh";
    cout << setw(15) << left << "Que quan";
    cout << setw(20) << left << "Nganh hoc";
    cout << setw(5) << right << "Nam TN" << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(20) << left << p[i].getHoTen();
        cout << setw(10) << left << p[i].getNgaySinh().xuat();
        cout << setw(15) << left << p[i].getQueQuan();
        cout << setw(20) << left << p[i].getNganh();
        cout << setw(5) << right << p[i].getNamTN() << endl;
    }

    int max = p[0].getNamTN();
    for (int i = 1; i < n; i++) {
        if (max < p[i].getNamTN()) {
            max = p[i].getNamTN();
        }
    }

    cout << "\nThong tin cac ky su tot nghiep gan day:\n";
    cout << setw(20) << left << "Ho ten";
    cout << setw(10) << left << "Ngay sinh";
    cout << setw(15) << left << "Que quan";
    cout << setw(20) << left << "Nganh hoc";
    cout << setw(5) << right << "Nam TN" << endl;
    for (int i = 0; i < n; i++) {
        if (p[i].getNamTN() == max) {
            cout << setw(20) << left << p[i].getHoTen();
            cout << setw(10) << left << p[i].getNgaySinh().xuat();
            cout << setw(15) << left << p[i].getQueQuan();
            cout << setw(20) << left << p[i].getNganh();
            cout << setw(5) << right << p[i].getNamTN() << endl;
        }
    }
    
    return 0;
}