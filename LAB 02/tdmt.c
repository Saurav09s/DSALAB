#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter the dimension of 3-tuple format of sparse matrix");
    int a,b;
    scanf("%d %d",&a,&b);
    int spmt[a][b];
    printf("Enter elements of the sparse matrix");
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            scanf("%d",&spmt[i][j]);
        }
    }
    int r=spmt[0][0];//no of rows of traditional matrix
    int c=spmt[0][1];//no of columns of traditional matrix
    int k=1;
    int ar[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(i==spmt[k][0]&&j==spmt[k][1])
            {
                ar[i][j]=spmt[k][2];
                k++;
            }
            else
            {
                ar[i][j]=0;
            }
        }
    }

    printf("The corresponding traditional matrix is:\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",ar[i][j]);
        }
        printf("\n");
    }
}