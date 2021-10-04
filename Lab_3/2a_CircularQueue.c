#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Queue {
    int front, rear;
    unsigned capacity;
    int* array;
}Queue;

Queue* createQueue(unsigned capacity)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    printf("Queue of capacity %d created!\n", capacity);
    return queue;
}
bool isFull(Queue* queue)
{
    return ((queue->front == 0 && queue->rear == (queue->capacity) - 1)||(queue->front == queue->rear+1));
}

bool isEmpty(Queue* queue)
{
    return (queue->front == -1);
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
    else if((queue->rear == (queue->capacity) - 1) && queue->front != 0)
    {
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
    if(queue->front == queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
    }
    else if(queue->front == (queue->capacity - 1))
    {
        queue->front = 0;
    }
    else
    {
        queue->front = queue->front + 1;
    }
    printf("%d has been dequeued\n", item);
    return item;
}

int main()
{
    Queue * queue_1 = createQueue(6);
    enqueue(queue_1, 1);
    enqueue(queue_1, 2);
    enqueue(queue_1, 3);
    enqueue(queue_1, 4);
    enqueue(queue_1, 5);
    enqueue(queue_1, 6);
    enqueue(queue_1, 7);
    dequeue(queue_1);
    dequeue(queue_1);
    dequeue(queue_1);
    dequeue(queue_1);
    dequeue(queue_1);
    dequeue(queue_1);
    dequeue(queue_1);
    enqueue(queue_1, 1);
    enqueue(queue_1, 2);
    enqueue(queue_1, 3);
    enqueue(queue_1, 4);
    enqueue(queue_1, 5);
    enqueue(queue_1, 6);
    enqueue(queue_1, 7);
    dequeue(queue_1);
    dequeue(queue_1);
    dequeue(queue_1);
    dequeue(queue_1);
    dequeue(queue_1);
    dequeue(queue_1);
    dequeue(queue_1);
    enqueue(queue_1, 1);
    enqueue(queue_1, 2);
    enqueue(queue_1, 3);
    enqueue(queue_1, 4);
    enqueue(queue_1, 5);
    enqueue(queue_1, 6);
    enqueue(queue_1, 7);
    dequeue(queue_1);
    dequeue(queue_1);
    dequeue(queue_1);
    dequeue(queue_1);
    dequeue(queue_1);
    dequeue(queue_1);
    dequeue(queue_1);

}