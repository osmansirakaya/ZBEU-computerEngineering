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

struct node* araekle(struct node* h)
{
struct node* l,*newd,*prev;
l=h;//liste baþýna gelindi
int s;
printf("\n Sayý Gir:");
scanf("%d",&s);
newd=dugumal();
newd->veri=s;
if (l->next==NULL)
{
	//listede  düðüm var
	if (s<l->veri)
	{
	newd->next=l;
	return newd;
	}else
	{
		l->next=newd;
		return h;
	}
}
else
{
	while(l!=NULL)
	{
		if (s<l->veri)
		{
			prev->next=newd;
			newd->next=l;
			return h;
		}
	prev=l; //önceki düðümü sakla
	l=l->next; // düðümü/listeyi ileri al
	}
	prev->next=newd;
	return h;	
}


	
	
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
head=araekle(head);	
	
printf("\nDevam etmek istiyormusun:");	
cev=getch();
}while(cev!='h' && cev!='H');
	
show(head);	
	
	
	return 0;
}
