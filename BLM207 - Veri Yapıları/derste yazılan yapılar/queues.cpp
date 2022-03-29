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

struct node * insert(struct node *h,int a)
{
	struct node *q;
	q=h;
	if (q==NULL) // KUYRUK BOŞ
	{
	q=(struct node *)malloc(sizeof(struct node));//ilk düğümü ekledim
	q->veri=a;
	q->next=NULL;
	return q;	
	}
	else
	{
		while(q->next!=NULL) // son elemana gider
		q=q->next;
		q->next=(struct node *)malloc(sizeof(struct node));//yeni düğüm
		q=q->next;
		q->veri=a;
		q->next=NULL;
		return h;
		
	}
	
}

struct node *remove(struct node *h)
{
	struct node *q,*temp;
	q=h;
	temp=h;//ilk düğüm
	
	
	if (q==NULL)
	{
	printf("\nKuyurk Boss");
	return NULL;
	}
	q=q->next;
	temp->next=NULL;
	printf("\n Silinen Veri:%d",temp->veri);
	free(temp);
	return q; //2. düğümü yeni liste başı olarak döndür
	
}

int size(struct node *h)
{
int say=0;
struct node *q;
q=h;
while(q!=NULL)
{
	say++;
	q=q->next;
}
return say;
}

int main()
{
	
int sayi;
struct node *head=NULL,*queu=NULL;

head=insert(head,6);
head=insert(head,-8);
head=insert(head,15);
head=insert(head,2);
head=insert(head,13);
head=insert(head,100);
head=insert(head,-105);
head=insert(head,-17);

queu=head;//liste başa getirildi
goster(queu);


printf( "\nkuyruk boyutu:%d",size(head));

printf("\n\n siliniyor\n");
head=remove(head);
head=remove(head);
head=remove(head);
head=remove(head);
printf( "\nkuyruk boyutu:%d",size(head));
head=remove(head);
head=remove(head);
head=remove(head);
head=remove(head);
head=remove(head);

printf( "\nkuyruk boyutu:%d",size(head));

queu=head;
goster(queu);

	getch();
	return 0;
}
