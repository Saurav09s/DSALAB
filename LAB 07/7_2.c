#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int value;
    struct Queue *next;
}*front=NULL,*rear=NULL;

void Enqueue(int x);
int Dequeue();
void isEmpty();
void display();

int main()
{
    while(1)
    {
        printf("MENU:\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.isEmpty\n");
        printf("4.Traverse\n");
        printf("5.EXIT\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("Enter the value to be inserted:");
                int x;
                scanf("%d",&x);
                Enqueue(x);
                break;

            case 2:
                if(Dequeue()!=-1)
                {
                    printf("%d is deleted from queue\n",Dequeue());
                }
                else
                {
                    Dequeue();
                }
                break;

            case 3:
                isEmpty();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Wrong Choice!");
                break;
        }
    }
}

void Enqueue(int x)
{
    struct Queue *new;
    new  = (struct Queue*)malloc(sizeof(struct Queue));
    if(new==NULL)
    {
        printf("Memory was not allocated!\n");
        exit(0);
    }
    else
    {
        if(front==NULL)
        {
            new->value = x;
            new->next = NULL;
            front = rear = new;
        }
        else
        {
            new->value=x;
            new->next = NULL;
            rear->next = new;
            rear = new;
        }
        printf("Element Enqueued\n");
    }
}

int Dequeue()
{
    int x = -1;
    if(front == NULL)
    {
        printf("Queue is empty!");
    }
    else
    {
        struct Queue *temp;
        temp = front;
        x = front->value;
        front = front->next;
        free(temp);
    }
    return x;
}

void isEmpty()
{
    if(front==NULL)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Queue is not empty!\n");
    }
}

void display()
{
    struct Queue *p = front;
    printf("The items in queue are: ");
    while(p)
    {
        printf("%d ",p->value);
        p = p->next;
    }
    printf("\n");
}
