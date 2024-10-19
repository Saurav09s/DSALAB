#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int *LQueue=NULL,SIZE,front = -1,rear = -1;

void Enqueue();
int Dequeue();
void isEmpty();
void isFull();
void Traverse();

int main()
{
    printf("Enter the size:");
    scanf("%d",&SIZE);
    LQueue = (int*)malloc(SIZE*sizeof(int));
    int choice;
    while(1)
    {
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                Enqueue();
                break;

            case 2:
                printf("Element %d deleted successfully",Dequeue());
                printf("\n");
                break;

            case 3:
                isEmpty();
                break;

            case 4:
                isFull();
                break;

            case 5:
                Traverse();
                break;

            case 6:
                free(LQueue);
                exit(0);
                break;

            default:
                printf("Wrong Choice");
                break;
        }
    }

    return 0;
}

void Enqueue()
{
    if(rear==SIZE-1)
    {
        printf("Queue is full\n");
    }
    else
    {
        int x;
        printf("Enter the element to be inserted: ");
        scanf("%d",&x);
        front=0;
        LQueue[++rear]=x;
        printf("Element successfully inserted \n");
    }
}

int Dequeue()
{
    int temp;
    if(front==rear==-1||front>rear)
    {
        printf("Queue is empty \n");
    }
    else if(front==rear)
    {
        temp=LQueue[front];
        front=rear=-1;
        return temp;
    }
    else
    {
        temp=LQueue[front];
        front++;
        return temp;
    }
}

void isEmpty()
{
    if(front==rear==-1)
    {
        printf("Queue is empty \n");
    }
    printf("\n");
}

void isFull()
{
    if(rear==SIZE-1)
    {
        printf("Queue is full \n");
    }
    printf("\n");
}

void Traverse()
{
    printf("Elements present in the linear Queue are: ");
    for(int i = front;i<=rear;i++)
    {
        printf("%d ",LQueue[i]);
    }
    printf("\n");
}




