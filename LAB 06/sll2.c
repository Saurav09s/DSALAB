#include <stdio.h>
#include <stdlib.h>

int count1=0;

struct sll 
{
    int val;
    struct sll *NEXT;
}*start;

void search(struct sll *node);
void sort(struct sll *node);
void reverse(struct sll *node);
void traverse(struct sll *node);

int main()
{
    struct sll *node;
    node = (struct sll*)malloc(sizeof(struct sll*));
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
        new = (struct sll*)malloc(sizeof(struct sll));
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
        printf("i. search an element in the list\n");
        printf("ii. sort the list in ascending order\n");
        printf("iii. reverse the list\n");
        printf("iv. traverse\n");
        printf("v. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                search(node);
                break;

            case 2:
                sort(node);
                break;

            case 3:
                reverse(node);
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
void traverse(struct sll *node)
{
    node=start;
    while(node!=NULL)
    {
        printf("%d ",node->val);
        node = node->NEXT;
    }
    printf("\n");
}

void search(struct sll *node)
{
    printf("Enter the element to be searched:");
    int x;
    scanf("%d",&x);
    int pos=1;
    while(node->val!=x)
    {
        node = node->NEXT;
        pos++;
    }
    printf("Element found at node %d",pos);
}

void sort(struct sll *node)
{
    struct sll *i,*j;
    for(i = start;i!=NULL;i=i->NEXT)
    {
        int temp = 0;
        for(j = start;j->NEXT!=NULL;j=j->NEXT)
        {
            if(j->val>j->NEXT->val)
            {
                temp = j->val;
                j->val=j->NEXT->val;
                j->NEXT->val=temp;
            }
        }
    }
}

void reverse(struct sll *node)
{
    struct sll *q = NULL, *r = NULL;

    while (node != NULL)
    {
        r = q;
        q = node;
        node = node->NEXT;
        q->NEXT = r;
    }
    start = q;
}