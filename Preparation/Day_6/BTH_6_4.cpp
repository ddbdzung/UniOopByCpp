#include <iostream>

using namespace std;

class Electronic {
protected:
    double congSuat;
    double dienAp;
public:
    Electronic(double congSuat, double dienAp) {
        this->congSuat = congSuat;
        this->dienAp = dienAp;
    }
    virtual ~Electronic() {}
};

class MayGiat : public Electronic {
private:
    double dungTich;
    string loai;
public:
    MayGiat(double congSuat, double dienAp, double dungTich, string loai) : Electronic(congSuat, dienAp) {
        this->dungTich = dungTich;
        this->loai = loai;
    }
    void xuat();
    virtual ~MayGiat() {}
};

void MayGiat::xuat() {
    cout << "Cong suat: " << congSuat << endl;
    cout << "Dien ap: " << dienAp << endl;
    cout << "Dung tich: " << dungTich << endl;
    cout << "Loai: " << loai << endl;
}

class TuLanh : public Electronic {
private:
    double dungTich;
    int soNgan;
public:
    TuLanh(double congSuat, double dienAp, double dungTich, int soNgan) : Electronic(congSuat, dienAp) {
        this->dungTich = dungTich;
        this->soNgan = soNgan;
    }
    void xuat();
    virtual ~TuLanh() {}
};

void TuLanh::xuat() {
    cout << "Cong suat: " << congSuat << endl;
    cout << "Dien ap: " << dienAp << endl;
    cout << "Dung tich: " << dungTich << endl;
    cout << "So ngan: " << soNgan << endl;
}

int main() {

    cout << "Thong tin cua may giay:\n";
    MayGiat a(200, 220, 8, "cua truoc");
    a.xuat();
    cout << "Thong tin cua tu lanh:\n";
    TuLanh b(150, 220, 150, 4);
    b.xuat();

    return 0;
}