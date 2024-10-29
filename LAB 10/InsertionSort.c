#include <stdio.h>

void Insertion(int a[], int n)
{
    int i,j,key;
    for(i = 1;i < n;i++)
    {
        key = a[i];
        j = i-1;
        while (j>=0&&a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

int main()
{
    int n,i;
    printf("Enter no of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements of the array: ");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    Insertion(a,n);
    printf("Sorted Array: ");
    for ( i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}