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

struct node* bastanekle(struct node* h)
{
struct node* newd;
newd=dugumal();
newd->next=h;

printf("\n Sayý Gir:");
scanf("%d",&newd->veri);

return newd;	
	
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
head=bastanekle(head);	
	
printf("\nDevam etmek istiyormusun:");	
cev=getch();
}while(cev!='h' && cev!='H');
	
show(head);	
	
	
	return 0;
}
