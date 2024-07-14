#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *CreatNode() {
    struct node *NextNode;
    NextNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the Value\n");
    scanf("%d", &NextNode->data);
    NextNode->next = NULL;
    return NextNode;
}

void InsertAtBegning(struct node **head) 
{
    struct node* NextNode = CreatNode();
    if (*head == NULL) {
        *head = NextNode;
        NextNode->next = NextNode; // circular link
    } else {
        struct node *temp = *head;
        while (temp->next!= *head) {
            temp = temp->next;
        }
        NextNode->next = *head;
        temp->next = NextNode;
        *head = NextNode;
    }
}

void InsertAtEnd(struct node **head) {
    struct node* NextNode = CreatNode();
    if (*head == NULL) {
        *head = NextNode;
        NextNode->next = NextNode; // circular link
    } else {
        struct node *temp = *head;
        while (temp->next!= *head) {
            temp = temp->next;
        }
        temp->next = NextNode;
        NextNode->next = *head;
    }
}

void InsertAfterThePosition(struct node *temp) {
    struct node *NextNode = CreatNode();
    NextNode->next = temp->next;
    temp->next = NextNode;
}

void Delete_From_beg(struct node **head) {
    struct node *temp = *head;
    if (temp->next == temp) {
        *head = NULL;
    } else {
        struct node *prev = *head;
        while (prev->next!= *head) {
            prev = prev->next;
        }
        prev->next = temp->next;
        *head = temp->next;
    }
    free(temp);
}

void Delete_From_end(struct node **head) {
    struct node *prev, *temp;
    temp = *head;
    if (temp->next == temp) {
        *head = NULL;
    } else {
        while (temp->next->next!= *head) {
            temp = temp->next;
        }
        prev = temp;
        temp = temp->next;
        prev->next = temp->next;
        free(temp);
    }
}

void Delete_After_pos(struct node *temp, struct node *next) {
    temp->next = next->next;
    free(next);
}

void display(struct node *head) {
    struct node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp!= head);
}

int main() 
{
    struct node *head;
    head = NULL;
    int choice = 1;
    struct node* temp=NULL;
    while (choice) {
        struct node *NextNode = CreatNode();
        if (head == NULL) {
            head = NextNode;
            NextNode->next = NextNode;
            temp=NextNode; // circular link
        }
        else 
        {
            temp->next = NextNode;
            NextNode->next = head;
            temp = NextNode;
        }
        printf("Do you want to add node 1/0\n");
        scanf("%d", &choice);
    }
    printf("Created Circular LinkedList\n");
    display(head);
    choice = 1;
    while (choice)
    {
        printf("\n1) Insert At Begning\n");
        printf("2) Insert At End\n");
        printf("3) Insert After the Position\n");
        printf("4) Delete From Begning\n");
        printf("5) Delete from End\n");
        printf("6) Delete node after a given Position\n");
        printf("7) Display\n");
        printf("8) Exit\n");
        printf("\n");

        printf("Enter the Choice\n");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("To Insert At the Begning\n ");
                InsertAtBegning(&head);
                break;

            case 2:
                printf("To Insert At the End\n ");
                InsertAtEnd(&head);
                break;

            case 3:
                int pos;
                printf("Enter the position after which to insert:");
                scanf("%d", &pos);
                struct node *temp = head;
                for (int i = 1; i < pos && temp->next!= head; i++) {
                    temp = temp->next;
                }

                if (temp!= NULL) {
                    InsertAfterThePosition(temp);
                } else {
                    printf("Pos is not in the list\n");
                }
                break;

            case 4:
                {
                printf("Deleting From Beginning");
                Delete_From_beg(&head);
                break;
                }

            case 5:
                printf("Deleting From End");
                Delete_From_end(&head);
                break;
            

            case 6:
            {
                int pos;
                printf("Enter the position after which you want to delete:");
                scanf("%d", &pos);
                struct node* next;
                struct node *temp = head;
                for (int i = 1; i < pos && temp->next!= head; i++) {
                    temp = temp->next;
                    next=temp->next;
                }

                if (temp!= NULL)
                {
                    Delete_After_pos(temp,next);
                } 
                else 
                {
                    printf("Pos is not in the list\n");
                }
                break;
            }

            case 7:
            display(head);
            break;
            case 8:
            printf("Exiting...........");
            exit(0);
            break;

            default:
            printf("Invalid Choice\n");
        }
    }
}