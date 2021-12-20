#include <iostream>

using namespace std;

class SoPhuc
{
private:
	float thuc, ao;

public:
	SoPhuc();
	SoPhuc(float a, float b);
	SoPhuc operator+(SoPhuc x);
	SoPhuc operator-(SoPhuc x);
	friend ostream &operator<<(ostream &os, SoPhuc &obj);
};

SoPhuc::SoPhuc()
{
	this->thuc = 0;
	this->ao = 0;
}

SoPhuc::SoPhuc(float a, float b)
{
	this->thuc = a;
	this->ao = b;
}

SoPhuc SoPhuc::operator+(SoPhuc x)
{
	SoPhuc res;
	res.thuc = this->thuc + x.thuc;
	res.ao = this->ao + x.ao;
	return res;
}
SoPhuc SoPhuc::operator-(SoPhuc x)
{
	SoPhuc res;
	res.thuc = this->thuc - x.thuc;
	res.ao = this->ao - x.ao;
	return res;
}
ostream &operator<<(ostream &os, SoPhuc &obj)
{
	cout << obj.thuc << " + " << obj.ao << "i";
	return os;
}

int main()
{

	SoPhuc sp1(3, 4), sp2(5, 6);
	SoPhuc sp3 = sp1 + sp2;
	SoPhuc sp4 = sp1 - sp2;
	cout << "sp1 + sp2 = " << sp3 << endl;
	cout << "sp1 - sp2 = " << sp4 << endl;

	return 0;
}