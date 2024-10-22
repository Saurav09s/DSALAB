#include <stdio.h>
#include <stdlib.h>

void compare(int *p, int *q)
{
    if(*p>*q)
    {
        printf("%d is greater than %d\n",*p,*q);
    }
    else if(*p<*q)
    {
        printf("%d is less than %d\n",*p,*q);
    }
    else
    {
        printf("Both numbers are same\n");
    }
}

int main()
{
    int a,b;
    printf("Please enter the two numbers to be compared: ");
    scanf("%d %d",&a,&b);
    compare(&a,&b);
}
