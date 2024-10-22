#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

char Stack[100], postfix[100], infix[100];
int top = -1, SIZE;

void PUSH(char x[],int n)
{
    if(top==SIZE-1)
    {
        printf("Stack Overflow!");
    }
    else
    {
        top++;
        Stack[top]=x[0];
    }
}
int isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
}
int precedence(char x[],int n)
{
    if(x[0]=='^'||x[0]=='%')
    {
        return 3;
    }
    if(x[0]=='*'||x[0]=='/')
    {
        return 2;
    }
    if(x[0]=='-'||x[0]=='+')
    {
        return 1;
    }
    if(x[0]=='(')
    {
        return 0;
    }
}
char POP()
{
    if(top==-1)
    {
        printf("Stack empty");
    }
    else
    {
        return Stack[top];
        top--;
    }
}

int operand(char x[],int n)
{
    if(x[0]=='+'||x[0]=='-'||x[0]=='/'||x[0]=='*'||x[0]=='^'||x[0]=='%')
    {
        return 1;
    }
    else
    {
        if(x[0]!='('&&x[0]!=')')
        {
            return 0;
        }
    }
}
void infiToPost()
{
    char x[2];
    int i=0,j=0;
    while(infix[i]!='\0')
    {
        x[0]=infix[i];
        if(operand(x,2)==0)
        {
            postfix[j]=infix[i];
            j++;
        }
        else if(x[0]=='(')
        {
            PUSH(x,2);
        }
        else if(operand(x,2)==1)
        {
            char y[2];
            y[0]=Stack[top];
            if(precedence(x,2)>precedence(y,2))
            {
                PUSH(x,2);
            }
            else
            {
                if(y[0]!='(')
                {
                    postfix[j]=POP();
                    j++;
                }
            }
        }
        else if(x[0]==')')
        {
            while(Stack[top]!='(')
            {
                postfix[j]=POP();
                j++;
            }
        }
        i++;
    }
    
}
int main()
{
    scanf("%s",infix);
    SIZE = strlen(infix);
    Stack[SIZE];
    infiToPost();
    printf("%s\n",Stack);
    printf("%s\n",postfix);
    
}