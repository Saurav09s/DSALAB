#include <stdio.h>
#include <stdlib.h>

struct BstNode{
    struct BstNode *lchild;
    struct BstNode *rchild;
    int data;
}*root = NULL;

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
            printf("Element found");
            return;
        } else if (key < t->data){
            t = t->lchild;
        } else {
            t = t->rchild;
        }
    }
    printf("Element not found");
}
int main()
{
    Insert(5);
    Insert(90);
    Insert(9);
    Insert(12);
    Insert(34);

    preOrder(root);
    
    printf("\n");

    inOrder(root);

    printf("\n");

    postOrder(root);

    printf("\n");

    search(1);      
}