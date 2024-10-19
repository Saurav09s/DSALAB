#include <stdio.h>
#include <stdlib.h>

void insert(int n3,int a[]);
void delete(int n4,int a[]);
int LinSearch(int k,int *p);
void traverse(int *q,int n2);

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int a[n];
    

    printf("Enter elements of the array:");
    for(int i =0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    int *ptr = a;
    while (1)
    { 
        printf("MENU:\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Linear Search\n");
        printf("4.Traverse\n");

        int choice;
        printf("Please enter the choice:");
        scanf("%d",&choice);
     
        switch (choice)
        {
            case 1:
                insert(n,ptr);
                break;

            case 2:
                delete(n,ptr);
                break;

            case 3:
                printf("Enter the element to be searched: ");
                int pos = LinSearch(n, ptr);
                printf("The element is at index %d",pos);
                break;

            case 4:
                traverse(ptr,n);
                break;

            case 5:
                exit(0);
                break;

            default:
                printf("Invalid Choice!");
                break;
        }
    }
}



int LinSearch(int n1,int *p)
{
    int k,idx=-1;
    scanf("%d",&k);

    for(int i=0;i<n1;i++)
    {
        if(k==*p)
        {
            idx=i;
        }
        p++;
    }
    if(idx!=-1)
    {
       return idx;
    }
    else
    {
        return -1;
    }

}

void traverse(int *q,int n2)
{
    for(int i=0;i<n2;i++)
    {
        printf("%d ",*q);
        q++;
    }
}

void delete(int n4,int a[])
{
    int num;
    int *ptr2 = a;
    printf("Enter the element to be deleted:");
    int pos=LinSearch(  n4, ptr2);

    // Deleting element
    int i;
    for (i = pos; i < n4 - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n4--;
    
    printf("\nArray after deletion\n");
    for (i = 0; i < n4; i++)
    {
        printf("%d  ", a[i]);
    }
}

void insert(int n3,int a[])
{
    n3++;
    printf("%d",n3);
    int num,key;

    printf("Enter the number to be inserted:");
    scanf("%d",&num);

    printf("Enter the index at which element is to be inserted:" );
    scanf("%d",&key);

    for(int i=n3-2;i>=key;i--)
    {
        a[i+1]=a[i];
    }
    a[key]=num;

    for(int i=0;i<n3;i++)
    {
        printf("%d ",a[i]);
    }
}