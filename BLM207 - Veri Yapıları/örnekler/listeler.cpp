#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{ //liste d���mlerden olusur. onun i�in buraya bir d���m tan�mlad�k.
	int veri; // veri kaydedece�imiz alan say�sal oldugu i�in int tan�mland�
	struct node *next; // sonraki d���m�n adresini tutan b�l�m. D���m�n kendi tipinde olmas� gerekiyor.
};


struct node * dugumal(){ // d���m eklemek i�in fonksiyon
	struct node *l; // local'in l si. l ile yap�lacak i�lemler
	l=(struct node*)malloc(sizeof(struct node)); //tek d���ml�k yer ay�rcak her d���m ald�g�m�zda
	l->next=NULL; // al�nan d���m�n sonraki d���m� bo� de�eri g�sterecek
	return l; // en son al�nan d���m� d�nd�r.


};

struct node *sonekle(struct node* h) 







int main(){
	struct *list; // *list listenin i�inde gezinmemiz i�indir. Tipi d���m tipidir
	struct *head; // *head listenin ba��d�r. Listeye eri�memiz i�in head'a ihtiya� vard�r.
	list=NULL; // bo� durum
	
	char cev;
	do{
		
	printf("devam etmek istiyor musun: ");
	cev=getc();	//getchar. cevab� cag�r�yor.
	}while(cev!="h" && cev!="H")
	
	
	return 0;
}










