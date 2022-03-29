#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


using namespace std;
struct dugum {

	int v;
	struct dugum *sol, *sag;
}*agac=NULL, *root=NULL, *yd=NULL, *lroot=NULL;


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
	char c='x';
	int sayi;
	while (c != 'e' || c != 'E') {

		cout <<endl<< "1. ekle" << endl; cout << "2. inorder" << endl; cout << "3. postorder" << endl; cout << "4. preorder"<< endl;cout <<"5. Yukseklik" <<endl;
		c = getchar();
		if (c == '1')
		{
			cout << endl << "Yeni Sayi Giriniz:";
			cin >> sayi;
			ekle(sayi);
			cout << endl ;
		}
		if (c == '2')
		{
			agac = root;
			cout << "----------"<<endl ;
			gosterinorder(agac);
		}
			if (c == '3')
		{
			agac = root;
			cout << "----------"<<endl ;
			gosterpostorder(agac);
		}
			if (c == '4')
		{
			agac = root;
			cout << "----------"<<endl ;
			gosterpreorder(agac);
		}
			if (c == '5')
		{
			agac = root;
		cout<<height(agac)<<"----"<<endl;
		}
		cout << endl<<"Cikmak istiyormusunuz-(e/h):";
		c = getchar();
	}

	return 0;

}

void ekle(int veri)
{
	agac = root;
	if (agac == NULL)
	{
		agac = dugumal();
		agac->v = veri;
		root = agac;
	}
	else
	{
		while (agac != NULL)
		{
			lroot = agac;//önceki düðüm parent düðüm
			if (veri < agac->v) 
			agac = agac->sol;
			else	
			agac = agac->sag;
		}
		if (veri < lroot->v)
		{
			lroot->sol = dugumal();
			lroot = lroot->sol;
			lroot->v = veri;
		}
		else
		{
			lroot->sag = dugumal();
			lroot = lroot->sag;
			lroot->v = veri;
		}


	}// else


}



void gosterinorder(struct dugum * a)
{
	if (a == NULL) return;
	else
	{
		gosterinorder(a->sol);
		cout << a->v << endl;
		gosterinorder(a->sag);
	}
}

void gosterpostorder(struct dugum * a)
{
	if (a == NULL) return;
	else
	{
		gosterpostorder(a->sol);
		gosterpostorder(a->sag);
		cout << a->v << endl;
	}
}
void gosterpreorder(struct dugum * a)
{
	if (a == NULL) return;
	else
	{
		cout << a->v << endl;
		gosterpreorder(a->sol);
		gosterpreorder(a->sag);
	}
}