#include <stdio.h>
#include <stddef.h>

void compare(int *a2,int *b2);

int main()
{
    int a,b;
    printf("Enter two numbers:");
    scanf("%d %d",&a,&b);
    int *a1=NULL,*b1=NULL;
    a1 = &a;
    b1 = &b;
    compare(a1,b1);
    return 0;
}
void compare(int*a2,int*b2)
{
    if(*a2>*b2)
    {
        printf("%d is greater than %d",*a2,*b2);
    }
    else if(*a2<*b2)
    {
        printf("%d is less than %d",*a2,*b2);
    }
    else
    {
        printf("Both numbers are same");
    }
}
