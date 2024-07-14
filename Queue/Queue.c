#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    int size;
    int rare;
    int front;
    int *arr;
}Queue;

Queue *createQueue()
{
    Queue * queue= (Queue*)malloc(sizeof(Queue));
    queue->rare=-1;
    queue->front=-1;
    printf("Enter the size of the queue:-");
    scanf("%d", &queue->size);
    queue->arr=(int*)malloc(sizeof(int)*queue->size);
    return queue;
}

int isFull(Queue * queue)
{
    return queue->rare==queue->size-1;
}

int isEmpty(Queue * queue)
{
    return queue->front==-1 || queue->front > queue->rare;
}

int enqueue(Queue* queue,int value)
{
    if(isFull(queue))
    {
        printf("Queue is full\n");
        return 0;
    }
    if(queue->front==-1)
    {
        queue->front=0;
    }
    queue->arr[++queue->rare]=value;
    printf("Enqueued Value is %d\n", value);
    return 1;
}

int dequeue(Queue * queue)
{
    if(isEmpty(queue))
    {
        printf("Queue is empty\n");
        return 0;
    }
    else
    {
        printf("Dequeued Value is %d\n", queue->arr[queue->front]);
        queue->front++;
        return 1;
    }
}

int peek(Queue * queue)
{
    if(isEmpty(queue))
    {
        printf("Unable to Find Peek, Queue is empty\n");
        return 0;
    }
    printf("Front Element in the Queue :-%d\n", queue->arr[queue->front]);
    return 1;
}

void display(Queue *queue) 
{
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Queue elements are:\n");
        for (int i = queue->front; i <= queue->rare; i++) {
            printf("%d ", queue->arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    Queue *queue = createQueue();
    int choice, value;
    while(1)
    {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Check if Queue is Empty\n");
        printf("4. Check if Queue is Full\n");
        printf("5. Peek\n");
        printf("6. Display Queue\n");
        printf("7. Last Element\n");
        printf("8. Total Elements present in Queue\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d",&value);
            enqueue(queue, value);
            break;

            case 2:
            dequeue(queue);
            break;

            case 3:
            if(isEmpty(queue))
            printf("Queue is empty\n");
            else
            printf("Queue is not empty\n");
            break;

            case 4:
            if(isFull(queue))
            printf("Queue is full\n");
            else
            printf("Queue is not full\n");
            break;

            case 5:
            peek(queue);
            break;

            case 6:
            display(queue);
            break;

            case 7:
            if(!isEmpty(queue))
                printf("Last Element is :-%d\n", queue->arr[queue->rare]);
            else
                printf("Queue is empty\n");
            break;

            case 8:
            if(!isEmpty(queue))
                printf("Total Element Present is Queue is:-%d\n", queue->rare - queue->front + 1);
            else
                printf("Queue is empty\n");
            break;

            case 9:
            free(queue->arr);
            free(queue);
            printf("Exiting.........\n");
            exit(0);

            default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}
// queue is based on fifo the first element entered will be removed first 