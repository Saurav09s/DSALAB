#include <stdio.h>
#include <stdlib.h>

int prime(int n);

int main()
{
    int n,sum = 0;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int *ptr=(int*)malloc(n*sizeof(int));

    int *temp = ptr;
    
    //Entering array elements
    printf("Enter array elements: ");
    for(int i = 0;i<n;i++)
    {
        scanf("%d",ptr);
        ptr++;
    }
    //Calculating Sum of the prime numbers
    ptr=temp;
    for(int i=0;i<n;i++)
    {
        if(prime(*ptr)==1)
        {
            sum+=*ptr;
        }
        ptr++;
    }

    //Printing the sum
    printf("Sum = %d",sum);
    free(ptr);
    
    return 0;
}
int prime(int n)
{
    int count = 0;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            count++;
        }
    }
    if(count==2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
