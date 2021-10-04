// 9_FinalYear.c
/*
*    Consider a scenario where one line is to submit one form. Once the line started 
*    moving the authority realized announced that few students from final year should be 
*    into another line, resulting creation of another line. The formation of other line is 
*    created as: Once the authority gets that the student belong to final year they push them 
*    to other line. The other line starts from the last student that has join the line. At the 
*    end both lines will be displayed on the screen. Write a program to demonstrate the 
*    above scenario.
*    Input: 1,2,3,2,3,4,1,2,4,3
*    Output: 1,2,3,2,3,1,2,3
*    4,4
*    Input: 1,2,3,4
*/

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
    // printf("Queue of capacity %d created!\n", max);
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
    queue->front = queue->front + 1;
    //printf("%d has been dequeued\n", item);
    return item;
}

int main()
{
    Queue * queue = createQueue(20);
    printf("Enter the number of students: \n");
    int n = 0;
    scanf("%d", &n);
    printf("Enter the year of %d students: \n", n);
    for(int i = 0; i < n; i++)
    {
        int x = 0;
        scanf("%d", &x);
        enqueue(queue, x);
    }
    Queue * queue_1 = createQueue(20);
    Queue * queue_2 = createQueue(20);
    for(int i = 0; i < n; i++)
    {
        int x = dequeue(queue);
        if(x == 4)
            enqueue(queue_2, x);
        else
            enqueue(queue_1, x);
    }
    printf("Non-final-year students' queue: ");
    while(!isEmpty(queue_1))
    {
        printf("%d ", dequeue(queue_1));
    }
    printf("\nFinal-year students' queue: ");
    while(!isEmpty(queue_2))
    {
        printf("%d ", dequeue(queue_2));
    }
}