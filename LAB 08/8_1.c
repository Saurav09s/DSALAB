#include <stdio.h>
// double ended queue
#include <stdlib.h>
#include <limits.h>
int left = -1;
int right = -1;
#define Max 5
int deq[Max];
void insert_right()
{
    int x;
    if (left == (right + 1) % Max)
    {
        printf("Doubel ended queue overflow\n");
    }

    else
    {
        printf("enter a value\n");
        scanf("%d", &x);
        if (left == -1)
        {
            left = 0;
        }
        right = (right + 1) % Max;
        deq[right] = x;
    }
}

void insert_left()
{
    int x;
    if (left == (right + 1) % Max)
    {
        printf("Double ended queue Overflow\n");
    }
    else
    {
        printf("Enter a value\n");
        scanf("%d", &x);
        if (right == -1)
        {
            right = 0;
            left = 0;
            deq[left] = x;
        }
        else
        {
            left == (left - 1) % Max;
            deq[Max] = x;
        }
    }
}

void delete_left()
{
    if (left == -1)
    {
        printf("Double ended queue underflow \n");
    }
    else
    {
        printf("The popped element is %d\n", deq[left]);
        if (left == right)
        {
            left = -1;
            right = -1;
        }
        else
        {
            left = (left + 1) % Max;
        }
    }
}

void delete_right()
{
    if (left == -1)
    {
        printf("double ended queue underflow\n");
    }
    else
    {
        printf("deleted element is %d\n", deq[right]);
        if (left == right)
        {
            left = 1;
            right = -1;
        }
        else
        {
            right = (right + 1) % Max;
        }
    }
}
void display()
{
    if (left == -1)
    {
        printf("Deque underflow\n");
    }
    else
    {
        printf("Deque elements are\n");
        for (int i = left;; i = (i + 1) % Max)
        {
            printf("%d ", deq[i]);
            if (i == right)
            {
                break;
            }
        }
    }
    printf("\n");
}

void input_restricted()
{
    int ch;
    while (1)
    {
        printf("press 1 for insert at right\npress 2 for delete st left\npress 3 for delete at right\npress 4 for display\npress 5 for quit\n");
        printf("enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_right();
            break;
        case 2:
            delete_left();
            break;

        case 3:
            delete_right();
            break;

        case 4:
            display();
            break;

        case 5:
            exit(1);
            break;

        default:
            printf("wrong choice\n");
        }
    }
}
void output_restricted()
{

    int ch;
    while (1)
    {
        printf("press 1 for insert at right\npress 2 for insert at left\npress 3 for delete at left\npress 4 for display\npress 5 for quit\n");
        printf("enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_right();
            break;
        case 2:
            insert_left();
            break;

        case 3:
            delete_left();
            break;

        case 4:
            display();
            break;

        case 5:
            exit(1);
            break;

        default:
            printf("wrong choice\n");
        }
    }
}

int main()
{

    int choice;
    while (1)
    {

        printf("press 1 for input restricted\npress 2 for output restricted\npress 3 for quit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            input_restricted();
            break;
        case 2:
            output_restricted();
            break;

        case 3:
            exit(1);
            break;

        default:
            printf("wrong choice\n");
            break;
        }
    }
}