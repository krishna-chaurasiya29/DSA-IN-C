#include <stdio.h>
#include<ctype.h>
char stack[10];
int top=-1;
void push(char x)
{
    stack[++top]=x;
}
char pop()
{
    if(top==-1)
    return -1;
    else
    return stack[top--];
}
int priority(char x)
{
if(x=='(')
return 0;
if(x=='+'||x=='-')
return 1;
if(x=='*'||x=='/')
return 2;
}
int main()
{
char exp[20];
char*e,x;
    printf("\nEnter the expression :  ");
    scanf("%[^\n]s",&exp);
    e=exp;
    while(*e!='\0')
    {
    if(isalnum(*e))//is alnum() is a fucntion used to check that the given input is alphabet or numeric
        printf("%c",*e);
    else if(*e=='(')
        push(*e);
    else if(*e==')')
    {
        while((x==pop())!='(')
        {
        printf("%c",x);
        }
    }
    else
    {
        while(priority(stack[top])>=priority(*e))
        printf("%c",pop());
        push(*e);
    }
    e++; 
    }
    while(top!=-1)
    {
        printf("%c",pop());
    }
}