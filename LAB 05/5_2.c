#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *next;
}*Head=NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}
void display(struct Node *h)
{
    do
    {
        printf("%d ",h->data);
        h = h->next;
    } while (h!=Head);
    printf("\n");
}

int length(struct Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while (p!=Head);
    return len;
}

void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if(index < 0 || index > length(p))
        return;

    if(index==0)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = x;
        if(Head==NULL)
        {
            Head = t;
            Head->next = Head;
        }
        else
        {
            while (p->next != Head)p = p->next;
            p->next = t;
            t->next = Head;
            Head = t;            
        }
    }
    else
    {
        for (int i = 0; i < index-1; i++)p = p->next;

        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = x;
        t->next = p->next;
        p->next = t;     
    }
}
int delete(struct Node *p, int index)
{
    struct Node *q;
    int i,x = -1;
    if(index < 0 || index > length(Head))
        return x;

    if(index==1)
    {
        while(p->next!=Head)p = p->next;
        x = Head->data;
        if(Head==p)
        {
            free(Head);
            Head=NULL;
        }
        else
        {
            p->next = Head->next;
            free(Head);
            Head = p->next;
        }
    }
    else
    {
        for (i = 0; i < index-2; i++)
        {
            p=p->next;
        }
        q = p->next;
        p->next = q->next;
        x=q->data;
        free(q);
    }
    return x;
}

int main()
{
    printf("Enter the no of nodes: ");
    int n;
    scanf("%d",&n);
    printf("Enter the elements of the circular linked list: ");
    int a[n];
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    create(a,n);
    printf("Linked List created\n");

    printf("Main Menu\n");
    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Count no of Nodes\n");
    printf("4.Display\n");
    printf("5.EXIT\n");

    while (1)
    {
        int option;
        printf("Enter option: ");
        scanf("%d",&option);
        switch (option)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                int x;
                scanf("%d",&x);
                printf("Enter the position: ");
                int pos;
                scanf("%d",&pos);
                insert(Head,pos,x);
                break;

            case 2:
                printf("Enter which node has to be deleted: ");
                int index;
                scanf("%d",&index);
                delete(Head,index);
                break;

            case 3:
                printf("The no of nodes in circular linked list is: ",length(Head));
                break;

            case 4:
                printf("Circular Linked List:  ");
                display(Head);
                break;

            case 5:
                exit(0);        
            
            default:
                printf("Wrong Choice!");
                break;
        }
    }    
}