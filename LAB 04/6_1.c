#include <stdio.h>
#include <stdlib.h>

int *Stack,SIZE,top=-1;

void PUSH(int n);
int POP();
void isEmpty();
void isFull();
void Traverse();

int main()
{
    printf("Enter the size of the stack: ");
    scanf("%d",&SIZE);
    Stack=(int*)calloc(SIZE,sizeof(int));
    while(1)
    {
        int choice;
        printf("\n*******MENU*******\n");
        printf("1.PUSH");
        printf("2.POP");
        printf("3.isEmpty");
        printf("4.isFull");
        printf("5.Traverse");
        printf("6.EXIT");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                int n;
                scanf("%d",&n);
                PUSH(n);
                printf("Element successfully inserted!\n");
                break;

            case 2:
                printf("%d deleted successfully!\n",POP());
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
                free(Stack);
                exit(0);
                break;

            default:
                printf("Wrong Choice");
                break;
        }
    }

    return 0;
}

void PUSH(int n)
{
    if(top==SIZE-1)
    {
        printf("Stack is full!\n");
    }
    else
    {
        top++;
        Stack[top]=n;
    }
}

int POP()
{
    if(top==-1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        return Stack[top];
        top--;
    }
}

void isEmpty()
{
    if(top==-1)
    {
        printf("Stack is empty!");
    }
    else
    {
        printf("Stack not empty!");
    }
}

void isFull()
{
    if(top==SIZE-1)
    {
        printf("Stack is full!\n");
    }
    else 
    {
        printf("Stack is not full\n");
    }
}

void Traverse()
{
    if(top==-1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("The elements in stack are: ");
        for(int i=top;i>=0;i--)
        {
            printf("%d ",Stack[i]);
        }
        printf("\n");
    }
}