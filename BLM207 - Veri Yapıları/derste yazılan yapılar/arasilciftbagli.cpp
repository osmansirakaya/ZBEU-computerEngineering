#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
	int veri;
	struct node *next,*prev;
};
void goster(struct node *list)
{
	while(list!=NULL)
	{
	printf("\n%d \t adres=%p    onceki=%p",list->veri,list, list->prev);
	list=list->next;
	
	}
}



void sondanekle(struct node *list)
{char cev;
struct node *onceki;
	printf("\nDevam etmek istiyormusunuz:");
	cev=getch();
while(cev=='e'||cev=='E')
{
list->next=(struct node *)malloc(sizeof(struct node));
onceki=list;
list=list->next;
list->prev=onceki;	
	printf("\nSay� Giriniz:");
	scanf("%d",&list->veri);
	printf("\nDevam etmek istiyormusunuz:");
	cev=getch();
}
list->next=NULL;
list->prev=onceki;
}



int kontrol=0;
struct node * arasil(struct node *h,int a )
{
struct node *onceki=NULL,*liste;	

liste=h;// �n�art de�il ancak kullan�labilir
while(liste!=NULL)
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

   if (kontrol==0)
	{
		printf("\n Aranilan deger listede yoktur:");
		return h;
	}
	else
	{
	  if (onceki==NULL)	// ilk d���mde bulundu
		{
		onceki=liste;
		liste=liste->next; //ikinci d���me ge�ildi
		liste->prev=NULL;
		free(onceki);
		return liste;
		}
		if (liste->next==NULL)// son d���m
		{
			liste->prev=NULL;
			onceki->next=NULL;
			free(liste);
			return h;
		}
		else //ara d���m
		{
			onceki->next=liste->next;
			liste->next->prev=onceki;
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
ilk->prev=NULL;
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