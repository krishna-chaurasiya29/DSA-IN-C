#include <stdio.h>
#define size 20
char a[size];
int top =-1;
void push(char x)
{
    if(top==size-1)
    {
        printf("Stack is over flow ");
    }
    else
    {
    a[++top]=x;
    }
}
char pop()
{
    if(top==-1)
    {
        printf("Stack is under flow ");
    }
    else
    {
        printf("%c",a[top]);
        return a[top--];
    }
}

int main()
{
    char str[20];
    int i,l;
    printf("\nEnter the string :");
    scanf("%s",&str);
    l=strlen(str);
    for(i=0;i<l;i++)
    {
        push(str[i]);
    }
    printf("\nstring in reverse\n");
    for(i=0;i<l;i++)
    {
        pop();
    }
}