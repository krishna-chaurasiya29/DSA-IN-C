#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

Node * top=NULL;
Node *CreateNode()
{
    Node * newNode=(Node*)malloc(sizeof(Node));
    printf("Enter the data\n");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    return newNode;
}
void push()
{
    Node * newNode=CreateNode();
    if(top==NULL)
    {
        top=newNode;
    }
    else
    {
        newNode->next=top;
        top=newNode;
    }
    printf("Pushed %d onto the stack\n",top->data);
}

void pop()
{
    if(top==NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        Node * temp=top;
        int poppedData=temp->data;
        top=top->next;
        free(temp);
        printf("Popped %d from the stack\n",poppedData);
    }
}
void display()
{
    if (top == NULL) 
    {
    printf("Stack is empty\n");
    }
    else
    {
        Node * temp=top;
        int count=0;
        printf("Stack Elements are.........\n");
        while (temp!=NULL)
        {
            count++;
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("\n");
        printf("Elements in the stack are :-%d\n",count);
    }
}
int main()
{
    int choice=1;
    while(choice)
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("Invalid choice\n");
        }
    }
}
