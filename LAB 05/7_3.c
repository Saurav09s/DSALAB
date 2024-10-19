#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int *CQueue=NULL, SIZE, front = -1, rear = -1;

void Enqueue(int n);
int Dequeue();
void isEmpty();
void isFull();
void Traverse();

int main()
{
    printf("Enter the size of Circular Queue: ");
    scanf("%d", &SIZE);

    int *CQueue = (int *)calloc(SIZE, sizeof(int));
    while (1)
    {
        int choice;
        printf("\nMain Menu\n");
        printf("1.Enqueue\n");
        printf("2.Dqueue\n");
        printf("3.isEmpty\n");
        printf("4.isFull\n");
        printf("5.Traverse\n");
        printf("6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter the element to be inserted:");
                int n;
                scanf("%d", &n);
                Enqueue(n);
                printf("\nElement successfully inserted");
                break;

            case 2:
                printf("Deleted element : %d", Dequeue());
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
                free(CQueue);
                exit(0);
                break;

            default:
                printf("Invalid Choice");
                break;
        }
    }

    return 0;
}

void Enqueue(int n)
{
    int temp;
    if ((rear + 1) % SIZE == front)
    {
        printf("Queue is Full!");
    }
    else if (front == -1)
    {
        front = 0;
        rear = 0;
        CQueue[rear] = n;
    }
    else
    {
        rear = (rear + 1) % SIZE;
        CQueue[rear] = n;
    }
}
int Dequeue()
{
    int temp;
    if (front == -1)
    {
        printf("Circular Queue is empty");
    }
    else if (front == rear)
    {
        temp = CQueue[front];
        front = rear = -1;
        return temp;
    }
    else
    {
        temp = CQueue[front];
        front = (front + 1) % SIZE;
        return temp;
    }
}
void isFull()
{
    if ((rear + 1) % SIZE == front)
    {
        printf("Queue is Full!");
    }
    else
    {
        printf("Queue not full!");
    }
}
void isEmpty()
{
    if (front == -1)
    {
        printf("Circular Queue is empty");
    }
    else
    {
        printf("Not empty");
    }
}
void Traverse()
{
    int i;
    if (front == -1)
    {
        printf("\n Queue is Empty.\n");
        exit(1);
    }
    else if (front <= rear)
    {
        printf("The elements present in the Queue are:");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", CQueue[i]);
        }
        printf("\n");
    }
    else
    {
        printf("The elements present in the Queue:");
        for (i = front; i <= SIZE - 1; i++)
        {
            printf("%d ", CQueue[i]);
        }
        for (i = 0; i < rear; i++)
        {
            printf("%d ", CQueue[i]);
        }
        printf("\n");
    }
}
