#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *CreateNode()
{
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    return newnode;
}

void Insert_at_Beginning(struct node **head)
{
    struct node* newnode=CreateNode();
    newnode->next=*head;
    *head=newnode;
}

void Insert_at_End(struct node** head)
{
    struct node* newnode=CreateNode();
    struct node* temp=*head;
    while(temp->next !=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}

void Insert_at_Pos(struct node* temp)
{
    struct node * newnode=CreateNode();
    newnode->next=temp->next;
    temp->next=newnode;
}
void Delete_from_beg(struct node**head)
{
    struct node* temp=*head;
    *head=temp->next;
    free(temp);
}

void Delete_from_End(struct node ** head)
{
    struct node* prev;
    struct node* temp=*head;
    while(temp->next !=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
}
void Delete_After_Pos(struct node *temp , struct node* nextnode)
{
    temp->next=nextnode->next;
    free(nextnode);
}
void Display(struct node * head)
{
    struct node* temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
printf("\n");
}
void LengthCount(struct node *head)
{
    int count=0;
    struct node* temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("\nLength of Linked List is :- %d\n",count);
}
int main()
{
    struct node *temp;
    struct node *head=NULL;
    int choice=1;
    printf("Creating & Adding Fisrt Element in the Linked list\n");
    while(choice)
    {
        struct node * newnode=CreateNode();
        if(head==NULL)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        printf("Do you want to add more elements in the Linked list press any number except 0 to exit\n");
        scanf("%d",&choice);
    }
    Display(head);
    LengthCount(head);
    choice=1;
    while(choice)
    {
        printf("Select the choice.......\n");
        printf("1.  Insert at the beginning\n");
        printf("2.  Insert at the end\n");
        printf("3.  Insert after the given position\n");
        printf("4.  Insert At the given position\n");
        printf("5.  Delete from the beginning\n");
        printf("6.  Delete from the end\n");
        printf("7.  Delete After the Position\n");
        printf("8.  Display List of the elements\n");
        printf("9.  Length of the Linked List\n");
        printf("10. Exit......\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Inserting Data at Beginning\n");
                Insert_at_Beginning(&head);
                break;
            }
            case 2:
            {
                printf("Inserting at End\n");
                Insert_at_End(&head);
                break;
            }
            case 3:
            {
                int pos;
                printf("Enter the Postion you want to Enter the data\n");
                scanf("%d",&pos);
                temp=head;
                for(int i=1; i<pos && temp!=NULL ; i++)
                {
                    temp=temp->next;
                }
                if(temp!=NULL)
                {
                    printf("Enter the data you want to insert\n");
                    Insert_at_Pos(temp);
                }
                else{
                    printf("Invalid Position\n");
                }
                break;
            }
            case 4:
            {
                int pos;
                printf("Enter the Postion you want to Enter the data\n");
                scanf("%d",&pos);
                temp=head;
                for(int i=1; i<pos-1 && temp!=NULL ; i++)
                {
                    temp=temp->next;
                }
                if(temp!=NULL)
                {
                    printf("Enter the data you want to insert\n");
                    Insert_at_Pos(temp);
                }
                else{
                    printf("Invalid Position\n");
                }
                break;
            }
            case 5:
            {
                printf("Deleting from Beginning\n");
                Delete_from_Beginning(&head);
                break;
            }
            case 6:
            {
                printf("Deleting from End\n");
                Delete_from_End(&head);
                break;
            }
            case 7:
            {
                int pos;
                printf("Enter the Postion after which you want to Delete the data\n");
                scanf("%d",&pos);
                struct node *nextnode;
                temp=head;
                for(int i=1; i<pos && temp!=NULL ; i++)
                {
                    temp=temp->next;
                    nextnode=temp->next;
                }
                if(temp!=NULL)
                {
                    Delete_After_Pos(temp,nextnode);
                }
                else
                {
                    printf("Invalid Position\n");
                }
                break;
            }
            case 8:
            {
                Display(head);
                break;
            }
            case 9:
            {
                LengthCount(head);
                break;
            }
            case 10:
            {
                printf("Exiting............\n");
                exit(0);
            }
            default:
            {
                printf("Invalid Choice\n");
            }
        }
    }
        printf("Updated LinkedList\n");
        Display(head);
        LengthCount(head);
}
