// QueueUsingSLL.c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node{
    int data;
    struct Node * next;
}Node;

typedef struct SinglyLinkedList
{
    Node * start;
    int len;
}SinglyLinkedList;

typedef struct Queue
{
    SinglyLinkedList * sll;
}Queue;

Node * createNode(int item)
{
    Node * temp = (Node *)malloc(sizeof(Node));
    temp->data = item;
    temp->next = NULL;
    return temp;
}

SinglyLinkedList * createSinglyLinkedList()
{
    SinglyLinkedList * sll = (SinglyLinkedList *)malloc(sizeof(SinglyLinkedList));
    sll->len = 0;

    /* Creating a start node that will store the location of the first node.
     * It stores null at the time of declaration.                           */
    sll->start = (Node *)malloc(sizeof(Node));
    sll->start->data = INT_MIN; // Data in the start node is never to be accessed. If INT_MIN is the data displayed, an error has possibly occured
    sll->start->next = NULL;
    return sll;
}

Queue * createQueue()
{
    Queue * queue = (Queue *)malloc(sizeof(Queue));
    queue->sll = createSinglyLinkedList();
    printf("A new queue was created!\n");
    return queue;
}

// Inserts an element at the end of a linked list
void insertAtEnd(SinglyLinkedList * sll, int item)
{
    Node * newnode = createNode(item);
    Node * ptr = sll->start;
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newnode;
    sll->len++;
}

// Deletion at start
int deleteAtStart(SinglyLinkedList * sll)
{
    if(sll->start->next == NULL)
        return INT_MIN;
    Node * ptr = sll->start->next;
    sll->start->next = ptr->next;
    int data = ptr->data;
    free(ptr);
    sll->len--;
    return data;
}
/* Display function provided for illustrative purposes.*/
void display(Queue * queue)
{
    if(queue->sll->start->next == NULL)
    {
        printf("Queue is empty, nothing to display.\n");
        return;
    }
    // Printing data
    Node * ptr = queue->sll->start->next; // Setting pointer to the first element in the singly linked list
    while(ptr != NULL)
    {
        printf("%d      ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Enqueue
void enqueue(Queue * queue, int item)
{
    insertAtEnd(queue->sll, item);
    printf("%d was enqueued in the queue!\n", item);
}

// Dequeue
int dequeue(Queue * queue)
{
    int data = deleteAtStart(queue->sll);
    if(data != INT_MIN)
        printf("%d was dequeued from the queue!\n", data);
    else
        printf("Queue is empty, nothing to dequeue\n");
    return data;
}

int main()
{
    Queue * queue = createQueue();
    enqueue(queue, 10);
    display(queue);
    enqueue(queue, 20);
    display(queue);
    enqueue(queue, 30);
    display(queue);
    dequeue(queue);
    display(queue);
    dequeue(queue);
    display(queue);
    dequeue(queue);
    display(queue);
    dequeue(queue);
    display(queue);
}