#include <stdio.h>

int main()
{
    printf("Enter the elements of the array:");
    int ar[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&ar[i][j]);
        }
    }
    printf("Original Matrix:");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d",ar[i][j]);
        }
        printf("\n");
    }

    int ar2[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            ar2[i][j]=ar[j][i];
        }
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d",ar2[i][j]);
        }
        printf("\n");
    }
    return 0;
}