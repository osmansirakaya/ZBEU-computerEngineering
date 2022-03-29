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
h=list;//ilk düğümü tut

char cev;
	printf("\nDevam etmek istiyormusunuz:");
	cev=getch();
while(cev=='e'||cev=='E')
{
list->next=(struct node *)malloc(sizeof(struct node));
list=list->next;	
	printf("\nSayı Giriniz:");
	scanf("%d",&list->veri);
	printf("\nDevam etmek istiyormusunuz:");
	cev=getch();
}
list->next=h;//dairesel liste için son  düğüm ilk düğüme bağlanacak
}



int kontrol=0;
struct node *  arasil(struct node *h,int a )
{
struct node *onceki=NULL,*liste;	

liste=h;// önşart değil ancak kullanılabilir
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
if (liste->veri==a) // son düğüm kontrol
		kontrol=1;


   if (kontrol==0)
	{
		if (liste->next==h)
		{
			if (liste->veri==a)
					{
				    free(liste);
					return NULL; // TEK DÜĞÜM VARDI LİSTE SİLİNDİ
					}
		}
		else
		{
		printf("\n Aranılan değer listede yoktur:");
		return h;
		}
	}
	else
	{
		 if (onceki==NULL) //İLK DÜĞÜMDE BULUNDU
		 {
		 	struct node *oldh=h;
		 	onceki=liste->next;//yeni ilk düğüm (eski 2. düğüm)
		 	free(liste);
		 	liste=onceki;
		 	while(liste->next!=h)
               {
               	liste=liste->next;
		        }
		        liste->next=onceki;
		 	return onceki;//yeni ilk düğüm
	 	 }
		if (liste->next==h)// son düğüm
		{
			onceki->next=h;
			free(liste);
			return h;
		}
		else //ara düğüm
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
printf("Sayı Giriniz:");
scanf("%d",&ilk->veri);
list=ilk;
sondanekle(list);
printf("\nSilinecek  sayıyı Giriniz:");
scanf("%d",&s);
list=ilk;
ilk=arasil(list,s);

list=ilk;//liste başa getirildi
goster(list);
return 0;	
}
