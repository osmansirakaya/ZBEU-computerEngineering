#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
	int veri;
	struct node *next;
};
void goster(struct node *h)
{struct node *list;
list=h;
	while(list->next!=h)
	{
	printf("\n%d \t adres=%p",list->veri,list);
	list=list->next;
	}
	printf("\n%d \t adres=%p",list->veri,list);
	
}



void sondanekle(struct node *list)
{
struct node *h;
h=list;//ilk d���m� tut

char cev;
	printf("\nDevam etmek istiyormusunuz:");
	cev=getch();
while(cev=='e'||cev=='E')
{
list->next=(struct node *)malloc(sizeof(struct node));
list=list->next;	
	printf("\nSay� Giriniz:");
	scanf("%d",&list->veri);
	printf("\nDevam etmek istiyormusunuz:");
	cev=getch();
}
list->next=h;//dairesel liste i�in son  d���m ilk d���me ba�lanacak
}



int kontrol=0;
struct node *  arasil(struct node *h,int a )
{
struct node *onceki=NULL,*liste;	

liste=h;// �n�art de�il ancak kullan�labilir
while(liste->next!=h)
{
if (liste->veri==a)
	{
		kontrol=1;
		break;
	}else
	{
		onceki=liste;
		liste=liste->next;
	}

}
if (liste->veri==a) // son d���m kontrol
		kontrol=1;


   if (kontrol==0)
	{
		if (liste->next==h)
		{
			if (liste->veri==a)
					{
				    free(liste);
					return NULL; // TEK D���M VARDI L�STE S�L�ND�
					}
		}
		else
		{
		printf("\n Aran�lan de�er listede yoktur:");
		return h;
		}
	}
	else
	{
		 if (onceki==NULL) //�LK D���MDE BULUNDU
		 {
		 	struct node *oldh=h;
		 	onceki=liste->next;//yeni ilk d���m (eski 2. d���m)
		 	free(liste);
		 	liste=onceki;
		 	while(liste->next!=h)
               {
               	liste=liste->next;
		        }
		        liste->next=onceki;
		 	return onceki;//yeni ilk d���m
	 	 }
		if (liste->next==h)// son d���m
		{
			onceki->next=h;
			free(liste);
			return h;
		}
		else //ara d���m
		{
			onceki->next=liste->next;
			free(liste);
			return h;
			
		}
		
		
		
	}




}


int main()
{
	int s;
struct node *ilk,*list;
ilk=(struct node *)malloc(sizeof(struct node));
printf("Say� Giriniz:");
scanf("%d",&ilk->veri);
list=ilk;
sondanekle(list);
printf("\nSilinecek  say�y� Giriniz:");
scanf("%d",&s);
list=ilk;
ilk=arasil(list,s);

list=ilk;//liste ba�a getirildi
goster(list);
return 0;	
}
