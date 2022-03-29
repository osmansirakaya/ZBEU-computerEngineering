#include<iostream>
#include<stdlib.h>
using namespace std;
struct dugum
{
	int veri;
	struct dugum *adres;
};

void goster(struct dugum * l)
{

	while (l != NULL)
	{
		cout << " Bunulanan adres:" << l->veri << endl;
		l = l->adres;
	}

}

void sil(struct dugum * l, int ara)
{
	struct dugum * onceki;
	onceki = l;
	while (l != NULL)
	{
		if (l->veri == ara)
		{
			onceki->adres = l->adres;
			free(l);
		}

		onceki = l;
		l = l->adres;
	}



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
	int aranan;
	cout << "Aranan Veriyi Giriniz:"; cin >> aranan;

	yliste = liste;
	sil(yliste,aranan);
	yliste = liste;
	goster(yliste);

	system("pause");
	return 0;
}
