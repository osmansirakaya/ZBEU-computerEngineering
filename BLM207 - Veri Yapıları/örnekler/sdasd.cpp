#include <stdio.h>
#include <stdlib.h>
struct ciftlist {
	char   degisken[100];
	int    degeri;
	struct ciftlist* next;
};
struct ciftlist* locate(int veri, struct ciftlist* head) {
	struct ciftlist* locate = NULL;
		struct ciftlist* temp = head;
	do {
	if(head -> degeri != veri)
	head = head -> next;
	else {
	locate = head;
	break;
}
	} while(head != temp);
	return(locate);
}

void insertAtFront(int key,struct ciftlist* head) {
	if(head == NULL) {
	head = (struct ciftlist *)malloc(sizeof(struct ciftlist));
	head -> degeri = key;
	head -> next = head;
	}
	else {
	struct ciftlist *temp = (struct ciftlist *)malloc(sizeof(struct ciftlist));
	struct ciftlist *last = head;
	temp -> degeri = key;
	while(last -> next != head) // listenin son elemaný bulunuyor.
	last = last -> next;
	
	temp -> next = head;
	last -> next = temp;
	head = temp;
	}
}
int main(int argc, char** argv) { 	
int dizi[100];
struct ciftlist *tmp;//degiskenin baslangýc adresini saklar
struct ciftlist head=(struct ciftlist)malloc(sizeof(struct ciftlist));//degisken adresleri saklar
for(int i=0; i<100; i++) dizi[i]=rand()%100;
for(int i=0; i<100; i++){
	insertAtFront(i,head);
//	if(i==0) tmp=head;//degiskenlerin baslangic adresini atadik
//	head->degeri=dizi[i]
//	head->next=tmp;
}
//struct bul head=(struct bul)malloc(sizeof(struct bul));
}
