#include<iostream>
#include<stdlib.h>
using namespace std;
struct dugum
{
	int veri;
	struct dugum *adres;
};
void sirala(struct dugum *l)
{
	struct dugum *kliste;
	int g;
	while (l != NULL)
	{
		kliste = l->adres;
		while (kliste != NULL)
		{
			if (l->veri > kliste->veri)
			{
				g = l->veri;
				l->veri = kliste->veri;
				kliste->veri = g;

			}
			kliste = kliste->adres;
		}
		l = l->adres;
	}

}

struct dugum * enkucuk(struct dugum * l)
{
	struct dugum *yl,*ek;
	yl = l;
	int enkucuk=yl->veri;
	ek = yl;
	while (yl != NULL)
	{
		if (yl->veri < enkucuk)
		{
			enkucuk = yl -> veri;
			ek = yl;
		}
		yl = yl->adres;
	}
	return ek;

}

struct dugum *yliste, *liste,*kliste,*gliste;

int main()
{
	liste = (struct dugum *)malloc(sizeof(struct dugum *));
	yliste = liste;
	cout << "Veri Giriniz:"; cin >> yliste->veri;
	int i;
	for (i = 1; i<5; i++)
	{
		yliste->adres = (struct dugum *)malloc(sizeof(struct dugum *));
		yliste = yliste->adres;
		cout << "Veri Giriniz:"; cin >> yliste->veri;
	}
	yliste->adres = NULL;
	yliste = liste;
	sirala(yliste);
	yliste = liste;
	while (yliste != NULL)
	{
		cout << " Bunulanan adres:" << yliste->veri<<endl;
		yliste = yliste->adres;
	}

	system("pause");
	return 0;
}
