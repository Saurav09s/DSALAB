#include <stdio.h>
#include <stdlib.h>

int count1=0;

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
    count1 = 1;
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
        count1++;
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
    if(pos==1)
    {
        struct sll *new;
        new = (struct sll*)malloc(sizeof(struct sll*));
        new->NEXT=start;
        new->val= x;
        start = new;
        node = start;
        count1++;
    } 
    else if(pos == count1+1)
    {
        while(node->NEXT!=NULL)
        {
            node = node->NEXT;
        }
        struct sll *new;
        new = (struct sll*)malloc(sizeof(struct sll*));
        new->val= x;
        node->NEXT = new;
        node = new;
        node->NEXT = NULL;
        count1++;
    }
    else
    {
        c=0;
        while(c<pos-2)
        {
            node=node->NEXT;
            c++;
        }
        struct sll *new;
        new = (struct sll *)malloc(sizeof(struct sll *));
        new->val = x;
        new->NEXT = node->NEXT;
        node->NEXT = new;
        node=new;
        count1++;
    }  
}


void traverse(struct sll *node)
{
    if(node!=NULL)
    {
        printf("%d ",node->val);
        traverse(node->NEXT);
    }
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
    printf("Enter the position of the element: ");
    int pos,t,c=0;
    scanf("%d",&pos);
    if(pos==1)
    {
        node = start;
        struct sll *temp;
        temp = (struct sll*)malloc(sizeof(struct sll));
        t = node->val;
        temp = node;
        node = node->NEXT;
        start = node;
        free(temp);       
    }
    else if(pos==count1)
    {
        node = start;
        struct sll *temp, *prev;
        while(node->NEXT!=NULL)
        {
            prev=node;
            node = node->NEXT;
        }
        t=node->val;
        temp = node;
        node = prev;
        node->NEXT=NULL;
        node = start;
        free(temp);
    }
    else
    {
        node = start;
        struct sll *temp,*prev;
        while(c!=pos-1)
        {
            prev = node;
            node = node->NEXT;
            c++;
        } 
        temp = node;
        node = prev;
        node->NEXT=temp->NEXT;
        free(temp);      
    }
    return t;
}