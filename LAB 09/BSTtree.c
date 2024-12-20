#include <stdio.h>
#include <stdlib.h>

typedef struct BstNode{
    struct BstNode *lchild;
    struct BstNode *rchild;
    int data;
}BST;
BST *root = NULL;
void Insert(int key)
{
    struct BstNode* t = root;
    struct BstNode* p;
    struct BstNode* r;
 
    if (root == NULL){
        p = (struct BstNode*)malloc(sizeof(struct BstNode));
        p->data = key;
        p->lchild = NULL;
        p->rchild = NULL;
        root = p;
        return;
    }
 
    while(t != NULL)
    {
        r = t;
        if (key < t->data)
        {
            t = t->lchild;
        } 
        else if (key > t->data)
        {
            t = t->rchild;
        } else {
            return;
        }
    }
 
    p = (struct BstNode*)malloc(sizeof(struct BstNode));
    p->data = key;
    p->lchild = NULL;
    p->rchild = NULL;
 
    if (key < r->data)
    {
        r->lchild = p;
    } 
    else 
    {
        r->rchild = p;
    }
}

void inOrder(struct BstNode *p)
{
    if (p){
        inOrder(p->lchild);
        printf("%d ",p->data);
        inOrder(p->rchild);
    }
}

void preOrder(struct BstNode *p)
{
    if(p){
    printf("%d ",p->data);
    preOrder(p->lchild);
    preOrder(p->rchild);
    }
}

void postOrder(struct BstNode *p)
{
    if(p){
    postOrder(p->lchild);
    postOrder(p->rchild);
    printf("%d ",p->data);
    }
}

void search(int key)
{
    struct BstNode *t = root;
    while (t != NULL){
        if (key == t->data){
            printf("Element found\n");
            return;
        } else if (key < t->data){
            t = t->lchild;
        } else {
            t = t->rchild;
        }
    }
    printf("Element not found\n");
}
int main()
{
    int n;
    printf("Enter no of nodes: ");
    scanf("%d",&n);
    printf("Enter BST elements: ");
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&ar[i]);
    }
    for (int i = 0; i < n; i++)
    {
        Insert(ar[i]);
    }
    printf("BST created\n");

    printf("Main MENU\n");
    printf("1.Preorder\n");
    printf("2.Postorder\n");
    printf("3.Inorder\n");
    printf("4.Search\n");
    printf("5.EXIT\n");

    while (1)
    {
        int option;
        printf("Enter option: ");
        scanf("%d",&option);

        switch (option)
        {
            case 1:
                preOrder(root);
                printf("\n");
                break;

            case 2:
                postOrder(root);
                printf("\n");
                break;

            case 3:
                inOrder(root);
                printf("\n");
                break;

            case 4:
                printf("Enter the element to be searched: ");
                int x;
                scanf("%d",&x);
                search(x);
                break;

            case 5:
                exit(0);
                
            default:
                printf("Wrong Choice!\n");
                break;
        }
    }    
}