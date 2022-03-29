#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
	int veri;
	struct node *next;
};
void goster(struct node *list)
{
	while(list!=NULL)
	{
	printf("\n%d \t adres=%p",list->veri,list);
	list=list->next;
	
	}
}



void sondanekle(struct node *list)
{char cev;
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
list->next=NULL;
}



int kontrol=0;
struct node *  arasil(struct node *h,int a )
{
struct node *onceki=NULL,*liste;	

liste=h;// önşart değil ancak kullanılabilir
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
		printf("\n Aranılan değer listede yoktur:");
		return h;
	}
	else
	{
	  if (onceki==NULL)	// ilk düğümde bulundu
		{
		onceki=liste;
		liste=liste->next; //ikinci düğüme geçildi
		free(onceki);
		return liste;
		}
		if (liste->next==NULL)// son düğüm
		{
			onceki->next=NULL;
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
