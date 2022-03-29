#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node 
{
int veri;
struct node *sol,*sag;
}; // yukarıda düğümü tanımladı

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
if (tmp->veri==deger) return; // girlen deger kök ile aynı ise hic birsey yapma
if (deger<tmp->veri) tmp=tmp->sol; // ama girilen deger kökten kucuk ise sola yaz
else tmp=tmp->sag;  // büyük ise de sağına yaz
}	
struct node *nw=(struct node *)malloc(sizeof(struct node) ); // yeni kök nw icin hafızadan yer ayır
nw->veri=deger;  // yeni köküm nw'nin verisine girilen değeri ata
nw->sol=nw->sag=NULL; // üst tarafta kök olustu, şimdi ise sağına soluna null değer eklendi
if (kok==NULL)kok=nw; // kök boş ise hic bisey yapma
else if (nw->veri<aile->veri) // girilen deger kökten kücükse 
aile->sol=nw;     // değeri kök'ün soluna ekle
else     //  ama girilen deger kökten büyükse 
aile->sag=nw;   // girilen degeri kök'ün sagına ekle
}
void goster(struct node *n) // dolasma fonksiyonu
{
	if (n==NULL) return; // ağacım boş ise her hangi birsey yapma
	goster(n->sol);  // agacın solun daki değeri yaz
	printf("-%d",n->veri); // düğümü yaz
	goster(n->sag); // agacın sagın daki degeri yaz


}
struct node * min(struct node *k) // ağactaki min sayıyı bulma 
{
	if (k==NULL) return NULL; // ağac boş ise bişey yapma
struct node *p=kok; 
while(p->sol!=NULL) // kök'ün solu dolu ise
{
	p=p->sol; // agacın solun daki veriyi (yani en kucuk veriyi) p'ye ata
} 
return p; // ekrana p'yi yaz;
}
struct node * max(struct node *k)   // ağactaki max sayıyı bulma   
{
if (k==NULL) return NULL; // ağac boş ise bişey yapma
	
struct node *p=kok; 

while(p->sag!=NULL) // agacın sagı dolu ise 
{
	p=p->sag; // ağacın en sagında ki veriyi(yani en büyük veriyi) p'ye at
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
goster(kok); // yukarıda değerleri karısık ya da sıralı girmen fark etmez
printf("\n");
struct node * m=min(kok); 
printf ("Min:%d\n-",m->veri);
m=max(kok);
printf("Max:%d\n-",m->veri);

	
	
return 0;
}
