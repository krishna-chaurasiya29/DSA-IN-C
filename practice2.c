//ciruclar queue

#include<stdio.h>
#include<stdlib.h>
#define size 5

typedef struct 
{
    int front;
    int rear;
    int arr[size];
}CircularQueue;

CircularQueue * CreateQueue()
{
    CircularQueue *queue = (CircularQueue *)malloc(sizeof(CircularQueue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isFull(CircularQueue * queue)
{
    return (queue->front==0 && queue->rear==size-1) || (queue->rear == (queue->front-1)%(size-1));
}

int isEmpty(CircularQueue* queue)
{
    return queue->front == -1;
}

void enqueue(CircularQueue * queue)
{
    if(isFull(queue))
    {
    printf("Queue is full\n");
    return;
    }

    if(isEmpty(queue))
    queue->front,queue->rear = 0;
    else if(queue->rear==size-1 && queue->front!=0)
    queue->rear = 0;
    else
    queue->rear++;
    printf("Enter the value you want to Enter:-");
    scanf("%d",queue->arr[queue->rear]);
    printf("Enqued value is %d",queue->arr[queue->rear]);
}

void dequeue(CircularQueue *queue)
{
    if(isEmpty(queue))
    {
    printf("Queue is Empty\n");
    return;
    }
    int item=queue->arr[queue->rear];
    if(queue->rear==queue->front)
    queue->front,queue->rear = -1;
    else if(queue->front==size-1)
    queue->front = 0;
    else
    queue->front++;
    printf("The item deleted is :-%d\n",item);
}

void peek(CircularQueue* queue)
{
    if(isEmpty(queue))
    {
    printf("Queue is Empty\n");
    return;
    }
    printf("The Peak value is %d",queue->rear);
}
int main()
{
    CircularQueue *queue = CreateQueue();
    int choice ,value;
    while(1)
    {
        printf("Select The Operation from the given Options :\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Check if Queue is Empty\n");
        printf("5. Check if Queue is Full\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            enqueue(&queue);
            break;

            case 2:
            dequeue(&queue);
            break;

            case 3:
            peek(&queue);
            break;

            case 4:
            if(isEmpty(queue))
            printf("Queue is Empty\n");
            else
            printf("Queue is not Empty\n");
            break;

            case 5:
            if(isFull(queue))
            printf("Queue is Full\n");
            else
            printf("Queue is not Full\n");
            break;

            case 6:
            display(queue);
            break;

            case 7:
            free(queue->arr);
            free(queue);
            exit(0);

            default:
            printf("Invalid Choice broo\n");
        }
    }
}











