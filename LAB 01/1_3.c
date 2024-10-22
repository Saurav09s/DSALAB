#include <stdio.h>
#include <stdlib.h>


struct ComplexNum
{
    int real;
    int imaginary;
};

void sum(struct ComplexNum val1, struct ComplexNum val2);
void multiply(struct ComplexNum *p1,struct ComplexNum *p2);

int main()
{
    struct ComplexNum num1,num2,*p1=NULL,*p2=NULL;

    p1=&num1;
    p2=&num2;

    printf("Enter complex number 1: ");
    scanf("%d %d",&num1.real,&num1.imaginary);

    printf("Enter complex number 2: ");
    scanf("%d %d",&num2.real,&num2.imaginary);

    while(1)
    {
        int choice;
        printf("*******MENU******* \n");
        printf("1.SUM \n");
        printf("2.MULTIPLY \n");
        printf("3.EXIT \n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                sum(num1,num2);
                break;
            case 2:
                multiply(p1,p2);
                break;
            case 3:
                exit(0); 
                break;
            default:
                printf("Wrong Choice");
        }
    }

    return 0;

}

void sum(struct ComplexNum val1,struct ComplexNum val2)
{
    int rsum= val1.real+val2.real;
    int isum= val1.imaginary+val2.imaginary;
    printf("Sum = %d + %di \n \n",rsum,isum);

}

void multiply(struct ComplexNum *x,struct ComplexNum *y)
{
    printf("Product = %d + %di \n \n",((x->real*y->real)-(x->imaginary*y->imaginary)),((x->real*y->imaginary)+(y->real*x->imaginary)));
}