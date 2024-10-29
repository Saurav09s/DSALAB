#include <stdio.h>
#include <stdlib.h>

struct sll 
{
    int val;
    struct sll *NEXT;
}*start;

void inAtAny(struct sll *node);
int deleteFrom(struct sll *node);
void count(struct sll *node);
void traverse(struct sll *node);

int main()
{
    struct sll *node;
    node = (struct sll*)malloc(sizeof(struct sll));
    if(node == NULL)
    {
        printf("Memory was not allocated");
    }
    start = node;
    printf("Enter the no of nodes to be inserted: ");
    int n;
    scanf("%d",&n);
    printf("Enter a value to be inserted: ");
    scanf("%d",&node->val);
    node->NEXT=NULL;
    n--;
    while(n!=0)
    {
        struct sll *new;
        new = (struct sll*)malloc(sizeof(struct sll*));
        printf("Enter the value to be inserted: ");
        scanf("%d",&new->val);
        node->NEXT=new;
        node = new;
        node->NEXT=NULL;
        n--;
    } 
    node = start; 
    printf("\n");
    while(1)
    {
        printf("MENU:\n");
        printf("1. Insert the node at a position\n");
        printf("2. Delete a node from specific position\n");
        printf("3. Count\n");
        printf("4. Traversal\n");
        printf("5. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                inAtAny(node);
                break;

            case 2:
                deleteFrom(node);
                break;

            case 3:
                count(node);
                break;

            case 4:
                traverse(node);
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

void inAtAny(struct sll *node)
{
    int x,pos,c=0;
    printf("Enter the value to be inserted: ");
    scanf("%d",&x);
    printf("Enter the position: ");
    scanf("%d",&pos);
    if(pos==0)
    {
        struct sll *new;
        new = (struct sll*)malloc(sizeof(struct sll*));
        new->val= x;
        new->NEXT=start;
        start = new;
        node = start;
    } 
    else
    {
        struct sll *p;
        node = start;
        p = node;
        for(int i = 0;i<pos-1;i++)
        {
            p = node;
            node = node->NEXT;
        }
        struct sll *new;
        new = (struct sll*)malloc(sizeof(struct sll*));
        new->val= x;
        p->NEXT= new;
        new->NEXT = node;
    }
}


void traverse(struct sll *node)
{
    struct sll *p = start;
    while(p)
    {
        printf("%d ",p->val);
        p = p->NEXT;
    }
    printf("\n");
}

void count(struct sll *node)
{
    int noOfNodes=0;
    node = start;
    while(node)
    {
        node = node->NEXT;
        noOfNodes++;
    }
    printf("Total no of nodes: %d\n",noOfNodes);
}

int deleteFrom(struct sll *node)
{
    struct sll *temp;
    printf("Enter the position of the element: ");
    int pos,t,c=0;
    scanf("%d",&pos);
    if(pos==1)
    {
        node = start;
        t = node->val;
        temp = node;
        node = node->NEXT;
        start = node;
        free(temp);       
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            temp = node;
            node = node->NEXT;
        }
       temp->NEXT = node->NEXT;
       temp = node;
       node = node->NEXT;
       free(temp);       
    }
    return t;
}