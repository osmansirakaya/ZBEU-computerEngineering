#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node* start = NULL;
struct node* temp = NULL;
struct node* q = NULL;

void yazdir()
{
	q = start;
	while(q->next != NULL)
	{ 
	printf("%d->", q->data);
	q=q->next;
	}
	printf("%d", q->data);
}
void basaEkle(int basa)
{ struct node *basaGelecek = (struct node*)malloc(sizeof(struct node));

 basaGelecek->data = basa;
 basaGelecek->next = start;
 start = basaGelecek;
}


void sondanSil()
{
	q=start;
	while(q->next->next != NULL)
	{
		q = q->next;
	}
	free(q->next);
	q->next =NULL;
}
void bastanSil(){
	struct node* ikinci=NULL;
	ikinci = start->next;
	free(start);
	start = ikinci;
}


int main()
{
	int secim,basa;
	while(1==1){
	
		printf("\n1-Basa Eleman Ekle");
		printf("\n2- sondan Eleman sil");
		printf("\n3- bastan  Eleman sil");
		printf("\n Yapacak Ýslemi Secin");
		scanf("%d",&secim);
		if(sondanSil== bastanSil){
			printf("listenin basý sonu aynidir!",secim);
		}
		else{
		
	
		switch(secim){
		
		case 1:
		     printf("\n Basa Eklemek Ýstediginiz Elemaný Girin:");
			 scanf("%d",&basa);
			 basaEkle(basa);
			 yazdir();
			 break;
	     
			 case 2:
			 	sondanSil();
			 	yazdir();
			 	break;
			 	case 3:
			 		bastanSil();
			 		yazdir();
			 		break;}
			 	
		}
	}
}



