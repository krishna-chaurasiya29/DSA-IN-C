#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

// Function to create a new node
struct node* createNode(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Function to push an element onto the stack
void push(int data) {
    struct node *newnode = createNode(data);
    if (top == NULL) 
    {
        top = newnode;
    } 
    else 
    {
        newnode->next = top;
        top = newnode;
    }
    printf("Pushed %d onto the stack\n", data);
}

// Function to pop an element from the stack
int pop() 
{
    if (top == NULL) 
    {
        printf("Stack underflow\n");
        return -1;
    } 
    else 
    {
        struct node *temp = top;
        int poppedData = temp->data;
        top = top->next;
        free(temp);
        printf("Popped %d from the stack\n", poppedData);
        return poppedData;
    }
}

// Function to display the stack
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        struct node *temp = top;
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
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
                printf("Invalid choice, please try again\n");
        }
    }
    return 0;
}
