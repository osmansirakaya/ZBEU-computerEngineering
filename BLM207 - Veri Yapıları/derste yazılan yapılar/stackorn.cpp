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



struct node * push(struct node *t)
{
	struct node *newd;
if (t==NULL)
{
t=(struct node *)malloc(sizeof(struct node));
printf("Say� Giriniz:");
scanf("%d",&t->veri);
t->next=NULL;	
return t;
}
else
{
newd=(struct node *)malloc(sizeof(struct node));
printf("Say� Giriniz:");
scanf("%d",&newd->veri);
newd->next=t;// her zaman yeni d���m ilk d���m
return newd;
}
	
}

struct node * pop(struct node *t)
{
	struct node *yig;
	yig=t;
	if (yig==NULL)
	{
	printf("\n yigin bos");
	return NULL; // yi�in bo�
	}
	else
	{
		yig=yig->next;
		printf("\n\n  silinen:%d",t->veri);
		free(t);
		return yig;
	}
	
	
}


int main()
{
int sayi;
struct node *top=NULL,*yigin=NULL;

top=push(top);
top=push(top);
top=push(top);
top=push(top);
printf("\nListe K���kten b�y��e siralaniyor::::");

top=pop(top);
top=pop(top);
top=pop(top);
top=pop(top);
top=pop(top);
yigin=top;//liste ba�a getirildi
goster(yigin);
return 0;	
}
