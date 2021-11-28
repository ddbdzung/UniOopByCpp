#include <iostream>
#include <sstream>

using namespace std;

class Date {
private:
    int d;
    int m;
    int y;
    string convertIntToString(const int &x) {
        stringstream ss;
        string str_x;
        ss << x;
        ss >> str_x;
        ss.str("");
        ss.clear();
        return str_x;
    }
public:
    Date() {}
    void typeDate();
    string getDate();
};

void Date::typeDate() {
    cout << "Nhap ngay/thang/nam: ";    cin >> d >> m >> y;
}

string Date::getDate() {
    string res = "";
    res = convertIntToString(d) + '/' + convertIntToString(m) + '/' + convertIntToString(y);
    return res;
}

class Person {
protected:
    string name;
    Date birth;
    string address;
public:
    Person() {};
    void input();
    void output();
};

void Person::input() {
    cout << "Nhap ten: "; fflush(stdin);    getline(cin, name);
    cout << "Ngay sinh: ";  birth.typeDate();
    cout << "Nhap dia chi: "; fflush(stdin);    getline(cin, address);
}
void Person::output() {
    cout << "Ten: " << name << endl;
    cout << "Ngay sinh: " << birth.getDate() << endl;
    cout << "Dia chi: " << address << endl;
}

class School {
public:
    string name;
    Date date;
};

class Faculty {
private:
    string name;
    Date date;
    School x;
public:
    void input();
    void output();
};

void Faculty::input() {
    cout << "Nhap ten khoa: ";  fflush(stdin);  getline(cin, name);
    cout << "Ngay lap: ";   date.typeDate();
    cout << "Nhap ten truong: "; fflush(stdin);  getline(cin, x.name);
    cout << "Ngay thanh lap truong: "; x.date.typeDate();
}
void Faculty::output() {
    cout << "Ten khoa: " << name << endl;
    cout << "Ngay lap: " << date.getDate() << endl;
    cout << "Ten truong: " << x.name << endl;
    cout << "Ngay thanh lap truong: " << x.date.getDate() << endl;
}

class Student : public Person {
private:
    Faculty y;
    string Class;
    double score;
public:
    Student() {}
    void input();
    void output();
};

void Student::input() {
    Person::input();
    y.input();
    cout << "Nhap ten lop: ";   fflush(stdin);  getline(cin, Class);
    cout << "Nhap diem: ";  cin >> score;
}
void Student::output() {
    Person::output();
    y.output();
    cout << "Ten lop: " << Class << endl;
    cout << "Diem: " << score << endl;
}

int main() {
    Student a;
    a.input();
    cout << endl;
    a.output();
}
