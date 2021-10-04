// 3b_StackUsingQueuePopCostly.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Queue {
    int front, rear;
    unsigned max;
    unsigned size;
    int* array;
}Queue;

typedef struct Stack {
    Queue * queue_1;
    Queue * queue_2;
}Stack;

Stack * createStack(unsigned max)
{
    Stack * stack = (Stack*)malloc(sizeof(Stack));
    stack->queue_1 = (Queue*)malloc(sizeof(Queue));
    stack->queue_1->max = max;
    stack->queue_1->front = -1;
    stack->queue_1->rear = -1;
    stack->queue_1->array = (int*)malloc(stack->queue_2->max * sizeof(int));
    stack->queue_1->size = 0;

    stack->queue_2 = (Queue*)malloc(sizeof(Queue));
    stack->queue_2->max = max;
    stack->queue_2->front = -1;
    stack->queue_2->rear = -1;
    stack->queue_2->array = (int*)malloc(stack->queue_2->max * sizeof(int));
    stack->queue_1->size = 0;

    printf("Stack of capacity %d has been created!\n", max);
    return stack;
}
bool isFull(Queue* queue)
{
    return ((queue->front == 0 && queue->rear == (queue->max) - 1)||(queue->front == queue->rear+1));
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
    else if((queue->rear == (queue->max) - 1) && queue->front != 0)
    {
        queue->rear = 0;
    }
    else
    {
        queue->rear = queue->rear + 1;
    }
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    return;
    //printf("%d enqueued to queue\n", item);
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
    else if(queue->front == (queue->max - 1))
    {
        queue->front = 0;
    }
    else
    {
        queue->front = queue->front + 1;
    }
    queue->size = queue->size - 1;
    //printf("%d has been dequeued\n", item);
    return item;
}

void push(Stack * stack, int item)
{
    if(isFull(stack->queue_1))
    {
        printf("Stack Overflow\n");
        return;
    }
    enqueue(stack->queue_1, item);
    printf("%d has been pushed to the stack!\n", item);
}

int pop(Stack * stack)
{
    if(isEmpty(stack->queue_1))
    {
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    while(stack->queue_1->size != 1)
    {
        enqueue(stack->queue_2, dequeue(stack->queue_1));
    }
    int item = dequeue(stack->queue_1);
    while(!isEmpty(stack->queue_2))
    {
        enqueue(stack->queue_1, dequeue(stack->queue_2));
    }
    printf("%d was popped off the stack!\n", item);
    return item;
}

// This function should not be available, but it is used here for illustration purposes
void printStack(Queue * queue)
{
    if(isEmpty(queue))
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Current stack: "); 
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
    Stack * stack_1 = createStack(6);
    push(stack_1, 23);
    printStack(stack_1->queue_1);
    push(stack_1, 56);
    printStack(stack_1->queue_1);
    push(stack_1, 37);
    printStack(stack_1->queue_1);
    push(stack_1, 92);
    printStack(stack_1->queue_1);
    push(stack_1, 10);
    printStack(stack_1->queue_1);
    push(stack_1, 41);
    printStack(stack_1->queue_1);
    push(stack_1, 41);
    pop(stack_1);
    printStack(stack_1->queue_1);
    pop(stack_1);
    printStack(stack_1->queue_1);
    pop(stack_1);
    printStack(stack_1->queue_1);
    pop(stack_1);
    printStack(stack_1->queue_1);
    pop(stack_1);
    printStack(stack_1->queue_1);
    pop(stack_1);
    printStack(stack_1->queue_1);
    pop(stack_1);
}