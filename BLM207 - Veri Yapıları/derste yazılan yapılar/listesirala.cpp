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
	printf("\nSayý Giriniz:");
	scanf("%d",&list->veri);
	printf("\nDevam etmek istiyormusunuz:");
	cev=getch();
}
list->next=NULL;
}

void listsort(struct node *h)  //bubble sort
{
struct node *list1,*list2;
int gecici;
list1=h;
list2=h->next;

   //for (list1=h;list1!=NULL;list1=list1->next;)
	while (list1!=NULL)
	{ 
	
	list2=list1->next;
		while (list2!=NULL)
		{
			if (list1->veri>list2->veri)
			{
				gecici=list1->veri;
				list1->veri=list2->veri;
				list2->veri=gecici;
				
			}
			list2=list2->next;
		}
		
		list1=list1->next;
	}
 

}


int main()
{
	int s;
struct node *ilk,*list;
ilk=(struct node *)malloc(sizeof(struct node));
printf("Sayý Giriniz:");
scanf("%d",&ilk->veri);
list=ilk;
sondanekle(list);
printf("\nListe Küçükten büyüðe siralaniyor::::");
list=ilk;
listsort(list);

list=ilk;//liste baþa getirildi
goster(list);
return 0;	
}
