#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
	int veri;
	struct node *next; //sonraki d���m adresini tutar
};

struct node *dugumal()
{
	struct node *l;
	l=(struct node *)malloc(sizeof(struct node));
	l->next=NULL;
	return l;
}

void sonekle(struct node* h)
{
struct node* l;
l=h;//liste ba��na gelindi
while(l->next!=NULL)	
l=l->next;
//son d���me gelindi
l->next=dugumal();
l=l->next; // yeni d���me ilerlendi
printf("\n Say� Gir:");
scanf("%d",&l->veri);

	
	
}

void show(struct node* h)
{
struct node* l;
l=h;//liste ba��na gelindi
while(l!=NULL)	
{
printf("\n.Veri:%d   --->%p",l->veri,l);
l=l->next;//sonraki d���me ilerler	
}
	
}

int main()
{
struct node *list,*head;
list=NULL;//bo� durum
list=dugumal();
head=list; ///**************************
printf("\n�lk Say�y� Gir:");
scanf("%d",&list->veri);



char cev;
do 
{
sonekle(head);	
	
printf("\nDevam etmek istiyormusun:");	
cev=getch();
}while(cev!='h' && cev!='H');
	
show(head);	
	
	
	return 0;
}
