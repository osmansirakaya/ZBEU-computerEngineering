#include <stdio.h>

#define QUEUESIZE 5

int Queue[QUEUESIZE - 1];
int frontElement = -1, rearElement = -1;

void enQueue(int item)
{
    if(rearElement > 4)
    {
        printf("\n *********************************************\n");
        printf("\n Your Queue is Full, pls dequeue an element... ");
    }
    else
    {
        if(frontElement == -1)
        {
            frontElement = frontElement + 1;
        }
        rearElement = rearElement + 1;
        Queue[rearElement] = item;
    }
}

void deQueue()
{
    if(frontElement == -1 || frontElement > rearElement)
    {
        printf("\n *********************************************\n");
        printf("\n Your Queue is Already Empty, Please Enqueue an item");
    }
    else
    {
        frontElement = frontElement + 1;
    }

}

void printQueue()
{
    int i;
    if(frontElement == -1 || frontElement > rearElement)
    {
        printf("\n *********************************************\n");
        printf("\n Your Queue is Already Empty, Please Enqueue an item");
    }
    else
    {
        for( i = rearElement; i >= frontElement; i--)
        {
            printf(" %d \n", Queue[i]);
        }
    }
}
int main()
{
    int choise, item;
    while(1 == 1)
    {
        printf("\n 1- Enqueue element ...");
        printf("\n 2- Dequeue element ...");
        scanf("%d", &choise);

        switch(choise)
        {
            case 1:
                printf("\n Which number do you want to enqueue? ");
                scanf("%d", &item);
                enQueue(item);
                printQueue();
                break;
            case 2:
                deQueue();
                printQueue();
                break;
        }

    }
    return 0;
}
