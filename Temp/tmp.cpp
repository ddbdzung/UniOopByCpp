#include <bits/stdc++.h>
using namespace std;
class date{
	int d,m,y;
	public:
    int getY() {
        return this->y;
    }
	friend class hang;
	friend void in_ngaysx(hang a[],int n);
};
class hang{
	char tenh[20],mah[20];
	date ngaysx;
	public:
		void nhap();
		void xuat();
		friend void in_ngaysx(hang a[],int n);
};
void hang::nhap(){
	cout<<"nhap ma hang: ";fflush(stdin);gets(mah);
	cout<<"nhap ten hang :";fflush(stdin);gets(tenh);
	cout<<"nhap ngay san xuat: ";cin>>ngaysx.d>>ngaysx.m>>ngaysx.y;
}
void hang::xuat(){
	cout<<setw(5)<<left<<mah;
	cout<<setw(5)<<left<<tenh;
	cout<<setw(5)<<left<<ngaysx.d<<"/"<<ngaysx.m<<"/"<<ngaysx.y<<endl;
}
void in_ngaysx(hang a[],int n){
	for(int i=0;i<n;i++)
	if(a[i].ngaysx.getY()==2017) a[i].xuat();
}
int main(){
	hang a[20];
	int n;
	do{
		cout<<"nhap so luong hang :";cin>>n;
	}while(n<0);
	for(int i=0;i<n;i++){
		cout<<"nhap hang hoa thu"<<i+1<<endl;
		a[i].nhap();
	}
	cout<<"danh sach hang hoa sau khi nhap: \n";
	for(int i=0;i<n;i++){
		a[i].xuat();
	}
	cout<<"\n danh sach hang san xuat nam 2017 \n";
	in_ngaysx(a,n);
}
