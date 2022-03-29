#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node 
{
int veri;
struct node *sol,*sag;
}; // yukar�da d���m� tan�mlad�

struct node *kok;
struct node *agac;

void create()
{
	agac=NULL; 
	kok=NULL;
}

void ekle(int deger) 
{
struct node *aile=NULL; //alt k�k adresini tutmak i�in
struct node *tmp=kok; //i�lem yaparken kullan�lacak	
while(tmp!=NULL)
{
	aile=tmp;
if (tmp->veri==deger) return; // girlen deger k�k ile ayn� ise hic birsey yapma
if (deger<tmp->veri) tmp=tmp->sol; // ama girilen deger k�kten kucuk ise sola yaz
else tmp=tmp->sag;  // b�y�k ise de sa��na yaz
}	
struct node *nw=(struct node *)malloc(sizeof(struct node) ); // yeni k�k nw icin haf�zadan yer ay�r
nw->veri=deger;  // yeni k�k�m nw'nin verisine girilen de�eri ata
nw->sol=nw->sag=NULL; // �st tarafta k�k olustu, �imdi ise sa��na soluna null de�er eklendi
if (kok==NULL)kok=nw; // k�k bo� ise hic bisey yapma
else if (nw->veri<aile->veri) // girilen deger k�kten k�c�kse 
aile->sol=nw;     // de�eri k�k'�n soluna ekle
else     //  ama girilen deger k�kten b�y�kse 
aile->sag=nw;   // girilen degeri k�k'�n sag�na ekle
}
void goster(struct node *n) // dolasma fonksiyonu
{
	if (n==NULL) return; // a�ac�m bo� ise her hangi birsey yapma
	goster(n->sol);  // agac�n solun daki de�eri yaz
	printf("-%d",n->veri); // d���m� yaz
	goster(n->sag); // agac�n sag�n daki degeri yaz


}
struct node * min(struct node *k) // a�actaki min say�y� bulma 
{
	if (k==NULL) return NULL; // a�ac bo� ise bi�ey yapma
struct node *p=kok; 
while(p->sol!=NULL) // k�k'�n solu dolu ise
{
	p=p->sol; // agac�n solun daki veriyi (yani en kucuk veriyi) p'ye ata
} 
return p; // ekrana p'yi yaz;
}
struct node * max(struct node *k)   // a�actaki max say�y� bulma   
{
if (k==NULL) return NULL; // a�ac bo� ise bi�ey yapma
	
struct node *p=kok; 

while(p->sag!=NULL) // agac�n sag� dolu ise 
{
	p=p->sag; // a�ac�n en sag�nda ki veriyi(yani en b�y�k veriyi) p'ye at
}
return p; // ekrana p'yi yaz;
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
ekle(20);
ekle(8);
ekle(4);
goster(kok); // yukar�da de�erleri kar�s�k ya da s�ral� girmen fark etmez
printf("\n");
struct node * m=min(kok); 
printf ("Min:%d\n-",m->veri);
m=max(kok);
printf("Max:%d\n-",m->veri);

	
	
return 0;
}
