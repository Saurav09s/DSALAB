#include <stdio.h>
#include <stdlib.h>

void Merge(int a[],int l, int h, int mid)
{
    int i = l, k = l, j = mid+1, B[1000];
    while(i<=mid&&j<=h)
    {
        if(a[i]<a[j])
            B[k++]=a[i++];
        else
            B[k++]=a[j++];
    }
    for(;i<=mid;i++)
        B[k++]=a[i];
    for(;j<=h;j++)
        B[k++]=a[j];
    for(i=0;i<=h;i++)
        a[i]=b[i];      
}
void MergeSort(int a[],int n)
{
    
}
