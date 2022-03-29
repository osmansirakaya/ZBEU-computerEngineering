#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
	int veri;
struct node *sol,*sag;
};

struct node *kok;

void create(void)
{
	kok=NULL;
	
}
struct node *pp;
struct node *bul(int deger)
	{
	struct node *p=kok;
	while(p!=NULL)
	{
		if (p->veri==deger) return p;
		else if (deger<p->veri) 
		{pp=p;
				p=p->sol;
		}
		else
		{	pp=p;
			p=p->sag;

		}
	}
	return NULL;
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
void ekle(int deger)
{
	struct node *aile;
	struct node *p=kok;
	while(p!=NULL)
	{
		aile=p;
		if (p->veri==deger) return;
		else if (deger<p->veri) 
				p=p->sol;
			else
				p=p->sag;
				
	}
	
	struct node *nw=(struct node *)malloc (sizeof(struct node));
	nw->veri=deger;
	nw->sol=nw->sag=NULL;
	
	if (kok==NULL) kok=nw;
	else if (deger<aile->veri)
			aile->sol=nw;
			else
			aile->sag=nw;
	
}

void gosterpre(struct node *p)
{
	if (p==NULL) return;
	printf("%d-",p->veri);
	gosterpre(p->sol);
	gosterpre(p->sag);
}
void gosterin(struct node *p)
{
	if (p==NULL) return;

	gosterin(p->sol);
	printf("%d-",p->veri);
	gosterin(p->sag);
}
void gosterpost(struct node *p)
{
	if (p==NULL) return;
	gosterpost(p->sol);
	gosterpost(p->sag);
	printf("%d-",p->veri);

}


struct node *sil(struct node *p, int deg)// baslarken kök, p'nin içinde 
{
struct node *x, *y, *temp; 
x = bul(deg);// arnýlan düðüm adresi x içerinde
if( x == NULL) { printf("Dugum mevcut degil\n"); return(p); }
else
{
/* bu kod kok (root) dugumu silmek icindir*/
if( x == p) { // girilen deger, kök'e eþit ise
printf("kok dugum siliniyor\n");
temp = x->sol; // temp'in içine saoldan en küçük ifadeyi al
y = x->sag; // kök'ün saðýn daki en büyük ifadeyi de y'ye al
//kok = temp; //kök
while(temp->sag != NULL) temp = temp->sag; // soldaký en büyük veriyi temp'e at
temp->sag=y; // temp'in saðýna kök haric aðaçtaki en büyük veriyi at
free(x); // býrak
return(temp); // aðaçtaki kök haric en büyük deðeri döndür
	
}else
{// aranan kökte deðilse

	if (x->sol!=NULL && x->sag!=NULL)//iki çocuðu varsa
	{
	temp = x->sol;
	y = x->sag;
	//kok = temp; //kök
	while(temp->sag != NULL) temp = temp->sag;
	//x->veri=temp->veri;
	temp->sag=y;
	pp->sol=temp;
	free(x);
	return(p);	
	
	}
	
	if (x->sol==NULL && x->sag!=NULL)
	{
	temp = x->sag;
	y = x->sol;// null
	
//	while(temp->sol != NULL) temp = temp->sol;// saðýn en küçüðü
//	temp->sag=y;
	
	if (pp->veri>x->veri)pp->sol=temp;
	else
		pp->sag=temp;

	free(x);
	return(p);	
	}

if (x->sol!=NULL && x->sag==NULL)
	{
	temp = x->sol;
	
	y = x->sag; //null
	//while(temp->sag != NULL) temp = temp->sag;
	//x->veri=temp->veri;
	//temp->sag=y;
	if (pp->veri>x->veri)pp->sol=temp;
	else
		pp->sag=temp;
	free(x);
	return(p);	
	
	}
if (x->sol==NULL && x->sag==NULL) //YAPRAK SÝLÝNÝYOR
	{
	temp = x;
	
	if (pp->veri>x->veri)pp->sol=NULL;
	else
		pp->sag=NULL;
	free(x);
	return(p);	
	
	}

}
}
}


int main()
{
create();
ekle(5);
ekle(3);	
ekle(7)	;
ekle(2)	;
ekle(4)	;
ekle(8);
ekle(1);
gosterpre(kok);	
printf("\n");
gosterin(kok);	
printf("\n");
gosterpost(kok);

int ara;
printf("\nAranacak ve Silinecek Sayiyi gir:");
scanf("%d",&ara);	
if (bul(ara)==NULL) printf("Agacta yok\n");
else
printf("Sayi agacta bulundu:%p\n",bul(ara));

struct node *silinen=sil(kok,ara);
if (silinen!=NULL) printf("silinen sayi-->%d\n",ara);

gosterin(kok);

	return 0;
}
