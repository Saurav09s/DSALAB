#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int size,count=0;

struct Stack
{
    int val;
    struct Stack *next;
};

void PUSH(struct Stack *Top);
int POP(struct Stack *Top);
void Display(struct Stack *Top);

int main()
{
    struct Stack *Top;

    printf("Enter the size of the stack: ");
    scanf("%d",&size);

    while (1)
    {
        printf("MENU:\n");
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.Display\n");
        printf("4.EXIT\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                PUSH(Top);
                break;
            
            case 2:
                printf("The deleted item is: %d",POP(Top));
                break;

            case 3:
                Display(Top);
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Wrong choice!");
                break;
        }
    }
}
void PUSH(struct Stack *Top)
{
    if(count==size)
    {
        printf("Stack is Full!");
        exit(0);
    }
    struct Stack *new;
    new  = (struct Stack*)malloc(sizeof(struct Stack));
    if(new==NULL)
    {
        printf("Memory was not allocated");
        exit(0);
    }
    else
    {
        printf("Enter the element to be pushed:");
        scanf("%d",&new->val);
        new->next=Top->next;
        Top->next = new;
        printf("Element successfull pushed\n");
        count++;
    }
}

int POP(struct Stack *Top)
{
    int x;
    struct Stack *Temp;
    Temp = Top;
    if(Top==NULL)
    {
        printf("\nEmpty\n");
    }
    else if(Top->next!=NULL)
    {
        x = Top->val;
        Top = Temp->next;
        free(Temp);
        return x;
    }
}

void Display(struct Stack *Top)
{
    struct Stack *temp;
    temp = Top;
    while(temp!=NULL)
    {
        printf("%d ",temp->val);
        temp = temp->next;
    }
}