 //Doubly_Linkedlist
#include<stdio.h>
#include<stdlib.h>
struct node *Creatnode();
void Display(struct node *head);
void Insert_at_beg(struct node **head);
void Insert_at_end(struct node **head);
void Insert_after_pos(struct node* temp);
void Delete_from_beg(struct node **head);
void Delete_from_end(struct node **head);
void Delete_after_pos(struct node *temp);
void LengthCount(struct node *head);

struct node
{
    int data;
    struct node *next;
    struct node*prev;
};
struct node *head,*temp;

struct node *Creatnode()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

void Insert_at_beg(struct node **head)
{
    struct node *newnode=Creatnode();
    newnode->next=*head;
    (*head)->prev=newnode;
    *head=newnode;
}

void Insert_at_end(struct node **head)
{
    struct node *newnode=Creatnode();
    temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    temp=newnode;
}

void Insert_after_pos(struct node* temp)
{
    struct node *newnode=Creatnode();
    newnode->prev=temp;
    newnode->next=temp->next;
    temp->next=newnode;
    temp->next->prev=newnode;
}

void Delete_from_beg(struct node **head)
{
    temp=*head;
    temp->next->prev=NULL;
    *head=temp->next;
    free(temp);
}

void Delete_from_end(struct node **head)
{
    temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
}

void Delete_after_pos(struct node *temp)
{
    struct node *todelete=temp->next;
    todelete->next->prev=temp;
    temp->next=todelete->next;
    free(todelete);
}

void Display(struct node *head)
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void LengthCount(struct node *head)
{
    int count=0;
    struct node* temp;
    temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("\nLength Of Linked List is :- %d\n",count); 
}
int main()
{
    head=NULL;
    int choice=1;
    printf("First Creat a Doubly LinkedList\n");
    while(choice)
    {
         struct node *newnode=Creatnode();
        if(head==NULL)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=temp->next;
        }
        
        printf("Do you want to insert new node 1/0\n");
        scanf("%d",&choice);
    }

printf("LinkedList Created\n");
Display(head);
LengthCount(head);
choice=1;

while(choice)
{
    printf("\n1) Insert at Begning\n");
    printf("2) Insert at end\n");
    printf("3) Insert after ginev position\n");
    printf("4) Delete from Begning\n");
    printf("5) Delete from end\n");
    printf("6) Delete after the Given position\n");
    printf("0)Exit\n");
    
    printf("Enter the choice\n");
    scanf("%d",&choice);
    
    switch(choice)
    {
        case 1:
        printf("To insert at Begning\n");
        Insert_at_beg(&head);
        break;
        
        case 2:
        printf("To insert at end\n");
        Insert_at_end(&head);
        break;
        
        case 3:
        int pos;
        printf("Give position\n");
        scanf("%d",&pos);
        
        temp=head;
        for(int i=1;i<pos && temp!=NULL;i++)
        {
            temp=temp->next;
        }
        if(temp!=NULL && temp->next!=NULL)
        {
            printf("Inserting After Given position\n");
            Insert_after_pos(temp);
            
        }
        else{
            printf("last node or position not found\n");
        }
        break;
        
        case 4:
        printf("Deleting from Begning\n");
        Delete_from_beg(&head);
        break;
        
        case 5:
        printf("Deleting from endn");
        Delete_from_end(&head);
        break;
        
        case 6:
        int position;
        printf("ENter the position\n");
        scanf("%d",&position);
        temp=head;
        for(int i=1;i<position && temp!=NULL;i++)
        {
            temp=temp->next;
        }
        if(temp!=NULL && temp->next!=NULL)
        {
            printf("Deleting after given position\n");
            Delete_after_pos(temp);
        }
        else
        {
            printf("Last node or position not not found\n");
        }
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
