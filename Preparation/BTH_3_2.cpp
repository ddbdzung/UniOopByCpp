#include <iostream>

using namespace std;

class NSX {
private:
    string mansx;
    string tennsx;
    string dcnsx;
public:
    void nhap();
    void xuat();
    virtual ~NSX() {}
};

void NSX::nhap() {
    cout << "Ma nha san xuat: ";    fflush(stdin);  getline(cin, mansx);
    cout << "Ten nha san xuat: ";   fflush(stdin);  getline(cin, tennsx);
    cout << "Dia chi nha san xuat: ";   fflush(stdin);  getline(cin, dcnsx);
};

int main() {

    cout << "Hi";

    return 0;
}