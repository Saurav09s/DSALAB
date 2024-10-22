#include <stdio.h>
#include <stdlib.h>

int size,count=0;

struct Stack
{
    int val;
    struct Stack *next;
}*Top=NULL;

void PUSH(int x);
int POP();
void isEmpty();
void Display();

int main()
{
    printf("Enter the size of the stack: ");
    scanf("%d",&size);

    while (1)
    {
        printf("MENU:\n");
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.isEmpty\n");
        printf("4.Display\n");
        printf("5.EXIT\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter the element to be pushed:- ");
                int x;
                scanf("%d",&x);
                PUSH(x);
                break;
            
            case 2:
                printf("%d deleted from the stack\n",POP());
                break;

            case 3:
                isEmpty();
                break;
                
            case 4:
                Display();
                break;

            case 5:
                exit(0);
                break;

            default:
                printf("Wrong choice!");
                break;
        }
    }
}
void PUSH(int x)
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
        new->val=x;
        new->next=Top;
        Top = new;
        printf("Element successfully pushed\n");
        count++;
    }
}

int POP()
{
    int x=-1;
    struct Stack *Temp;
    if(Top==NULL)
    {
        printf("\nEmpty\n");
    }
    else
    {
        Temp = Top;
        Top = Top->next;
        x = Temp->val;
        free(Temp);
    }
    return x;
}

void isEmpty()
{
    if(Top==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack is not empty");
    }
}

void Display()
{
    struct Stack *temp;
    temp = Top;
    while(temp!=NULL)
    {
        printf("%d ",temp->val);
        temp = temp->next;
    }
    printf("\n");
}

