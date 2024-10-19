#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int *stack;
    int top;
    int SIZE;
}A;

void PUSH(int x);
int POP();
void isFull();
void isEmpty();
void Traverse();

int main()
{
    A.top=-1;
    printf("Enter the size of the stack: ");
    scanf("%d",&A.SIZE);
    A.stack=(int *)malloc(A.SIZE*sizeof(int));
    while (1)
    {
        int choice;
        printf("Main Menu\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. isFull\n");
        printf("4. isEmpty\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("Enter the value to be pushed into the stack: ");
                int x;
                scanf("%d",&x);
                PUSH(x);
                break;
            
            case 2:
                printf("The deleted value is : %d \n",POP());
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
                free(A.stack);
                exit(0);
            
            default:
                printf("Wrong Choice!\n");
                break;
        }
    }
    return 0;    
}
void PUSH(int x)
{
    if(A.top==A.SIZE-1)
    {
        printf("Stack is Full\n");
    }
    else
    {
        A.top++;
        A.stack[A.top]=x;
        printf("Element successfully pushed\n");
    }
}
int POP()
{
    if(A.top==-1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        int temp;
        temp = A.stack[A.top];
        A.top--;
        return temp;
    }
}
void isFull()
{
    if(A.top==A.SIZE-1)
    {
        printf("Stack is full\n");
    }
    else
    {
        printf("Stack is not full\n");
    }
}
void isEmpty()
{
    if(A.top==-1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack is not empty.\n");
    }
}
void Traverse()
{
    for(int i = A.top;i>=0;i--)
    {
        printf("%d ",A.stack[i]);
    }
    printf("\n");
}