#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r,c,count=0;
    printf("Enter the size of the sparse matrix: ");
    scanf("%d %d",&r,&c);
    int ar[r][c];
    printf("Enter the elements of sparse matrix:");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&ar[i][j]);
            if(ar[i][j]!=0)
            {
                count++;
            }
        }
    }

    int spmt[count+1][3];
    spmt[0][0]=r;
    spmt[0][1]=c;
    spmt[0][2]=count;
    int k=1;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(ar[i][j]!=0)
            {
                spmt[k][0]=i;
                spmt[k][1]=j;
                spmt[k][2]=ar[i][j];
                k++;
            }
        }
    }

    for(int i=0;i<count+1;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",spmt[i][j]);
        }
        printf("\n");
    }   
}

    