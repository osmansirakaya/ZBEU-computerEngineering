#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>

struct node 
{
int veri;
struct node *next;
};
struct que
{
struct node *front;	
struct node *rear;	
};

void enq(struct que *k,int i)
{
	if (k->rear==NULL)
	{
		k->rear=(struct node *)malloc(sizeof(struct node));
		k->rear->veri=i;
		k->rear->next=NULL;
		k->front=k->rear;
	}
	else
	{
		k->rear->next=(struct node *)malloc(sizeof(struct node));	
		k->rear=k->rear->next;
		k->rear->veri=i;
		k->rear->next=NULL;
	}
	
	
}

int deq(struct que *k)
{struct node *temp;
int silinen;
if (k->front==NULL)
{ 
printf("Kuyruk Bos...\n");
return NULL;
}
else
{
temp=k->front;
k->front=k->front->next;	
silinen=temp->veri;
free(temp);
if (k->front==NULL)
{
	k->rear=k->front;
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
enq(q,5);	
enq(q,-7);
enq(q,2);
if (q->front!=NULL)printf("deleted:%d\n",deq(q));
if (q->front!=NULL)printf("deleted:%d\n",deq(q));
if (q->front!=NULL)printf("deleted:%d\n",deq(q));
if (q->front!=NULL)printf("deleted:%d\n",deq(q));
	return 0;
}
