#include <stdio.h>
#include <stdlib.h>


void add(int n1, int n2, int spmt1[][3], int spmt2[][3]);
int main()
{

    int r1, c1, n1;
    printf("Enter no of non zero elements in sparse matrix 1: ");
    scanf("%d", &n1);
    printf("Enter the row and column of sparse matrix 1:");
    scanf("%d %d", &r1, &c1);
    int spmt1[n1 + 1][3];
    spmt1[0][0] = r1, spmt1[0][1] = c1, spmt1[0][2] = n1;

    int r2, c2, n2;
    printf("Enter no of non zero elements in sparse matrix 2: ");
    scanf("%d", &n2);
    printf("Enter the row and column of sparse matrix 2:");
    scanf("%d %d", &r2, &c2);
    int spmt2[n2 + 1][3];
    spmt2[0][0] = r1, spmt2[0][1] = c1, spmt2[0][2] = n2;

    printf("Enter the elements of sparse matrix 1:");
    for (int i = 1; i < n1 + 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &spmt1[i][j]);
        }
    }

    printf("Enter the elements of sparse matrix 2:");
    for (int i = 1; i < n2 + 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &spmt2[i][j]);
        }
    }
    add(n1, n2, spmt1, spmt2);
}
void add(int n1, int n2, int spmt1[][3], int spmt2[][3])
{
    int nonZero, n = 0;
    if (spmt1[0][2] > spmt2[0][2])
    {
        nonZero = spmt1[0][2];
    }
    else
    {
        nonZero = spmt2[0][2];
    }
    for (int i = 1; i < nonZero + 1; i++)
    {
        if (spmt1[i][0] == spmt2[i][0] && spmt1[i][1] == spmt2[i][1])
        {
            n++;
        }
        else
        {
            n += 2;
        }
    }
    int res_spmt[n + 1][3];
    res_spmt[0][0] = spmt1[0][0], res_spmt[0][1] = spmt1[0][1], res_spmt[0][2] = n;
    int k = 1;
    for (int i = 1; i < n + 1; i++)
    {
        if(spmt1[i][0] == spmt2[i][0] && spmt1[i][1] == spmt2[i][1])
        {
            res_spmt[k][0] = spmt1[i][0];
            res_spmt[k][1] = spmt1[i][1];
            res_spmt[k][2] = spmt1[i][2]+spmt2[i][2];
            k++;
        }
        else if (spmt1[i][0] > spmt2[i][0] || spmt1[i][0] == spmt2[i][0])
        {
            if (spmt1[i][1] > spmt2[i][1])
            {
                res_spmt[k][0] = spmt2[i][0];
                res_spmt[k][1] = spmt2[i][1];
                res_spmt[k][2] = spmt2[i][2];
                res_spmt[k + 1][0] = spmt1[i][0];
                res_spmt[k + 1][1] = spmt1[i][1];
                res_spmt[k + 1][2] = spmt1[i][2];
            }
            else
            {
                res_spmt[k][0] = spmt1[i][0];
                res_spmt[k][1] = spmt1[i][1];
                res_spmt[k][2] = spmt1[i][2];
                res_spmt[k + 1][0] = spmt2[i][0];
                res_spmt[k + 1][1] = spmt2[i][1];
                res_spmt[k + 1][2] = spmt2[i][2];
            }
            k=k+2;
        }
    }
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ",res_spmt[i][j]);
        }
        printf("\n");
    }
}
