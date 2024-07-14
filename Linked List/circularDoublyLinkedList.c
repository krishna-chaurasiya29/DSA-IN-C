// Circular_Doubly_Linkedlist
#include<stdio.h>
#include<stdlib.h>

struct node *CreateNode();
void Display(struct node *head);
void Insert_at_beg(struct node **head);
void Insert_at_end(struct node **head);
void Insert_after_pos(struct node *head, int pos);
void Delete_from_beg(struct node **head);
void Delete_from_end(struct node **head);
void Delete_after_pos(struct node *head, int pos);
void LengthCount(struct node *head);

struct node {
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head, *temp;

struct node *CreateNode() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void Insert_at_beg(struct node **head) {
    struct node *newnode = CreateNode();
    if (*head == NULL) {
        *head = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;
    } else {
        struct node *last = (*head)->prev;
        newnode->next = *head;
        newnode->prev = last;
        last->next = newnode;
        (*head)->prev = newnode;
        *head = newnode;
    }
}

void Insert_at_end(struct node **head) {
    struct node *newnode = CreateNode();
    if (*head == NULL) {
        *head = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;
    } else {
        struct node *last = (*head)->prev;
        newnode->next = *head;
        newnode->prev = last;
        last->next = newnode;
        (*head)->prev = newnode;
    }
}

void Insert_after_pos(struct node *head, int pos) {
    struct node *newnode = CreateNode();
    temp = head;
    for (int i = 1; i < pos && temp->next != head; i++) {
        temp = temp->next;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
}

void Delete_from_beg(struct node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = *head;
    if (temp->next == *head) {
        *head = NULL;
        free(temp);
    } else {
        struct node *last = temp->prev;
        *head = temp->next;
        last->next = *head;
        (*head)->prev = last;
        free(temp);
    }
}

void Delete_from_end(struct node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = *head;
    if (temp->next == *head) {
        *head = NULL;
        free(temp);
    } else {
        struct node *last = temp->prev;
        last->prev->next = *head;
        (*head)->prev = last->prev;
        free(last);
    }
}

void Delete_after_pos(struct node *head, int pos) {
    temp = head;
    for (int i = 1; i < pos && temp->next != head; i++) {
        temp = temp->next;
    }
    struct node *todelete = temp->next;
    temp->next = todelete->next;
    todelete->next->prev = temp;
    free(todelete);
}

void Display(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void LengthCount(struct node *head) {
    int count = 0;
    if (head == NULL) {
        printf("\nLength Of Linked List is :- %d\n", count);
        return;
    }
    temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    printf("\nLength Of Linked List is :- %d\n", count); 
}

int main() {
    head = NULL;
    int choice = 1;
    printf("First Create a Circular Doubly LinkedList\n");
    while (choice) {
        struct node *newnode = CreateNode();
        if (head == NULL) {
            head = newnode;
            newnode->next = newnode;
            newnode->prev = newnode;
        } else {
            struct node *last = head->prev;
            last->next = newnode;
            newnode->prev = last;
            newnode->next = head;
            head->prev = newnode;
        }
        
        printf("Do you want to insert new node 1/0\n");
        scanf("%d", &choice);
    }

    printf("LinkedList Created\n");
    Display(head);
    LengthCount(head);
    choice = 1;

    while (choice) {
        printf("\n1) Insert at Beginning\n");
        printf("2) Insert at end\n");
        printf("3) Insert after given position\n");
        printf("4) Delete from Beginning\n");
        printf("5) Delete from end\n");
        printf("6) Delete after the Given position\n");
        printf("0) Exit\n");
        
        printf("Enter the choice\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("To insert at Beginning\n");
                Insert_at_beg(&head);
                break;
                
            case 2:
                printf("To insert at end\n");
                Insert_at_end(&head);
                break;
                
            case 3:
                int pos;
                printf("Give position\n");
                scanf("%d", &pos);
                printf("Inserting After Given position\n");
                Insert_after_pos(head, pos);
                break;
                
            case 4:
                printf("Deleting from Beginning\n");
                Delete_from_beg(&head);
                break;
                
            case 5:
                printf("Deleting from end\n");
                Delete_from_end(&head);
                break;
                
            case 6:
                int position;
                printf("Enter the position\n");
                scanf("%d", &position);
                printf("Deleting after given position\n");
                Delete_after_pos(head, position);
                break;
            
            case 0:
                printf("Exiting....\n");
                break;
                
            default:
                printf("Invalid Option\n");
        }
        printf("Updated LinkedList\n");
        Display(head);
        LengthCount(head);
    }
}
