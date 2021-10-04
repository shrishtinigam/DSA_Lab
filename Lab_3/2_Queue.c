// 2_Queue.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Queue {
    int front, rear;
    unsigned max;
    int* array;
}Queue;

struct Queue* createQueue(unsigned max)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->max = max;
    queue->front = -1;
    queue->rear = -1;
    queue->array = (int*)malloc(queue->max * sizeof(int));
    printf("Queue of capacity %d created!\n", max);
    return queue;
}
bool isFull(Queue* queue)
{
    return (queue->rear == (queue->max) - 1);
}

bool isEmpty(Queue* queue)
{
    return (queue->front == -1 || queue->front > queue->rear);
}

void enqueue(Queue* queue, int item)
{
    if (isFull(queue))
    {
        printf("Queue Overflow\n");
        return;
    }
    if(queue->front == -1 && queue->rear == -1)
    {
        queue->front = 0;
        queue->rear = 0;
    }
    else
    {
        queue->rear = queue->rear + 1;
    }
    queue->array[queue->rear] = item;
    printf("%d enqueued to queue\n", item);
}

int dequeue(Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("Queue Underflow\n");
        return INT_MIN;
    }
    int item = queue->array[queue->front];
    queue->front = queue->front + 1;
    printf("%d has been dequeued\n", item);
    return item;
}

// This function should not be available, but it is used here for illustration purposes
void printQueue(Queue * queue)
{
    if(isEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Current queue: "); 
    for(int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int main()
{
    Queue * queue_1 = createQueue(6);
    enqueue(queue_1, 1);
    printQueue(queue_1);
    enqueue(queue_1, 2);
    printQueue(queue_1);
    enqueue(queue_1, 3);
    printQueue(queue_1);
    enqueue(queue_1, 4);
    printQueue(queue_1);
    dequeue(queue_1); // A dequeue
    printQueue(queue_1);
    enqueue(queue_1, 5);
    printQueue(queue_1);
    enqueue(queue_1, 6);
    printQueue(queue_1);
    enqueue(queue_1, 7);
    printQueue(queue_1);
    dequeue(queue_1);
    printQueue(queue_1);
    dequeue(queue_1);
    printQueue(queue_1);
    dequeue(queue_1);
    printQueue(queue_1);
    dequeue(queue_1);
    printQueue(queue_1);
    dequeue(queue_1);
    printQueue(queue_1);
    dequeue(queue_1);
    printQueue(queue_1);
    // Once the a full queue has been dequeued completely, it can't be used again.
    enqueue(queue_1, 1);
    printQueue(queue_1);
    enqueue(queue_1, 2);
    printQueue(queue_1);
    enqueue(queue_1, 3);
    printQueue(queue_1);
    enqueue(queue_1, 4);
    printQueue(queue_1);
    enqueue(queue_1, 5);
    printQueue(queue_1);
    enqueue(queue_1, 6);
    printQueue(queue_1);
    enqueue(queue_1, 7);
}