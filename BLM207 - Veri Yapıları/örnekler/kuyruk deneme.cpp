#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>

struct node 
{
int veri;
struct node *next;
}; // buraya kadar düðüm tanýmladý
struct que // kuyruðu tanýmlýyor
{
struct node *front;	 // kuyruðun baþý front
struct node *rear;	// kuyruðun sonu rear
}; 

void enq(struct que *k,int i) // kuyruða veri eklemek için k deðiþkeni kullanýlacak(k deðiþkeni ile que'yi kullanýcaz)
{							 // int i = dýþardan girilecek veri
	if (k->rear==NULL) // kuyruðumun sonu boþ ise
	{
		k->rear=(struct node *)malloc(sizeof(struct node)); // kurugun sonu için hafýzadan yer ayýr
		k->rear->veri=i;  	 // ve girilen veriyi kuyrugun sonuna ata
		k->rear->next=NULL;	// kuyrugun sonuna boþ bir yer oluþtur	
		k->front=k->rear;  // kuyrukta yalnýz bir veri oldugu için, o veri kuyrugun hem baþýdýr hemde sonudur
	}
	else // kurugun sonu boþ deðil ise
	{
		k->rear->next=(struct node *)malloc(sizeof(struct node)); // kurugumun son elemanýnýn arkasýna boþ yer ayýr
		k->rear=k->rear->next; // kuyrugumun sonuna, ayýrmýs oldugum boþ alaný ata
		k->rear->veri=i;   //kuyrugun sonundan ayýrmýs oldugum boþ alana girilen veriyi ekle
		k->rear->next=NULL; // ve kuyrugun en sonunu boþalt
	}
	
	
}

int deq(struct que *k) // kuyruktan veri silme(silme fronttan gerçeklesýr)
 { struct node *temp;    // gecici deðiþken temp
int silinen;
if (k->front==NULL) // kuyrugun basý boþ ise 
{ 
printf("Kuyruk Bos...\n"); 
return NULL; // iþlem yapma
}
else // kuyrugun baþý boþ deðil ise
{
temp=k->front; 			// kuytugun baþýný temp'e ata
k->front=k->front->next; // kuyrugun basýndan 2.veriyi al, kuyrugun basýna ekle(çunku en bastaký veri silinince baþý boþ kalýyor)
silinen=temp->veri;      // kuyrugun en basýnda ki veriyi silinen deðiþkenine ata
free(temp);              // temp iþlemini bitir 
if (k->front==NULL)     //kuyrugun basý boþ ise
{
	k->rear=k->front;   // kuyrukta eleman yoktur, baþýda kýçýda birdir
}
return 0;

}
}

	

