#include <stdio.h>
#include <stdlib.h>

int count1=0;

struct dll
{
    int val;
    struct dll *prev;
    struct dll *next;
}*start;

void inAtAny(struct dll *node);
int deleteFrom(struct dll *node);
void traverse(struct dll *node);

int main()
{
    struct dll *node;
    node = (struct dll*)malloc(sizeof(struct dll*));
    if(node==NULL)
    {
        printf("Memory was not allocated");
        exit(0);
    }
    start = node;
    printf("Enter no of nodes: ");
    int n;
    scanf("%d",&n);
    printf("Enter the value to be inserted: ");
    scanf("%d",&node->val);
    count1++;
    n--;
    node->next=NULL;
    node->prev=NULL;
    while(n!=0)
    {
        struct dll *new;
        new = (struct dll*)malloc(sizeof(struct dll));
        printf("Enter the value to be inserted: "); 
        scanf("%d",&new->val);
        node->next = new;
        new->prev = node;
        node = new;
        node->next = NULL;
        n--;
        count1++;
    }
    node = start;
    while(1)
    {
        printf("MENU: \n");
        printf("1. Insert the node at a position\n");
        printf("2. Delete a node from specific position\n");
        printf("3. Traversal\n");
        printf("4. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                inAtAny(node);
                break;

            case 2:
                printf("The element deleted was: %d",deleteFrom(node));
                break;

            case 3:
                traverse(node);
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Wrong choice!\n");
                break;
        }
    }
}

void inAtAny(struct dll *node)
{
    int x,pos,c=0;
    printf("Enter the value to be inserted: ");
    scanf("%d",&x);
    printf("Enter the position: ");
    scanf("%d",&pos);
    if(pos==1)
    {
        node = start;
        struct dll *new;
        new = (struct dll*)malloc(sizeof(struct dll));
        new->next=start;
        new->prev=NULL;
        new->val= x;
        start = new;
        node = start;
        count1++;
    } 
    else if(pos == count1+1)
    {
        node = start;
        while(node->next!=NULL)
        {
            node = node->next;
        }
        struct dll *new;
        new = (struct dll*)malloc(sizeof(struct dll));
        new->val= x;
        node->next = new;
        new->prev = node;
        node = new;
        node->next = NULL;        
        count1++;
    }
    else
    {
        c=0;
        while(c<pos-2)
        {
            node=node->next;
            c++;
        }
        struct dll *new;
        new = (struct dll *)malloc(sizeof(struct dll));
        new->val = x;
        new->next = node->next;
        node->next = new;
        new->prev= node;
        node=new;
        count1++;
    }
    printf("\n");  
}

int deleteFrom(struct dll *node)
{
    printf("Enter the position of the element: ");
    int pos,t,c=0;
    scanf("%d",&pos);
    if(pos==1)
    {
        node = start;
        struct dll *temp;
        temp=(struct dll *)malloc(sizeof(struct dll));
        t = node->val;
        temp = node;
        node = node->next;
        node->prev=NULL;
        start = node;

    }
    else if(pos==count1)
    {
        struct dll *temp, *before;
        while(node->next!=NULL)
        {
            before=node;
            node = node->next;
        }
        t=node->val;
        temp = node;
        node = before;
        node->next=NULL;
        node = start;
        free(temp);
    }
    else
    {
        node = start;
        struct dll *temp,*before;
        while(c!=pos-1)
        {
            before = node;
            node = node->next;
            c++;
        }
        t= node->val; 
        temp = node;
        before->next = node->next;
        node = node->next;
        node->prev=before;
        node = before;
        free(temp);      
    }
    return t;
}

void traverse(struct dll *node)
{
    node = start;
    while(node!=NULL)
    {
        printf("%d ",node->val);
        node = node->next;
    }
    printf("\n");
}