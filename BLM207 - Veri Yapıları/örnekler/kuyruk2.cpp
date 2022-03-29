#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
	int veri;
	struct node *next;
};
struct que{
	struct node *front;
	struct node *rear;
};
 void enq(struct que *k, int i)
 {
 	if(k->rear==NULL){
 		k->rear=(struct node *)malloc(sizeof(struct node));
 		k->rear->veri=i;
 		k->rear->next=NULL;
 		k->front=k->rear;	
	 }
	 else{
	 	k->rear->next=(struct node *)malloc(sizeof(struct node));
	 	k->rear=k->rear->next;
	 	k->rear->veri=i;
	 	k->rear->next=NULL;
	 }
	 
 int deq(struct que *k);
 {	
    struct node *tmp; 
 	int silinen;
 	if(k->front==NULL){
 		printf("kuyruk bos kardes\n");
 		 return NULL;
	 }

	 else {
	 	
	 	  tmp=k->front;
		  k->front=k->front->next;
		  silinen=tmp->veri;
		  free(tmp);
		  if(k->front==NULL){
		  	k->rear=k->front;
	   }	  
	 }
   } 	
}
void create(struct que *k){
	k->front=k->rear=NULL;
}

struct que *q;
int main(){
	
	q=(struct que *)malloc(sizeof(struct que));
	create(q);
	enq(q,2);
	enq(q,1);
	enq(q,9);
    if (q->front!=NULL)printf("deleted:%d\n",deq(q));	
	return 0;
}




 
