// StackUsingSLL.c
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

typedef struct Stack
{
    SinglyLinkedList * sll;
}Stack;

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

Stack * createStack()
{
    Stack * stack = (Stack *)malloc(sizeof(Stack));
    stack->sll = createSinglyLinkedList();
    printf("A new stack was created!\n");
    return stack;
}

// Inserts an element at the start of a linked list
void insertAtStart(SinglyLinkedList * sll, int item)
{
    Node * newnode = createNode(item);
    newnode->next = sll->start->next;
    sll->start->next = newnode;
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
void display(Stack * stack)
{
    if(stack->sll->start->next == NULL)
    {
        printf("Stack is empty, nothing to display.\n");
        return;
    }
    // Printing data
    Node * ptr = stack->sll->start->next; // Setting pointer to the first element in the singly linked list
    while(ptr != NULL)
    {
        printf("%d      ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Push
void push(Stack * stack, int item)
{
    insertAtStart(stack->sll, item);
    printf("%d pushed to stack!\n", item);
}

// Pop
int pop(Stack * stack)
{
    int data = deleteAtStart(stack->sll);
    if(data != INT_MIN)
        printf("%d popped from the stack!\n", data);
    else
        printf("Stack is empty, nothing to pop.\n");
    return data;
}

int main()
{
    Stack * stack = createStack();
    push(stack, 10);
    display(stack);
    push(stack, 20);
    display(stack);
    push(stack, 30);
    display(stack);
    push(stack, 40);
    display(stack);
    pop(stack);
    display(stack);
    pop(stack);
    display(stack);
    pop(stack);
    display(stack);
    pop(stack);
    display(stack);
    pop(stack);
    display(stack);
    pop(stack);
    display(stack);
}