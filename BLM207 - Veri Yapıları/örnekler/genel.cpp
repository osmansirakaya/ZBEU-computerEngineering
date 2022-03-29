#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

struct dugum {
	int veri;
	struct dugum *sonraki;
};
struct dugum *blist = NULL, *ylist, *gecici, *onceki;
struct dugum *dugumal()
{
	return (struct dugum *)malloc(sizeof(struct dugum));
}
void bekle(int x)
{
	struct dugum *yd;
	gecici = blist;
	yd = dugumal();
	yd->veri = x;
	yd->sonraki = gecici;
	blist = yd;
}

void sekle(int x)
{
	ylist = blist;
	struct dugum *yd;
	yd = dugumal();
	yd->veri = x;
	yd->sonraki = NULL;
	while (ylist->sonraki != NULL)
	{
		ylist = ylist->sonraki;
	}
	ylist->sonraki = yd;
}
void aekle(int x) //sýralý listede
{
	ylist=blist;
	onceki = ylist;
	while (ylist->veri<x)
	{
		onceki = ylist;
		ylist = ylist->sonraki;

	}

	if (ylist == NULL)
		bekle(x);
	else if (onceki->sonraki == NULL)
		sekle(x);
	else
	{
			struct dugum *yd;
			yd = dugumal();
			yd->veri = x;
		onceki->sonraki = yd;
		yd->sonraki = ylist;

	}

}
void sondanSil()
{
	ylist=blist;
	if (ylist==NULL)
	{
	cout<<"liste boþ silme yapýlamaz"<<endl;
//	exit(1);
	}
	else
	{
		if (ylist->sonraki==NULL)
		{
		free(ylist);
		blist=NULL;
		}
		else 
		{
		ylist=blist;	
			while (ylist->sonraki != NULL)
			{	
			onceki=ylist;
			ylist=ylist->sonraki;	
			}
			onceki->sonraki=NULL;
			free(ylist);
		}
	}
}
void bastanSil()
{
		ylist = blist;
	if (ylist==NULL)
	{
	cout<<"liste boþ silme yapýlamaz"<<endl;
//	exit(1);
	}
	else
	{
	if (ylist->sonraki==NULL)
		{
		free(ylist);
		blist=NULL;
		}
		else 
		{
		blist=ylist->sonraki;
		free(ylist);
		
		}	
	}
}

void asil(int x) //sýralý listede
{
	ylist=blist;
	onceki = ylist;
	while (ylist->veri!=x)
	{
		onceki = ylist;
		ylist = ylist->sonraki;

	}

	if (ylist == blist)
		bastanSil();
	else if (onceki->sonraki == NULL)
		sondanSil();
	else
	{
		gecici=ylist;
		onceki->sonraki = gecici->sonraki;
		free(gecici);

	}

}

void tersCevir()
{
	ylist=blist;
    onceki = NULL;
    struct dugum* sonraki;
    while(ylist!=NULL)
    {
	sonraki=ylist->sonraki;
	ylist->sonraki=onceki;
	onceki=ylist;
	ylist=sonraki;
	}
blist=onceki;	
}
void sirala(struct dugum *l)
{
	struct dugum *kliste;
	int g;
	while (l != NULL)
	{
		kliste = l->sonraki;
		while (kliste != NULL)
		{
			if (l->veri > kliste->veri)
			{
				g = l->veri;
				l->veri = kliste->veri;
				kliste->veri = g;

			}
			kliste = kliste->sonraki;
		}
		l = l->sonraki;
	}

}
void goster()
{
	ylist = blist;
	while (ylist != NULL)
	{
		cout << ylist->veri << endl;
		ylist = ylist->sonraki;

	}
}
int main()
{
	ylist = blist;
	char e;
	int y;
	do
	{
		cout << "iþlem Giriniz(bekle 1, sekle 2, aekle 3,Sondansil 4, bastansil 5,Aradan sil 6,Ters:7)" << endl;
		e = getch();
		if (e == '1')
		{
			cout << "veri giriniz";
			cin >> y;
			bekle(y);
		}
		else if (e == '2')
		{
			cout << "veri giriniz";
			cin >> y;
			sekle(y);
		}
		else if (e == '3')
		{
			cout << "veri giriniz";
			cin >> y;
			aekle(y);
		}else if (e == '4')
		{
			//cout << "LÝste sonu silindi";
			sondanSil();
		}else if (e == '5')
		{
			//cout << "LÝste basindan silindi";
			bastanSil();
		}else if (e == '6')
		{
			//cout << "LÝste basindan silindi";
			int y;
			cout<<"silinecek degeri Gir:";
			cin>>y;
			asil(y);
		}else if (e == '7')
		{
			//cout << "LÝste basindan silindi";
			int y;
			cout<<"Ters Çevir Listeyi:"<<endl;
			tersCevir();
		
		}else if (e == '8')
		{
			//cout << "LÝste basindan silindi";
			int y;
			cout<<"Listeyi Sýrala:"<<endl;
			ylist=blist;
			sirala(ylist);
		
		}


		goster();
	} while (e != 'e');
	return 0;
}



