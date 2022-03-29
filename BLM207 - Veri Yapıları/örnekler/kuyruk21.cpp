#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct don
{char ad[40];
int oncelik;
int sira;
} donen;

struct node  
{
char ad[40];
int oncelik;
int sira;
struct node *next;
};
struct que
{
struct node *front;	
struct node *rear;	
};
int s=99;
void enq(struct que *k,char a[40],int o)
{
	if (k->rear==NULL)
	{
		k->rear=(struct node *)malloc(sizeof(struct node));
		strcpy(k->rear->ad,a);
		k->rear->oncelik=o;
		k->rear->sira=++s;
		k->rear->next=NULL;
		k->front=k->rear;
	}
	else
	{
		k->rear->next=(struct node *)malloc(sizeof(struct node));	
		k->rear=k->rear->next;
		strcpy(k->rear->ad,a);
		k->rear->oncelik=o;
		k->rear->sira=++s;
		k->rear->next=NULL;
	}	
}

struct don deq(struct que *k)
{struct node *temp;
int silinen;
if (k->front==NULL)
{ 
printf("Kuyruk Bos...\n");
strcpy(donen.ad,"");
donen.sira=0;
donen.oncelik=0;
return donen;
}
else
{
temp=k->front;
k->front=k->front->next;	
strcpy(donen.ad,temp->ad);
donen.oncelik=temp->oncelik;
donen.sira=temp->sira;
free(temp);
if (k->front==NULL)
{
	k->rear=k->front;
}
return donen;
}	
	
	
}



void create(struct que *k)
{

	k->front=k->rear=NULL;
}


struct que *q1,*q2,*q3,*q4;

int main()
{
q1=(struct que *)malloc(sizeof(struct que));
q2=(struct que *)malloc(sizeof(struct que));
q3=(struct que *)malloc(sizeof(struct que));
q4=(struct que *)malloc(sizeof(struct que));
create(q1);
create(q2);
create(q3);
create(q4);
char v[40];
int on;
for (int i=0;i<5;i++)
{
	printf("Hastanin Ad-soyadini Giriniz:\n");
	scanf("%s",&v);
	printf("Hastanin Önceligi Giriniz:\n");
	scanf("%d",&on);
	switch(on)
	{
	case 1: enq(q1,v,on);break;
	case 2: enq(q2,v,on);break;
	case 3: enq(q3,v,on);break;
	case 4: enq(q4,v,on);break;	
		
	}
	
}

while(q1->front!=NULL)
{deq(q1);
printf("Siradaki Hasta Ad-->%s\n",donen.ad);
printf("Siradaki Hastanin Onceligi-->%d\n\n",donen.oncelik);
printf("sira no:%d\n\n",donen.sira);
}
while(q2->front!=NULL)
{deq(q2);
printf("Siradaki Hasta Ad -->%s\n",donen.ad);
printf("Siradaki Hastanin Önceligi -->%d\n\n",donen.oncelik);
printf("sira no:%d\n\n",donen.sira);
}
while(q3->front!=NULL)
{deq(q3);
printf("Siradaki Hasta Ad -->%s\n",donen.ad);
printf("Siradaki Hastanin Onceligi -->%d\n\n",donen.oncelik);
printf("sira no:%d\n\n",donen.sira);
}
while(q4->front!=NULL)
{deq(q4);
printf("Siradaki Hasta Ad -->%s\n",donen.ad);
printf("Siradaki Hastanin Onceligi -->%d\n",donen.oncelik);
printf("sira no:%d\n\n",donen.sira);
} 



	return 0;
}
