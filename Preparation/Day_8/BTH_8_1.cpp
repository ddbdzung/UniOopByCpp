#include <bits/stdc++.h>

using namespace std;

class phanso
{
private:
	int tu, mau;

public:
	phanso()
	{
		tu = mau = 0;
	}

	~phanso()
	{
		tu = mau = 0;
	}

	friend istream &operator>>(istream &is, phanso &obj)
	{
		cout << "Nhap tu so: ";
		is >> obj.tu;
		cout << "Nhap mau so: ";
		is >> obj.mau;
		return is;
	}

	friend ostream &operator<<(ostream &os, phanso &obj)
	{
		os << obj.tu << "/" << obj.mau;
		return os;
	}

	phanso operator+(phanso b)
	{
		phanso c;
		c.tu = this->tu * b.mau + this->mau * b.tu;
		c.mau = this->mau * b.mau;
		return c;
	}

	phanso operator-(phanso b)
	{
		phanso c;
		c.tu = this->tu * b.mau - this->mau * b.tu;
		c.mau = this->mau * b.mau;
		return c;
	}
	double operator-()
	{
		return (double)this->tu / this->mau;
	}
	phanso operator*(phanso b)
	{
		phanso c;
		c.tu = this->tu * b.tu;
		c.mau = this->mau * b.mau;
		return c;
	}
	phanso operator/(phanso b)
	{
		phanso c;
		c.tu = this->tu * b.mau;
		c.mau = this->mau * b.tu;
		return c;
	}
};

int main()
{

	phanso a, b, c;

	cout << "Nhap phan so thu nhat: " << endl;
	cin >> a;
	cout << "Nhap phan so thu 2: " << endl;
	cin >> b;
	phanso T = a + b;
	phanso H = a - b;
	phanso TICH = a * b;
	phanso THUONG = a / b;
	ofstream f("TENFILE.txt", ios::app);
	f << a << " + " << b << " = " << T << " = " << -T << endl;
	f << a << " - " << b << " = " << H << " = " << -H << endl;
	f << a << " * " << b << " = " << TICH << " = " << -TICH << endl;
	f << a << " : " << b << " = " << THUONG << " = " << -THUONG << endl;
	f.close();
	ifstream f1("TENFILE.txt", ios::in);
	char S[200];
	while (!f1.eof())
	{
		f1.getline(S, 200);
		cout << S << endl;
	}
	f1.close();

	return 0;
}