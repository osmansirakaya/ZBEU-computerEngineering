#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>

struct node 
{
int veri;
struct node *next;
}; // buraya kadar d���m tan�mlad�
struct que // kuyru�u tan�ml�yor
{
struct node *front;	 // kuyru�un ba�� front
struct node *rear;	// kuyru�un sonu rear
}; 

void enq(struct que *k,int i) // kuyru�a veri eklemek i�in k de�i�keni kullan�lacak(k de�i�keni ile que'yi kullan�caz)
{							 // int i = d��ardan girilecek veri
	if (k->rear==NULL) // kuyru�umun sonu bo� ise
	{
		k->rear=(struct node *)malloc(sizeof(struct node)); // kurugun sonu i�in haf�zadan yer ay�r
		k->rear->veri=i;  	 // ve girilen veriyi kuyrugun sonuna ata
		k->rear->next=NULL;	// kuyrugun sonuna bo� bir yer olu�tur	
		k->front=k->rear;  // kuyrukta yaln�z bir veri oldugu i�in, o veri kuyrugun hem ba��d�r hemde sonudur
	}
	else // kurugun sonu bo� de�il ise
	{
		k->rear->next=(struct node *)malloc(sizeof(struct node)); // kurugumun son eleman�n�n arkas�na bo� yer ay�r
		k->rear=k->rear->next; // kuyrugumun sonuna, ay�rm�s oldugum o� alan� ata
		k->rear->veri=i;   //kuyrugun sonundan ay�rm�s oldugum bo� alana girilen veriyi ekle
		k->rear->next=NULL; // ve kuyrugun en sonunu bo�alt
	}
	
	
}

int deq(struct que *k) // kuyruktan veri silme i�lemi(silme fronttan ger�ekles�r)
{struct node *temp;    // gecici de�i�ken temp
int silinen;
if (k->front==NULL) // kuyrugun bas� bo� ise 
{ 
printf("Kuyruk Bos...\n"); 
return NULL; 
}
else // kuyrugun ba�� bo� de�il ise
{
temp=k->front; 			// kuyrugun ba��n� temp'e ata
k->front=k->front->next; // kuyrugun bas�ndan 2.veriyi al, kuyrugun bas�na ekle(�unku en bastak� veri silinince ba�� bo� kal�yor)
silinen=temp->veri;      // kuyrugun en bas�nda ki veriyi silinen de�i�kenine ata
free(temp);              // temp i�lemini bitir 
if (k->front==NULL)     //kuyrugun bas� bo� ise
{
	k->rear=k->front;   // kuyrukta eleman yoktur, ba��da k���da ayn�d�r
}
return silinen; 
}	
	
	
}



void create(struct que *k)
{

	k->front=k->rear=NULL;
}


struct que *q;

int main()
{
q=(struct que *)malloc(sizeof(struct que));
create(q);
enq(q,1);	
enq(q,2);
enq(q,3);
enq(q,4);
enq(q,5);
enq(q,6);
if (q->front!=NULL)printf("eklenen:%d\n",enq(q));
if (q->front!=NULL)printf("eklenen:%d\n",deq(q));
if (q->front!=NULL)printf("eklenen:%d\n",deq(q));
if (q->front!=NULL)printf("eklenen:%d\n",deq(q));
if (q->front!=NULL)printf("eklenen:%d\n",deq(q));
if (q->front!=NULL)printf("eklenen:%d\n",deq(q));

	return 0;
}
