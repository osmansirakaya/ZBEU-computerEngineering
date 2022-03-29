#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


using namespace std;
struct dugum {

	int v;
	struct dugum *sol, *sag;
}*agac=NULL, *kok=NULL, *yd=NULL, *sonkok=NULL;
void ekle(int);
void gosterinorder(struct dugum *);
void gosterpostorder(struct dugum *);

void gosterpreorder(struct dugum *);
struct dugum * dugumal()
{
	yd = (struct dugum *)malloc(sizeof(struct dugum*));
	yd->sol = NULL;
	yd->sag = NULL;
	return yd;
}


int height(struct dugum * d)
{
	
	if (d==NULL)
	return -1;
	else
	{
	int solh=height(d->sol);	
	int sagh=height(d->sag);
	
	if (solh>sagh)
		return solh+1;
		else
		return sagh+1;
	
	}

}




int main() {
	agac = NULL;
	char c='l';
	int sayi;
	while (c != 'e' || c != 'E') {

		cout <<endl<< "1. ekle" << endl; cout << "2. inorder" << endl; cout << "3. postorder" << endl; cout << "4. preorder" << endl;
		c = getchar();
		if (c == '1')
		{
			cout << endl << "Yeni Sayi Giriniz:";
			cin >> sayi;
			ekle(sayi);
		}
		if (c == '2')
		{
			agac = kok;
			gosterinorder(agac);
		}
			if (c == '3')
		{
			agac = kok;
			gosterpostorder(agac);
		}
			if (c == '4')
		{
			agac = kok;
			gosterpreorder(agac);
		}
			if (c == '5')
		{
			agac = kok;
		cout<<height(agac)<<"----"<<endl;
		}
		cout << endl<<"Cikmak istiyormusunuz-(e/h):";
		c = getchar();
	}

	return 0;

}

void ekle(int veri)
{
	agac = kok;
	if (agac == NULL)
	{
		agac = dugumal();
		agac->v = veri;
		kok = agac;
	}
	else
	{
		agac = kok;
		while (agac != NULL)
		{
			sonkok = agac;
			if (veri < agac->v) agac = agac->sol;
			else	agac = agac->sag;
		}
		if (veri < sonkok->v)
		{
			sonkok->sol = dugumal();
			sonkok = sonkok->sol;
			sonkok->v = veri;
		}

		else
		{
			sonkok->sag = dugumal();
			sonkok = sonkok->sag;
			sonkok->v = veri;
		}


	}// else


}



void gosterinorder(struct dugum * agac)
{
	if (agac == NULL) return;
	else
	{
		gosterinorder(agac->sol);
		cout << agac->v << endl;
		gosterinorder(agac->sag);
	}
}

void gosterpostorder(struct dugum * agac)
{
	if (agac == NULL) return;
	else
	{
		gosterpostorder(agac->sol);
		gosterpostorder(agac->sag);
		cout << agac->v << endl;
	}
}


void gosterpreorder(struct dugum * agac)
{
	if (agac == NULL) return;
	else
	{
		cout << agac->v << endl;
		gosterpreorder(agac->sol);
		gosterpreorder(agac->sag);
	}
}
