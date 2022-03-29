#include <conio.h>
#include <stdlib.h>
#include <iostream>
#define uz 5

using namespace std;
struct dugum {
	char v;
	struct dugum *next;
} ls;
struct dugum *on, *son, *gcc;
void ilk()
{
	on = NULL;
	son = NULL;

}

struct dugum * dugumal()
{
	return (struct dugum *)malloc(sizeof(struct dugum));
}

void ekle(char d)
{
	if (son == NULL) //kuyruk boþ yada oluþmamýþ
	{
		son = dugumal();
		son->v = d;
		son->next = NULL;
		on = son;
	}
	else
	{
		son->next = dugumal();
		son = son->next;
		son->v = d;
		son->next = NULL;
	}
}
char cikar()
{
	char ck;
	if (on == NULL)
	{
		cout << "Kuyruk Boþ" << endl;
		return 13;
	}
	else
	{
		if (on->next == NULL)
			son = NULL;
		gcc = on;
		on = on->next;
		ck = gcc -> v;
		free(gcc);
		return ck;
	}

}
int main()
{
	char c, veri;
	do
	{
		if (c == '1')
		{
			cout << endl << "Karakter Gir:";
			cin >> veri;
			ekle(veri);
		}
		if (c == '2')
			cout << cikar() << endl;
		if (c == '3')
		{
			while (on != NULL)
			{
				cout << cikar() << endl;
			}

		}

		cout << "Ýþle Gir:1 Ekle, 2 Çýkar, 3 Listele" << endl;
		c = getch();
	} while (c != 'E' || c != 'e');


	return 0;
}
