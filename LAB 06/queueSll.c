#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int value;
    struct Queue *next;
};

void Enqueue(struct Queue *rear);
int Dequeue(struct Queue *front);

int main()
{
    struct Queue *front, *rear;
    while(1)
    {
        printf("MENU:\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Traverse\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                Enqueue(rear);
                break;

            case 2:
                Dequeue(front);
                break;

            default:
                printf("Wrong Choice!");
                break;
        }
    }
}

void Enqueue(struct Queue *rear)
{
    struct Queue *new;
    new  = (struct Queue*)malloc(sizeof(struct Queue));
    if(new==NULL)
    {
        printf("Memory was not allocated!");
        exit(0);
    }
    else
    {
        printf("Enter the value to be inserted:");
        scanf("%d",&new->value);
        new->next = rear;
        rear = new;
        printf("Element Enqueued");
    }
}

void display(struct Queue *rear,struct Queue *front)
{
    printf("The items in queue are: ");
    while(rear!=NULL)
    {
        printf("%d",rear->value);
        rear = rear->next;
    }
}
