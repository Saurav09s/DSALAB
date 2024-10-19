#include <stdio.h>
#include <stdlib.h>

int inpCoeff(int n)
{
    int p1[n];
    int p2[n];
    

    printf("Enter Polynomial-1 from lowest to highest degree: ");
    for(int i=0;i<=n;i++)
    {
        scanf("%d",&p1[i]);
    }

    printf("\nEnter Polynomial-2: ");
    for(int i=0;i<=n;i++)
    {
        scanf("%d",&p2[i]);
    }

    printf("Resultant Polynomial: ");
    int k=n;
    for(int j=n;j>=0;--j)
    {
        if(j>=1)
        {
            printf("%dx^%d+",p1[j]+p2[j],j);
        }
        else
        {
            printf("%dx^%d",p1[j]+p2[j],j);
        }
    }
}

int main()
{
    int n;
    printf("Enter maximum degree of x: ");
    scanf("%d",&n);
    inpCoeff(n);
    return 0;
}