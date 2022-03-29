#include<stdio.h>
#include<stdlib.h>

struct node 
{
int veri;
struct node *next;
};

struct node * push(struct node *st,int v)
{
	struct node *ilk=st;
	if (st==NULL)  //stack boþ
	{
		st=(struct node *)malloc(sizeof(struct node));//ilk düðüm
		st->veri=v;
		st->next=NULL;
		return st;		
		
	}
	else
	{
		if (st->next==NULL)
		{
		st->next=(struct node *)malloc(sizeof(struct node));//ilk düðüm
		st=st->next;
		st->veri=v;
		st->next=NULL;
		return ilk;		
		}
		
		while(st->next!=NULL)
		st=st->next;	
		
		st->next=(struct node *)malloc(sizeof(struct node));//ilk düðüm
		st=st->next;
		st->veri=v;
		st->next=NULL;
		return ilk;		
	
	}
	
	
	
	
}

void goster(struct node *s)
{
	while(s!=NULL)
	{
		printf("%d --->\n",s->veri);
		s=s->next;
	}
	
	
}

int pop(struct node * i)
{
	int rt;
struct node *temp;
if (i==NULL)
return -1; //stack boþþþ
else
{
	if (i->next==NULL)
	{
		rt=i->veri;
		free(i);
		return rt;
	}
	else
	{
			while(i->next->next!=NULL)
			i=i->next;
			temp=i->next; //silinecek
			rt=temp->veri;
			i->next=NULL;
			free(temp);
			return rt;
		
	}
}

	
}


int main()
{
struct node *stkk=NULL;
/*stkk=push(stkk,8); */ 
stkk=push(stkk,5); 
stkk=push(stkk,55);
stkk=push(stkk,40); 
goster(stkk);
printf("%d ---popped\n",pop(stkk));
printf("%d ---popped\n",pop(stkk));
printf("%d ---popped\n",pop(stkk));
printf("%d ---popped\n",pop(stkk));
printf("%d ---popped\n",pop(stkk));

return 0;
}

