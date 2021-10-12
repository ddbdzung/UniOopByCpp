#include <iostream>

using namespace std;

class Continue {
private:
    int n;
    int *a;
public:
    Continue() {}
    Continue(int n, int *a) {
        this->n = n;
        this->a = a;
    } 
    void sapXep();
    void xuat();
    virtual ~Continue() {}
};

void Continue::sapXep() {
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

void Continue::xuat() {
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
}

int main() {

    int n;
    cout << "Nhap so luong phan tu cua mang: "; cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap so nguyen thu " << i + 1 << ": "; cin >> a[i];
    }
    Continue p(n, a);
    p.sapXep();
    cout << "\n";
    p.xuat();

    return 0;
}