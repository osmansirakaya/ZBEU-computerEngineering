#include <conio.h>
#include <iostream>
using namespace std;
#define uz 8
struct yigin {
	int ust;
	int veri[uz];
};
int cikan;
struct yigin ekle(struct yigin y,int v)
{
	if (y.ust==uz-1)
	{
		cout<<"yigin dolu eklenemez";
		return y;
	}
	else
	{
		y.ust++;
		y.veri[y.ust]=v;
	return y;	
	}
	
}
struct yigin cikar(struct yigin y)
{
if (y.ust==0)
	{
		cout<<"yigin bostur veri cikarilamaz";
		return y;
	}
	else
	{
		cikan=y.veri[y.ust];
		y.ust--;
	return y;	
	}	
}









int main()
{
	struct yigin x,yx;
	x.ust=0;
	yx.ust=0;
	int veri,a;
	char c;
	do 
	{
	
		if (c=='1')
		{
			cout<<"Veri Giriniz:";
			cin>>veri;
			x=ekle(x,veri);
		//	yx=x;
		}
		if (c=='2')
			{
			x=cikar(x);
			cout<<"--:"<<cikan<<endl;
			
			}
		if (c=='3')
		{
			while (x.ust!=0)
			{
				x=cikar(x);
				cout<<cikan<<endl;
				yx=ekle(yx,cikan);
			}
			
		}
		
			if (c=='4')
		{
		int kont=0;	
		cout<<"Aranılacak Veriyi Giriniz:";
			cin>>a;
			while (x.ust!=0)
			{
				x=cikar(x);
			if (a==cikan)
			{
				kont++;
				cout<<"Aranılan Veri Yiginda bulundu";
			}
			}
			if (kont==0)
			cout<<"Aranılan Veri yiginda yok";
		}
		
	//cout<<"Çıkmak istiyormusunuz";
	cout<<endl<<"Ekle(1),Cikart(2),Goruntule(3),ARA(4)"<<endl;	
	c=getch();	
	}while(c!='e' || c!='E');
	
return 0;	
}
