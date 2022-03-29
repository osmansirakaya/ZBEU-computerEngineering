#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
	int veri;
	struct node *next; //sonraki düðüm adresini tutar
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
l=h;//liste baþýna gelindi
while(l->next!=NULL)	
l=l->next;
//son düðüme gelindi
l->next=dugumal();
l=l->next; // yeni düðüme ilerlendi
printf("\n Sayý Gir:");
scanf("%d",&l->veri);

	
	
}

void show(struct node* h)
{
struct node* l;
l=h;//liste baþýna gelindi
while(l!=NULL)	
{
printf("\n.Veri:%d   --->%p",l->veri,l);
l=l->next;//sonraki düðüme ilerler	
}
	
}

int main()
{
struct node *list,*head;
list=NULL;//boþ durum
list=dugumal();
head=list; ///**************************
printf("\nÝlk Sayýyý Gir:");
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
