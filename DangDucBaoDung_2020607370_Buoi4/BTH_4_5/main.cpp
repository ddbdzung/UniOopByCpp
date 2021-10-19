#include <iostream>

using namespace std;

class Array {
private:
    int *value;
    int n;
public:
    Array() {
        this->n = 0;
    }
    Array(int n) {
        this->n = n;
        this->value = new int[n];
        for (int i = 0; i < n; i++) {
            cout << "Nhap gia tri a[" << i << "] = ";   cin >> this->value[i];
        }
    }
    void nhap();
    void xuat();
    ~Array() {
        this->n = 0;
        delete[] this->value;
        cout << "\nDa giai phong bo nho mang\n";
    }
};

void Array::nhap() {
    cout << "Nhap so phan tu mang: ";   cin >> n;
    value = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap gia tri a[" << i << "] = ";   cin >> value[i];
    }
}

void Array::xuat() {
    for (int i = 0; i < n; i++) {
        cout << value[i] << " ";
    }
    cout << "\n";
}

int main() {

    Array a;
    a.nhap();
    a.xuat();
    Array b(5);
    b.xuat();
    b.~Array();

    return 0;
}
