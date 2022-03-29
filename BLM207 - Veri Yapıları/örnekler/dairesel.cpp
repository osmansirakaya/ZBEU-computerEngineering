#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

struct dugum {
	int veri;
	struct dugum *sonraki;
};
struct dugum *blist = NULL, *ylist, *gecici, *onceki, *yd;
struct dugum *dugumal()
{
	return (struct dugum *)malloc(sizeof(struct dugum));
}
void ekle(int x)
{
	ylist = blist;
	if (ylist == NULL)
	{
		blist = dugumal();
		blist->veri = x;
		blist->sonraki = blist;
		ylist = blist;

	}
	else
	{
		ylist = blist;
		while (ylist->sonraki != blist)
			ylist = ylist->sonraki;
		yd = dugumal();
		yd->veri = x;
		yd->sonraki = blist;
		ylist->sonraki = yd;
		//blist=yd liste baþýna ekleme yapýyor
	}



}

void sil(int x)
{

	ylist = blist;
	if (ylist == NULL) //liste boþ
		cout << "liste boþ" << endl;
	else
		if (ylist->sonraki == blist) //liste tek elemanlý
		{
			free(ylist);
			blist = NULL;

		}
		else
		{
			while (ylist->veri != x)
			{
				onceki = ylist;
				ylist = ylist->sonraki;
			}

			if (ylist->sonraki == blist)//son düðümde mi
			{
				onceki->sonraki = blist;
				free(ylist);
			}
			else if (ylist == blist)//ilk düðümde mi
			{
				gecici = ylist;
				while (ylist->sonraki != blist)
					ylist = ylist->sonraki;
				ylist->sonraki = blist->sonraki;
				blist = ylist->sonraki;
				free(gecici);
			}
			else
			{
				onceki->sonraki = ylist->sonraki;
				free(ylist);
			}

		}


}


void goster()
{
	ylist = blist;
	while (ylist->sonraki != blist)
	{
		cout << ylist->veri << endl;
		ylist = ylist->sonraki;

	}
	cout << ylist->veri << endl;
}
int y;
int main()
{
	char e;
	do {

		if (e == '1')
		{
			cout << endl << "veri giriniz:";
			cin >> y;
			ekle(y);
			//goster();
		}
		else if (e == '2')
		{
			cout << endl << "Silinecek veriyi giriniz:";
			cin >> y;
			sil(y);
			goster();
		}


		cout << "Ýþlem giriniz:";
		e = getch();
	} while (e != 'e');


	return 0;
}
