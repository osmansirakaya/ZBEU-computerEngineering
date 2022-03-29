#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


using namespace std;
struct dugum {

	int v;
	struct dugum *sol, *sag;
}*agac = NULL, *root = NULL, *yd = NULL, *lroot = NULL, *onceki;
void ekle(int);
void gosterinorder(struct dugum *);
void gosterpostorder(struct dugum *);

void gosterpreorder(struct dugum *);
struct dugum * dugumal()
{
	yd = (struct dugum *)malloc(sizeof(struct dugum));
	yd->sol = NULL;
	yd->sag = NULL;
	return yd;
}


int height(struct dugum * d)
{

	if (d == NULL)
		return -1;
	else
	{
		int solh = height(d->sol);
		int sagh = height(d->sag);

		if (solh>sagh)
			return solh + 1;
		else
			return sagh + 1;

	}

}

int dugumsay1(struct dugum * d)
{
	int s = 1;
	if (d == NULL)
		return 0;
	else
	{

		s += dugumsay1(d->sol);
		s += dugumsay1(d->sag);
	}
		

			return s;

}

/*int dugumsay(struct dugum * d)
{
	int k = 0;
	int s = 0;
	d = root;
	while (d != NULL)
	{
		s++;
		d = d->sol;
		s++;
		if (d->sol == NULL)
		{
			s++;
			d = d->sag;
		}
		else 	if (d->sag == NULL)
		{

			s++;
			d = d->sol;
		}

		else
		{

			s++;
			d = d->sol;
		}





	}


	d = root;
	while (d != NULL)
	{
		s++;
		d = d->sag;
		s++;
		if (d->sol == NULL)
		{
			s++;
			d = d->sag;
		}
		else 	if (d->sag == NULL)
		{

			s++;
			d = d->sol;
		}

		else
		{

			s++;
			d = d->sol;
		}





	}
	return s;
}*/

int main() {
	agac = NULL;
	char c = 'x';
	int sayi;
	while (c != 'e' || c != 'E') {

		cout << endl << "1. ekle" << endl; cout << "2. inorder" << endl; cout << "3. postorder" << endl; cout << "4. preorder" << endl;
		c = getchar();
		if (c == '1')
		{
			cout << endl << "Yeni Sayi Giriniz:";
			cin >> sayi;
			ekle(sayi);
		}
		if (c == '2')
		{
			agac = root;
			gosterinorder(agac);
		}
		if (c == '3')
		{
			agac = root;
			gosterpostorder(agac);
		}
		if (c == '4')
		{
			agac = root;
			gosterpreorder(agac);
		}
		if (c == '5')
		{
			agac = root;
			cout << height(agac) << "----" << endl;
		}
		if (c == '6')
		{
			agac = root;
			cout << dugumsay1(agac) << "----" << endl;
		}
		cout << endl << "Cikmak istiyormusunuz-(e/h):";
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
			lroot = agac;
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
