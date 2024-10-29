#include <stdio.h>
#include <stdlib.h>

void Bubble(int a[],int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(a[j]>a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main()
{
    printf("Enter no of elements: ");
    int n;
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    Bubble(a,n);
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}