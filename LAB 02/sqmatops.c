#include <stdio.h>
#include <stdlib.h>

void nonzero(int n1,int b[n1][n1])
{
    int count=0;
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n1;j++)
        {
            if(b[i][j]==0)
            {
                count++;
            }
        }
    }
    printf("The number of non zero elements : %d",count);
}

void uppertriang(int n2,int c[n2][n2])
{
    for(int i=0;i<n2;i++)
    {
        for(int j=0;j<n2;j++)
        {
           if(i>j)
           {
                printf("  ");
           }
            else if(i<j)
            {
                printf("%d ",c[i][j]);
            }
        }
        printf("\n");
    }
}

void display(int n3,int d[n3][n3])
{
    printf("The elements above the main diagonal are:-");
    for(int i=0;i<n3;i++)
    {
        for(int j=0;j<n3;j++)
        {
            if(i<j)
            {
                printf(" %d ", d[i][j]);
            }
        }
    }

    printf("\n");
    printf("The elements below the main diagonal are:-");
    for(int i=0;i<n3;i++)
    {
        for(int j=0;j<n3;j++)
        {
            if(i>j)
            {
                printf(" %d ",d[i][j]);
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the size of the square matrix: ");
    scanf("%d",&n);
    int a[n][n];

    printf("Enter elements of the matrix:");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    nonzero(n,a);
    printf("\n");
    uppertriang(n,a);
    display(n,a);

}