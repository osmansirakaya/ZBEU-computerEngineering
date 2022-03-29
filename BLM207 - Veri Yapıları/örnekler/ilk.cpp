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
	for (i = 1; i<12; i++)
	{
		yliste->adres = (struct dugum *)malloc(sizeof(struct dugum *));
		yliste = yliste->adres;
		cout << "Veri Giriniz:"; cin >> yliste->veri;
	}
	yliste->adres = NULL;

	yliste = liste;
	i = 1;
	while (yliste != NULL)
	{
		cout << i << ". veri:" << yliste->veri << endl;
		yliste = yliste->adres;
		i++;
	}

	system("pause");
	return 0;
}
