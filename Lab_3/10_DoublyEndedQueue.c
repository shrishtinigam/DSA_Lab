// 10_DoublyEndedQueue.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct DQueue {
    int front, rear;
    unsigned max;
    int* array;
}DQueue;

DQueue* createDQueue(unsigned max)
{
    DQueue* queue = (DQueue*)malloc(sizeof(DQueue));
    queue->max = max;
    queue->front = -1;
    queue->rear = -1;
    queue->array = (int*)malloc(queue->max * sizeof(int));
    printf("Queue of capacity %d created!\n", max);
    return queue;
}
bool isFull(DQueue* queue)
{
    return ((queue->front == 0 && queue->rear == (queue->max) - 1)||(queue->front == queue->rear + 1));
}

bool isEmpty(DQueue* queue)
{
    return ((queue->front == -1) && (queue->rear == -1));
}

void push_back(DQueue* queue, int item)
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
    else if((queue->rear == (queue->max) - 1) && queue->front != 0)
    {
        queue->rear = 0;
    }
    else
    {
        queue->rear = queue->rear + 1;
    }
    queue->array[queue->rear] = item;
    printf("%d was pushed back to queue\n", item);
}

void push_front(DQueue* queue, int item)
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
    else if(queue->front == 0)
    {
        queue->front = queue->max - 1;
    }
    else
    {
        queue->front = queue->front - 1;
    }
    queue->array[queue->front] = item;
    printf("%d was pushed in front of queue\n", item);
}

int pop_front(DQueue* queue)
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
    else if(queue->front == (queue->max - 1))
    {
        queue->front = 0;
    }
    else
    {
        queue->front = queue->front + 1;
    }
    printf("%d was popped from front\n", item);
    return item;
}

int pop_rear(DQueue* queue)
{
    if (isEmpty(queue))
    {
        printf("Queue Underflow\n");
        return INT_MIN;
    }
    int item = queue->array[queue->rear];
    if(queue->front == queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
    }
    else if(queue->rear == 0)
    {
        queue->rear = queue->max - 1;
    }
    else
    {
        queue->rear = queue->rear - 1;
    }
    printf("%d was popped from rear\n", item);
    return item;
}

// This function should not be available, but it is used here for illustration purposes
void printDQ(DQueue * queue)
{
    if(isEmpty(queue))
    {
        printf("Dqueue is empty\n");
        return;
    }
    
    if(queue->front <= queue->rear)
    {
        for(int i = queue->front; i <= queue->rear; i++)
        {
            printf("%d ", queue->array[i]);
        }
    }
    else{
        for(int i = queue->front; i < queue->max; i++)
        {
            printf("%d ", queue->array[i]);
        }
        for(int i = 0; i <= queue->rear; i++)
        {
            printf("%d ", queue->array[i]);
        }
    }
    printf("\n");
}

int main()
{
    DQueue * queue_1 = createDQueue(10);
    push_front(queue_1, 10);
    printDQ(queue_1);
    push_back(queue_1, 20);
    printDQ(queue_1);
    push_front(queue_1, 30);
    printDQ(queue_1);
    push_back(queue_1, 40);
    printDQ(queue_1);
    push_front(queue_1, 50);
    printDQ(queue_1);
    push_back(queue_1, 60);
    printDQ(queue_1);
    push_front(queue_1, 70);
    printDQ(queue_1);
    push_back(queue_1, 80);
    printDQ(queue_1);
    push_front(queue_1, 90);
    printDQ(queue_1);
    push_back(queue_1, 100);
    printDQ(queue_1);
    pop_front(queue_1);
    printDQ(queue_1);
    pop_rear(queue_1);
    printDQ(queue_1);
    pop_front(queue_1);
    printDQ(queue_1);
    pop_rear(queue_1);
    printDQ(queue_1);
    pop_front(queue_1);
    printDQ(queue_1);
    pop_rear(queue_1);
    printDQ(queue_1);
    pop_front(queue_1);
    printDQ(queue_1);
    pop_rear(queue_1);
    printDQ(queue_1);
    pop_front(queue_1);
    printDQ(queue_1);
    pop_rear(queue_1);
    printDQ(queue_1);
}