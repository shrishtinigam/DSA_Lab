// CircularDoublyLinkedList.c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
    A circular doubly linked list here is defined by its "start".
    "start" is a node pointer that points to the first element.

    Here, start is a proper node with memory allocated to it.
    Note that start doesn't store any actual data.
    The next of the start node stores the location of the first element in the doubly linked list. 
    The prev of the start node is NULL and never accessed.
    The data of the start node is INT_MIN and never accessed.

    Thus, if we create a circular doubly linked list "dcll", dcll->start->next gives us the first element.

    The first element's prev node is the address of the last node. (Thus, it is not connected to the start node.)
    The last elements's next node is the address of the first node. Thus the linked list is circular.

    "len" stores the number of elements in the linked list. This can be easily calculated,
    however it is added to make things easier and for illustration. It can be removed. 
    Functions are written independent of len.
    
    Functions provided: 

    insertAtStart
    insertAtEnd
    insertAtPosition

    display
    search

    deleteAtStart
    deleteAtEnd
    deleteAtPosition -> not done
*/

typedef struct Node{
    int data;
    struct Node * prev;
    struct Node * next;
}Node;

typedef struct CircularDoublyLinkedList
{
    Node * start;
    int len;
}CircularDoublyLinkedList;

Node * createNode(int item)
{
    Node * temp = (Node *)malloc(sizeof(Node));
    temp->data = item;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

CircularDoublyLinkedList * createCircularDoublyLinkedList()
{
    CircularDoublyLinkedList * dcll = (CircularDoublyLinkedList *)malloc(sizeof(CircularDoublyLinkedList));
    dcll->len = 0;
    dcll->start = (Node *)malloc(sizeof(Node));
    dcll->start->data = INT_MIN; // Data in the start node is never to be accessed. If INT_MIN is the data displayed, an error has possibly occured
    dcll->start->next = NULL;
    dcll->start->prev = NULL;
    printf("A new circular doubly linked list was created!\n");
    return dcll;
}

/* Insertion */

// Inserts an element at the start of a linked list
void insertAtStart(CircularDoublyLinkedList * dcll, int item)
{
    Node * newnode = createNode(item);
    if(dcll->start->next == NULL) // If dcll is empty
    {
        dcll->start->next = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;
    }
    else
    {
        newnode->next = dcll->start->next;
        newnode->prev = dcll->start->next->prev;
        dcll->start->next->prev->next = newnode;
        dcll->start->next->prev = newnode;
        dcll->start->next = newnode;
    }
    printf("%d was inserted at the start of the circular doubly linked list!\n", item);
    dcll->len++;
}

// Inserts an element at the end of a linked list
void insertAtEnd(CircularDoublyLinkedList * dcll, int item)
{
    Node * newnode = createNode(item);
    if(dcll->start->next == NULL) // If dcll is empty
    {
        dcll->start->next = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;
    }
    else
    {
        newnode->next = dcll->start->next;
        newnode->prev = dcll->start->next->prev;
        dcll->start->next->prev->next = newnode;
        dcll->start->next->prev = newnode;
    }
    printf("%d was inserted at the end of the circular doubly linked list!\n", item);
    dcll->len++;
}

// Inserts an element at a specified position.
// Here, position is determined by usual 1-base counting. If position = 5, item will be the fifth element in the linked list
void insertAtPosition(CircularDoublyLinkedList * dcll, int item, int position)
{
    Node * newnode = createNode(item);
    Node * ptr = dcll->start;
    for(int i = 0; i < (position - 1); i++)
    {
        if(ptr->next == dcll->start->next && i + 1 < position && ptr->data != INT_MIN)
        {
            printf("Invalid Location\n");
            return;
        }
        ptr = ptr->next;
    }
    if(dcll->start->next == NULL) // If dcll is empty
    {
        if(position != 1)
        {
            printf("Invalid Location\n");
            return;
        }
        newnode->next = newnode;
        newnode->prev = newnode;
    }
    else
    {
        newnode->next = ptr->next;
        newnode->prev = ptr->next->prev;
        if(position == 1)
            ptr->next->prev->next = newnode; // for 1st position
        ptr->next->prev = newnode;
    }
    ptr->next = newnode;
    printf("%d was inserted at position %d of the circular doubly linked list!\n", item, position);
    dcll->len++;
}

/* Traversal */

// Display function provided for illustrative purposes.
void display(CircularDoublyLinkedList * dcll)
{
    if(dcll->start->next == NULL)
    {
        printf("Circular doubly linked list is empty, nothing to display.\n");
        return;
    }
    // Printing data
    Node * ptr = dcll->start->next;
    if(ptr == ptr->next)
        printf("%d      ", ptr->data);
    else
    {
        while(ptr->next != dcll->start->next)
        {
            printf("%d       ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d      ", ptr->data);
    }
    // Printing the location
    Node * ptr2 = dcll->start->next; 
    printf("\n%d ", ptr->next);
    while(ptr2->next != dcll->start->next)
    {
        printf("%d ", ptr2->next);
        ptr2 = ptr2->next;
    }
    printf("%d ", ptr2->next);  // -> to check circular nature
    printf("\n");
}

// Returns the 1-base position of the first occurance of data.
int search(CircularDoublyLinkedList * dcll, int item)
{
    if(dcll->start->next == NULL)
    {
        printf("Empty circular doubly linked list, nothing to search for.\n");
        return INT_MIN;
    }
    int count = 1;
    Node * ptr = dcll->start->next;
    while(ptr->data != item)
    {
        if(ptr->data != item && ptr->next == dcll->start->next)
        {
            printf("%d not found in the circular doubly linked list.\n", item);
            return INT_MIN;
        }
        ptr = ptr->next;
        count++;
    }
    printf("%d found at %d position in the circular doubly linked list.\n", item, count);
    return count;
}

/* Deletion */

// Deletion at start
int deleteAtStart(CircularDoublyLinkedList * dcll)
{
    if(dcll->start->next == NULL)
    {
        printf("Circular Doubly Linked List is empty, nothing to delete\n");
        return INT_MIN;
    }
    Node * ptr = dcll->start->next;
    if(ptr->next == ptr)
        dcll->start->next = NULL;
    else
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        dcll->start->next = ptr->next;
    }
    int data = ptr->data;
    free(ptr);
    printf("%d was deleted from the start of the circular doubly linked list.\n", data);
    dcll->len--;
    return data;
}

// Deletion at end
int deleteAtEnd(CircularDoublyLinkedList * dcll)
{
    if(dcll->start->next == NULL)
    {
        printf("Circular Doubly Linked List is empty, nothing to delete\n");
        return INT_MIN;
    }
    Node * ptr = dcll->start->next;
    if(ptr->next == ptr)
        dcll->start->next = NULL;
    else
    {
        ptr = ptr->prev;
        dcll->start->next->prev = ptr->prev;
        ptr->prev->next = dcll->start->next;
    }
    int data = ptr->data;
    free(ptr);
    printf("%d was deleted from the end of the circular doubly linked list.\n", data);
    dcll->len--;
    return data;
}

// Deletion of an element at a particular position
// Here, position is determined by usual 1-base counting.
int deleteAtPosition(CircularDoublyLinkedList * dcll, int position)
{
    if(dcll->start->next == NULL)
    {
        printf("Circular doubly linked list is empty, nothing to delete\n");
        return INT_MIN;
    }
    Node * ptr = dcll->start;
    for(int i = 0; i < position; i++)
    {   
        if(ptr->next == dcll->start->next && i < position && ptr->data != INT_MIN)
        {
            printf("Invalid Location\n");
            return INT_MIN;
        }
        ptr = ptr->next;
    }
    if(ptr->next == ptr)
        dcll->start->next = NULL;
    else
    {
        if(ptr->next == dcll->start->next) // deletion at end
        {
            dcll->start->next->prev = ptr->prev;
            ptr->prev->next = dcll->start->next;
        }
        else
        {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            if(position == 1) // deletion at beginning
                dcll->start->next = ptr->next;
        }
    }
    int data = ptr->data;
    free(ptr);
    dcll->len--;
    printf("%d was deleted from %d position of the circular doubly linked list.\n", data, position);
    return data;
}

void introduction()
{
    printf("~ To display the DCLL, enter 1.\n\n");
    printf("INSERTION\n~ To insert an element at the start DCLL, enter 2 and the element.\n");
    printf("~ To insert an element at the end of the DCLL, enter 3 and the element.\n");
    printf("~ To insert an element at a specific position of the DCLL, enter 4, the element and the position.\n\n");
    printf("DELETION\n~ To delete an element from the start DCLL, enter 5.\n");
    printf("~ To delete an element from the end of the DCLL, enter 6.\n");
    printf("~ To delete an element from a specific position of the DCLL, enter 7 and the position.\n");
    printf("\n~ To search for an element, enter 8 and the element.\n\n");
    printf("~ To print this message again, enter 9.\n");
    printf("~ To exit, enter 0.\n\n");
}

int main()
{
    printf("\nWelcome to Circular Doubly Linked List (DCLL) Generator!\n\n");
    introduction();
    int x = -1;
    int item, position;
    CircularDoublyLinkedList * dcll = createCircularDoublyLinkedList();
    printf("\n");
    while(x != 0)
    {
        scanf("%d", &x);
        switch (x)
        {
            case 0: printf("Exiting... Thank you!\n"); break;
            case 1: display(dcll); break;

            case 2: printf("data: "); scanf("%d", &item); insertAtStart(dcll, item); break;
            case 3: printf("data: "); scanf("%d", &item); insertAtEnd(dcll, item); break;
            case 4: printf("data: "); scanf("%d", &item); printf("position: "); scanf("%d", &position); insertAtPosition(dcll, item, position); break;

            case 5: deleteAtStart(dcll); break;
            case 6: deleteAtEnd(dcll); break;
            case 7: printf("position: "); scanf("%d", &position); deleteAtPosition(dcll, position); break;

            case 8: printf("data to be searched: "); scanf("%d", &item); search(dcll, item); break;

            case 9: introduction(); break;
            default: printf("Invalid value, try again.\n"); break;
        }
    }
}