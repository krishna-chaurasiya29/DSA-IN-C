#include<stdio.h>
#include<stdlib.h>
#define MAX 100//here we can define size as global if we want
typedef struct 
{
    int top;
    int size;
    int *arr;
}Stack;

Stack *createStack(int size)
{
Stack * stack= (Stack*)malloc(sizeof(Stack));
stack->top=-1;
stack->size=size;
stack->arr=(int*)malloc(sizeof(int)*size);
return stack;
}
int isFull(Stack* stack)
{
    // if(stack->top==stack->size-1)
    // printf("The Stack is OVerFlowed.....\n");
    // else
    // printf("The Stack is N0t OVerFlowed....\n");
    return (stack->top==stack->size-1);
}
int isEmpty(Stack * stack)
{
    // if(stack->top==-1)
    // printf("The Stack is Empty\n");
    // else
    // printf("The Stack is not Empty\n");
        return (stack->top==-1);

}
void push(Stack *stack, int item)
{
    if (isFull(stack))
    {
        printf("Stack is Overflowed...... \n");
    }
    else
    {
        stack->arr[++stack->top]=item;
        printf("Inserted Element is %d",item);
    }
}

void pop(Stack * stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is UnderFlow..\n");
    }
    else
    {
        printf("Deleted Element is %d\n",stack->arr[stack->top--]);
    }
}

void peek(Stack * stack)
{
    if (isEmpty(stack))
    printf("Stack is Underflow.....\n");
    else
    printf("Top Element is %d\n",stack->arr[stack->top]);
}

void display(Stack * stack)
{
    int value=stack->top;
    while(value>=0)
    printf("%d\n",stack->arr[value--]);
}
int main()
{
    Stack *stack=createStack(5);
    int choice, value;
    while(1)
    {
        printf("\nEnter The Choose From Below\n");
        printf("1. Push\n");//done
        printf("2. Pop\n");//done
        printf("3. Peek\n");//done
        printf("4. To Check Stack is Empty or NOt\n");//done
        printf("5. To Check Stack is Full or Not\n");//done
        printf("6. Count..\n");//done
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter Your Choice:- ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter The Value You Want to Add:- ");
            scanf("%d",&value);
            push(stack,value);
            break;

            case 2:
            pop(stack);
            break;

            case 3:
            peek(stack);
            break;

            case 4:
                if(isEmpty(stack))
                printf("Stack is Empty....\n");
                else
                printf("The Stack is Not Empty.....\n");
            break;

            case 5:
            if(isFull(stack))
            printf("Stack is Full....\n");
            else
            printf("The Stack is Not Fulled Yet.....\n");
            break;

            case 6:
            printf("The Count in the Stack is:- %d \n",stack->top+1);
            break;

            case 7:
            display(stack);
            break;

            case 8:
             free(stack->arr);  // Free the allocated memory for array
            free(stack);  // Free the allocated memory for stack structure
            printf("Exiting...\n");
            exit(0);
            
            default:
            printf("Invalid Choice,Try Again\n");
        }
    }
}
