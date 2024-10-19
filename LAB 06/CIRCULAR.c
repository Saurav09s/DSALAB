#include <stdio.h>
#include <stdlib.h>

struct cll
{
    int val;
    struct cll *next;
}*start,*node;

void create(struct cll *node);
void traverse(struct cll *node);

int main()
{
    struct cll *node, *start;
    node = (struct cll*)malloc(sizeof(struct cll*));
    if(node == NULL)
    {
        printf("Memory was not allocated");
        exit(0);
    }
    start  = node;
    while(1)
    {
        int choice;
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                create(node);
                break;

            case 2:
                traverse(node);
                break;

            case 3:
                exit(0);
                break;

            default:
                printf("Wrong choice!");
                break;
        }
    }
}

void create(struct cll *node)
{
    printf("Enter a value to be inserted: ");
    scanf("%d",&node->val);
    node->next=NULL;
    printf("Would you like to continue? (Y/N):");
    char ch[2];
    scanf("%s",ch);
    while(ch[0]=='Y')
    {
        struct cll *new;
        new = (struct cll*)malloc(sizeof(struct cll*));
        new->next=NULL;
        printf("Enter the value to be inserted in the list: ");
        scanf("%d",&new->val);
        node->next=new;
        node = new;
        node->next=NULL;
        printf("Would you like to continue? (Y/N):");
        scanf("%s",ch);
    }
    node->next=start;
    node = start; 
}

void traverse(struct cll *node)
{
    while(node!=NULL)
    {
        printf("%d ",node->val);
        node = node->next;
    }
    printf("\n");
}