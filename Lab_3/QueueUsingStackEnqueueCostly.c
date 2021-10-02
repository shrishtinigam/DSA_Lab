// QueueUsingStackEnqueueCostly.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Stack {
    int top;
    unsigned max;
    int * array;
}Stack;

typedef struct Queue {
    Stack * stack_1;
    Stack * stack_2;
}Queue;

Queue * createQueue(unsigned max)
{
    Queue * queue = (Queue*)malloc(sizeof(Queue));
    queue->stack_1 = (Stack *) malloc(sizeof(Stack));
    queue->stack_1->max = max;
    queue->stack_1->top = -1;
    queue->stack_1->array = (int *) malloc(queue->stack_1->max * sizeof(int));
    
    queue->stack_2 = (Stack *) malloc(sizeof(Stack));
    queue->stack_2->max = max;
    queue->stack_2->top = -1;
    queue->stack_2->array = (int *) malloc(queue->stack_2->max * sizeof(int));

    printf("Queue of capacity %d has been created!\n", max);
    return queue;
}

bool isFull(Stack * stack)
{
    return stack->top == stack->max - 1;
}

bool isEmpty(Stack * stack)
{
    return stack->top == -1;
}

void push (Stack * stack, int x)
{
    if(isFull(stack))
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->top = stack->top + 1;
    stack->array[stack->top] = x;
    //printf("%d pushed to stack\n", x);
}

int pop (Stack * stack)
{
    if(isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

void enqueue(Queue * queue, int item)
{
    if(isFull(queue->stack_1))
    {
        printf("Queue Overflow\n");
        return;
    }
    if(isEmpty(queue->stack_1))
    {
        push(queue->stack_1, item);
        printf("%d was queued!\n", item);
        return;
    }
    while(!isEmpty(queue->stack_1))
    {
        push(queue->stack_2, pop(queue->stack_1));
    }
    push( queue->stack_1, item);
    while(!isEmpty(queue->stack_2))
    {
        push(queue->stack_1, pop(queue->stack_2));
    }
    printf("%d was queued!\n", item);
}

int dequeue(Queue * queue)
{
    if(isEmpty(queue->stack_1))
    {
        printf("Queue Underflow");
        return INT_MIN;
    }
    int item = pop(queue->stack_1);
    printf("%d was dequeued!\n", item);
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
}