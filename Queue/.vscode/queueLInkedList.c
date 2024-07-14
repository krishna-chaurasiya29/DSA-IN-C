#include <stdio.h>
#include <stdlib.h>

Queue* createQueue();
int isEmpty(Queue* q);
void enqueue(Queue* q, int data);
int dequeue(Queue* q);
int peek(Queue* q);
void display(Queue* q);

// Define the Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the Queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Create a new queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Enqueue a new element
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

// Dequeue an element
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

// Peek the front element
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}

// Display the queue elements
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("Queue after enqueuing 10, 20, 30:\n");
    display(q);

    printf("Dequeued element: %d\n", dequeue(q));
    printf("Queue after dequeuing an element:\n");
    display(q);

    printf("Front element: %d\n", peek(q));
    printf("Is the queue empty? %s\n", isEmpty(q) ? "Yes" : "No");

    dequeue(q);
    dequeue(q);

    printf("Queue after dequeuing all elements:\n");
    display(q);

    printf("Is the queue empty? %s\n", isEmpty(q) ? "Yes" : "No");

    return 0;
}
