#include<iostream>
#include<stdlib.h>
using namespace std;
struct dugum
{
	int veri;
	struct dugum *adres;
};

struct dugum *yliste, *liste;

int main()
{
	liste = (struct dugum *)malloc(sizeof(struct dugum *));
	yliste = liste;
	cout << "Veri Giriniz:"; cin >> yliste->veri;
	int i;
	for (i = 1; i<10; i++)
	{
		yliste->adres = (struct dugum *)malloc(sizeof(struct dugum *));
		yliste = yliste->adres;
		cout << "Veri Giriniz:"; cin >> yliste->veri;
	}
	yliste->adres = NULL;
	int aranan;
	cout << "Aranacak Veriyi Giriniz:"; cin >> aranan;

	yliste = liste;
	while (yliste != NULL)
	{
		if (yliste -> veri == aranan)
			cout << " Bunulanan adres:" << yliste;
		yliste = yliste->adres;
	}

	system("pause");
	return 0;
}
