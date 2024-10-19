#include <stdio.h>
#include <stdlib.h>

void transpose(int n1,int spmt[][3]);
void display(int rspmt,int spmtTranspose[][3]);

int main()
{
    int n, rspmt;
    printf("Enter the no of non zero elements: ");
    scanf("%d", &n);
    rspmt = n + 1;
    int spmt[rspmt][3];
    int r, c;
    printf("Enter the no of rows and column of sparse matrix: ");
    scanf("%d %d", &r, &c);
    spmt[0][0] = r, spmt[0][1] = c, spmt[0][2] = n;
    printf("Enter the sparse matrix in 3 tuple format: ");
    for (int i = 1; i < rspmt; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &spmt[i][j]);
        }
    }
    
    transpose(rspmt,spmt);    
}

void transpose(int rspmt, int spmt[][3])
{
    int spmtTranspose[rspmt][3];
    for (int i = 0; i < rspmt; i++)
    {
        spmtTranspose[i][0] = spmt[i][1];
        spmtTranspose[i][1] = spmt[i][0];
        spmtTranspose[i][2] = spmt[i][2];
    }

    for(int i=1;i<rspmt-1;i++)
    {
        int a=spmtTranspose[i][0],b=spmtTranspose[i+1][0];
        for (int j = 0; j < 3; j++)
        {
            int temp =0;
            if(a>b)
            {
                temp = spmtTranspose[i][j];
                spmtTranspose[i][j]=spmtTranspose[i+1][j];
                spmtTranspose[i+1][j]=temp;
            }
        }
    }
    display(rspmt,spmtTranspose);
}

void display(int rspmt,int spmtTranspose[][3])
{
    for (int i = 0; i < rspmt; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", spmtTranspose[i][j]);
        }
        printf("\n");
    }
}
