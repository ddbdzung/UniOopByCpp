#include <iostream>

using namespace std;

class Vehicle {
protected:
    string brand;
    int year_made;
    string company;
public:
    void nhap() {
        cout << "Nhap nhan hieu xe: ";  fflush(stdin);   getline(cin, this->brand);
        cout << "Nhap nam san xuat: ";  cin >> year_made;
        cout << "Nhap hang san xuat: "; fflush(stdin);   getline(cin, this->company);
    }
    void xuat() {
        cout << "Nhan hieu xe: " << brand << endl;
        cout << "Nam san xuat: " << year_made << endl;
        cout << "Hang san xuat: " << company << endl;
    }
    virtual ~Vehicle() {}
};

/**
 ** If there is a function with the same signature in the derived class
 ** you can disambiguate it by adding the base class's name followed by two colons base_class::foo(...).
 ** You should note that unlike Java and C#, C++ does not have a keyword for "the base class" (super or base)
 ** since C++ supports multiple inheritance which may lead to ambiguity.
 **/

class Car : public Vehicle {
private:
    int seats;
    double capacity;
public:
    void nhap() {
        Vehicle::nhap();
        cout << "Nhap so cho ngoi: ";   cin >> seats;
        cout << "Nhap dung tich: ";     cin >> capacity;
    }
    void xuat() {
        Vehicle::xuat();
        cout << "So cho ngoi: " << seats << endl;
        cout << "Dung tich xe: " << capacity << endl;
    }
    virtual ~Car() {}
};

class Motorbike : public Vehicle {
private:
    double cc;
public:
    void nhap() {
        Vehicle::nhap();
        cout << "Nhap phan khoi: "; cin >> cc;
    }
    void xuat() {
        Vehicle::xuat();
        cout << "Phan khoi xe: " << cc << endl;
    }
    virtual ~Motorbike() {}
};

int main() {

    Car a;
    cout << "Nhap thong tin xe o to: \n";
    a.nhap();
    cout << endl;
    Motorbike b;
    cout << "Nhap thong tin xe mo to: \n";
    b.nhap();
    cout << "\nXuat thong tin xe mo to: \n";
    a.xuat();
    cout << "\nXuat thong tin xe mo to: \n";
    b.xuat();

    return 0;
}
