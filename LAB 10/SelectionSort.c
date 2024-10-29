#include <stdio.h>

void Selection(int a[], int n)
{
    int i, j = 0,k,temp;
    for (i = 0; i < 6; i++)
    {
        k = i;
        for (j = i + 1; j < 6; j++)
        {
            if (a[j] < a[k])
            {
                k = j;
            }
        }
        temp = a[i];
        a[i] = a[k];
        a[k] = temp;
    }
}

int main()
{
    printf("Enter no of elements: ");
    int n;
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    Selection(a,n);
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");    
}