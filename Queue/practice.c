#include<stdio.h>
#include<stdlib.h>
struct node * createNode();
void Insert_at_Beg(struct node ** head);
void Insert_at_End(struct node ** head);
void Insert_at_pos(struct node * temp);
void Delete_at_Beg(struct node ** head);
void Delete_at_End(struct node ** head);
void Delete_at_pos(struct node * temp);
void Display(struct node*head);
struct node
{
    int data;
    struct node *next;
};

struct node * createNode()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    return newNode;
}
void display(struct node* head)
{
    int count=0;
    struct node * temp=head;
    while(temp!=NULL)
    {
        count++;
        printf("%d\t", temp->data);
        temp=temp->next;
    }
    printf("\n");
    printf("Count of the linked list is:-%d ",count);
}
void Insert_at_Beg(struct node ** head)
{
    struct node * newNode=createNode();
    if(*head==NULL)
    {
        *head=newNode;
        newNode->next=newNode;
    }
    else
    {
        struct node*temp=*head;
        while(temp->next!=*head)
        {
            temp=temp->next;
        }
        newNode->next=*head;
        temp->next=newNode;
        *head=newNode;
    }
}

void Delete_at_Beg(struct node ** head)
{
    struct node *temp=*head;
    if(temp->next=temp)
    {
        *head=NULL;
    }
    else
    {
        struct node* prev=*head;
        while(prev->next!=head)
        {
            prev=prev->next;
        }
        prev->next=temp->next;
        temp->next =head;
    }
}

void Delete_at_End(struct node ** head)
{
    struct node*temp=head;
    struct node*prev;
    if(temp->next=temp)
    {
        *head=NULL;
    }
    else
    {
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        prev=temp;
        temp=temp->next;
        prev->next=temp->next;
        free(temp);
    }
}

void Delete_at_pos(struct node * temp)
{
    struct node* next=temp->next;
    temp->next=next->next;
    free(next);
}

void Insert_at_End(struct node ** head)
{
    struct node * newNode=createNode();
    if(*head==NULL)
    {
        *head=newNode;
        newNode->next=newNode;
    }
    else
    {
        struct node*temp=*head;
        while(temp->next!=*head)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=*head;
    }
}
void Insert_at_pos(struct node *temp)
{
    struct node * newNode=createNode();
    newNode->next=temp->next;
    temp->next=newNode;
}

int main()
{
struct node * head,*temp;
head,temp=NULL;
int choice=1;
printf("Creating the Linked List ..........\n");
while(choice)
{
    struct node *newNode = createNode();
    if(head==NULL)
    {
        head = newNode;
        newNode->next=head;
        temp=newNode;
    }
    else
    {
        temp->next=newNode;
        newNode->next=head;
        temp=newNode;
    }
    printf("if you want to add one more node press 1 or 0 to exit");
    scanf("%d",&choice);
}
display(head);
choice=1;
while(choice)
{
    printf("Select the choice.......\n");
        printf("\n1) Insert At Begning\n");
        printf("2) Insert At End\n");
        printf("3) Insert After the Position\n");
        printf("4) Delete From Begning\n");
        printf("5) Delete from End\n");
        printf("6) Delete node after a given Position\n");
        printf("7) Display\n");
        printf("8) Exit...................\n");
        printf("\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("Inserting at the Beginning \n");
        Insert_at_Beg(head);
        break;
        case 2:
        printf("Inserting at the End \n");
        Insert_at_End(head);
        break;
        case 3:
        printf("Inserting after the Position \n");
        int pos;
        printf("Enter the position after which you want to insert the node\n");
        scanf("%d",&pos);
        struct node * temp=head;
        for(int i=1;i<pos&& temp->next!=NULL;i++)
        {
            temp=temp->next;
        }
        if(temp!=NULL)
        {
            Insert_after_position(temp);
        }
        else
        {
            printf("Invalid Position\n");
        }
        break;
        case 4:
        printf("Deleting from the Beginning \n");
        Delete_from_Beg(head);
        break;
        case 5:
        printf("Deleting from the End \n");
        Delete_from_End(head);
        break;
        case 6:
        printf("Deleting after the Position \n");
        int pos;
        printf("Enter the position after which you want to delete the node\n");
        scanf("%d",&pos);
        struct node * temp=head;
        for(int i=1;i<pos&& temp->next!=NULL;i++)
        {
            temp=temp->next;
        }
        if(temp!=NULL)
        {
            Delete_after_position(temp);
        }
        else
        {
            printf("Invalid Position\n");
        }
    }
}
return 0;
}