#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node 
{
int veri; // 
struct node *sol,*sag; //
};

struct node *kok;
struct node *agac;

void create()
{
	agac=NULL;
	kok=NULL;
}

void ekle(int deger)
{
struct node *aile=NULL; //alt kök adresini tutmak için
struct node *tmp=kok; //işlem yaparken kullanılacak	
while(tmp!=NULL)
{
	aile=tmp;
if (tmp->veri==deger) return;
if (deger<tmp->veri) tmp=tmp->sol;
else tmp=tmp->sag;
}	
struct node *nw=(struct node *)malloc(sizeof(struct node) );
nw->veri=deger;
nw->sol=nw->sag=NULL;
if (kok==NULL)kok=nw;
else if (nw->veri<aile->veri)
aile->sol=nw;
else
aile->sag=nw;
}
void goster(struct node *n)
{
	if (n==NULL) return;
	goster(n->sol);
	printf("-%d",n->veri);
	goster(n->sag);
	
}
struct node * min(struct node *k)
{
	if (k==NULL) return NULL;
struct node *p=kok;
while(p->sol!=NULL)
{
	p=p->sol;
}
return p;
}
struct node * max(struct node *k)             
{
if (k==NULL) return NULL;
	
struct node *p=kok;

while(p->sag!=NULL)
{
	p=p->sag;
}
return p;
}


int main()
{
create();
ekle(5);
ekle(3);
ekle(7);
ekle(2);
ekle(4);
ekle(8);
goster(kok);
goster(min);
goster(max);


	
	
return 0;
}
