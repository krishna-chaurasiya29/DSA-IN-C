#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *createNode() {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void display(struct node *head) {
    struct node *temp = head;
    while (temp!= NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL, *temp = NULL;
    int choice = 1;
    printf("Creating doubly linked list\n");
    while (choice) {
        struct node *newNode = createNode();
        if (!newNode) {
            printf("Failed to create a new node\n");
            break;
        }
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
        printf("Do you want to continue? 1 for yes and 0 for no: ");
        scanf("%d", &choice);
    }
    printf("The updated linked list is:\n");
    display(head);
    return 0;
}