#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{ //liste düðümlerden olusur. onun için buraya bir düðüm tanýmladýk.
	int veri; // veri kaydedeceðimiz alan sayýsal oldugu için int tanýmlandý
	struct node *next; // sonraki düðümün adresini tutan bölüm. Düðümün kendi tipinde olmasý gerekiyor.
};


struct node * dugumal(){ // düðüm eklemek için fonksiyon
	struct node *l; // local'in l si. l ile yapýlacak iþlemler
	l=(struct node*)malloc(sizeof(struct node)); //tek düðümlük yer ayýrcak her düðüm aldýgýmýzda
	l->next=NULL; // alýnan düðümün sonraki düðümü boþ deðeri gösterecek
	return l; // en son alýnan düðümü döndür.


};

struct node *sonekle(struct node* h) 







int main(){
	struct *list; // *list listenin içinde gezinmemiz içindir. Tipi düðüm tipidir
	struct *head; // *head listenin baþýdýr. Listeye eriþmemiz için head'a ihtiyaç vardýr.
	list=NULL; // boþ durum
	
	char cev;
	do{
		
	printf("devam etmek istiyor musun: ");
	cev=getc();	//getchar. cevabý cagýrýyor.
	}while(cev!="h" && cev!="H")
	
	
	return 0;
}










