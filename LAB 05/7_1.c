#include <stdio.h>
#include <stdlib.h>

struct LinearQueue{
    int *LQueue;
    int front;
    int rear;
    int SIZE;
}LQ;

void create();
void Enqueue(int x);
int Dequeue();
void isFull();
void isEmpty();
void Traverse();

int main()
{
    create();
    while (1)
    {
        int choice;
        printf("Main Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. isFull\n");
        printf("4. isEmpty\n");
        printf("5. Traverse\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                printf("Enter the element to be enqueued: ");
                int x;
                scanf("%d",&x);
                Enqueue(x);
                break;

            case 2:
                printf("The element deleted was: %d\n",Dequeue());
                break;

            case 3:
                isFull();
                break;

            case 4:
                isEmpty();
                break;

            case 5:
                Traverse();
                break;

            case 6:
                free(LQ.LQueue);
                exit(0);

            default:
                printf("Wrong Choice!\n");
                break;
        }       
    }
    return 0;    
} 

void create()
{
    printf("Enter the size of the Queue: ");
    scanf("%d",&LQ.SIZE);
    LQ.LQueue = (int *)malloc(LQ.SIZE*sizeof(int));
    LQ.front=0;
    LQ.rear=-1;
}
void Enqueue(int x)
{
    if(LQ.rear==LQ.SIZE-1)
    {
        printf("Queue is full!\n");
    }
    else
    {
        LQ.rear++;
        LQ.LQueue[LQ.rear]=x;
    }
}

int Dequeue()
{
    if(LQ.rear==LQ.front==-1||LQ.front>LQ.rear)
    {
        printf("Queue is empty!\n");
    }
    else if(LQ.rear==LQ.front&&LQ.rear!=-1)
    {
        int temp = LQ.LQueue[LQ.front];
        LQ.front++;
        return temp;
    }
    else
    {
        int temp = LQ.LQueue[LQ.front];
        LQ.front++;
        return temp;
    }
}

void isFull()
{
    if(LQ.rear==LQ.SIZE-1)
    {
        printf("Queue is full\n");
    }
    else
    {
        printf("Queue is not full\n");
    }
}

void isEmpty()
{
    if(LQ.rear==LQ.front==-1||LQ.front>LQ.rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue is not Empty\n");
    }
}

void Traverse()
{
    if(LQ.rear==LQ.front==-1||LQ.front>LQ.rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        for (int i = LQ.front; i <=LQ.rear; i++)
        {
            printf("%d ",LQ.LQueue[i]);
        }
        printf("\n");
    }
}