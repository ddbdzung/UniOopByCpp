#include <iostream>

using namespace std;

class Complete {
private:
    int n;
    float *array;
public:
    Complete() {
        cin >> n;
        array = new float[n];
        for (int i = 0; i < n; i++) {
            cin >> array[i];
        }
    }
    float timMin();
    float timMax();
    void xuat();
    virtual ~Complete() {}
};

float Complete::timMin() {
    float tmp = array[0];
    for (int i = 1; i < n; i++) {
        if (tmp > array[i]) {
            float t = tmp;
            tmp = array[i];
            array[i] = t;
        }
    }
    return tmp;
}

float Complete::timMax() {
    float tmp = array[0];
    for (int i = 1; i < n; i++) {
        if (tmp < array[i]) {
            float t = tmp;
            tmp = array[i];
            array[i] = t;
        }
    }
    return tmp;
}

void Complete::xuat() {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
}

int main() {

    Complete a;
    a.xuat();
    cout << "\n";
    cout << "Max = " << a.timMax() << "\n";
    cout << "Min = " << a.timMin();

    return 0;
}
