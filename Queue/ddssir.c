#include <stdio.h>
# define size 50
int a[size];
int f=-1,r=-1;
void Enqueue ()
{
    int x;
    if(r==size-1)
    {
    printf("\nQueue is overflow");
    }
    else
    {
    printf("\nEnter the value to be inserted : ");
    scanf("%d",&x);
    if(f==-1)
    f=0;
    a[++r]=x;
    }

}

void Dequeue ()
{
    printf("\nDeleted element of the Queue : %d ",a[f]);

        if(f==-1||f==r)
        {
        printf("\nQueue is underflow");
        }
        else
        {
        f++;
        }
}
void Show ()
{
    if(f==-1)
    {
      printf("\nQueue is empty");
    }
    else 
    {
      printf("\nThe elements in the Queue\n");
      for(int i=f;i<=r;i++)
      {
        printf("%d",a[i]);
        printf("\n");
      }
    }
    
}
int main()
{
  int choice;
  while(1)
  {
    printf("\n1.Enqueuen\n2.Dequeue\n3.Show");
    printf("\nEnter your choce[1/2/3]\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:Enqueue();break;
      case 2:Dequeue();break;
      case 3: Show();break;
      default:printf("\nwrong choice\n");

    }

    
  }
    
}