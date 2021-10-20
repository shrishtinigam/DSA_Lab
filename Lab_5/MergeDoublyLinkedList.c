// MergeDoublyLinkedList.c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/*  Question -
*   Consider one scenario where two lists is given and needs to be merged in a single list. Write a 
*   program for the given scenario.
*/

/*  Soultion -
*   We join the last element to the first element of the second list and delete the second list's start.
*   Refer to the doubly linked list program (DoublyLinkedList.c).
*   
*   
*/

typedef struct Node{
    int data;
    struct Node * prev;
    struct Node * next;
}Node;

typedef struct DoublyLinkedList
{
    Node * start;
    int len;
}DoublyLinkedList;

Node * createNode(int item)
{
    Node * temp = (Node *)malloc(sizeof(Node));
    temp->data = item;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

DoublyLinkedList * createDoublyLinkedList()
{
    DoublyLinkedList * dll = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
    dll->len = 0;
    dll->start = (Node *)malloc(sizeof(Node));
    dll->start->data = INT_MIN; // Data in the start node is never to be accessed. If INT_MIN is the data displayed, an error has possibly occured
    dll->start->next = NULL;
    dll->start->prev = NULL;
    printf("A new doubly linked list was created!\n");
    return dll;
}

/* Insertion */

// Inserts an element at the start of a linked list
void insertAtStart(DoublyLinkedList * dll, int item)
{
    Node * newnode = createNode(item);
    if(dll->start->next != NULL)
    {
        newnode->next = dll->start->next;
        dll->start->next->prev = newnode;
    }
    dll->start->next = newnode;
    printf("%d was inserted at the start of the doubly linked list!\n", item);
    dll->len++;
}

// Inserts an element at the end of a doubly linked list
void insertAtEnd(DoublyLinkedList * dll, int item)
{
    Node * newnode = createNode(item);
    Node * ptr = dll->start;
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newnode;
    if(ptr != dll->start)
        newnode->prev = ptr;
    printf("%d was inserted at the end of the doubly linked list!\n", item);
    dll->len++;
}

// Inserts an element at a specified position.
// Here, position is determined by usual 1-base counting. If position = 5, item will be the fifth element in the linked list
void insertAtPosition(DoublyLinkedList * dll, int item, int position)
{
    Node * newnode = createNode(item);
    Node * ptr = dll->start;
    for(int i = 0; i < (position - 1); i++)
    {
        if(ptr->next == NULL && i + 1 < position)
        {
            printf("Invalid Location\n");
            return;
        }
        ptr = ptr->next;
    }
    if(position != 1) // If adding at beginning then newnode's prev will remain NULL
        newnode->prev = ptr;
    if(dll->start->next != NULL) // When list is not empty
    {
        newnode->next = ptr->next;
        if(ptr->next != NULL) 
            ptr->next->prev = newnode; // Skip this if adding at the end
    }
    ptr->next = newnode;
    printf("%d was inserted at position %d of the doubly linked list!\n", item, position);
    dll->len++;
}

/* Traversal */
/* Display function provided for illustrative purposes.*/
void display(DoublyLinkedList * dll)
{
    // Printing data
    Node * ptr = dll->start->next; 
    printf("Start: %d \n", dll->start);
    while(ptr != NULL)
    {
        printf("%d       ", ptr->data);
        ptr = ptr->next;
    }
    // Printing the location
    Node * ptr2 = dll->start->next; 
    printf("\n%d ", dll->start->next);
    while(ptr2 != NULL)
    {
        printf("%d ", ptr2->next);
        ptr2 = ptr2->next;
    }
    printf("\n");
}

// Returns the 1-base position of the first occurance of data.
int search(DoublyLinkedList * dll, int item)
{
    int count = 1;
    Node * ptr = dll->start->next;
    while(ptr->data != item)
    {
        ptr = ptr->next;
        count++;
        if(ptr->data != item && ptr->next == NULL)
        {
            printf("%d not found in the doubly linked list.\n", item);
            return INT_MIN;
        }
    }
    printf("%d found at %d position in the doubly linked list.\n", item, count);
    return count;
}

/* Deletion */

// Deletion at start
int deleteAtStart(DoublyLinkedList * dll)
{
    if(dll->start->next == NULL)
    {
        printf("Doubly Linked List is empty, nothing to delete.\n");
        return INT_MIN;
    }
    Node * ptr = dll->start->next;
    dll->start->next = ptr->next;
    if(ptr->next != NULL) 
        ptr->next->prev = NULL;
    int data = ptr->data;
    free(ptr);
    printf("%d was deleted from the start of the doubly linked list.\n", data);
    dll->len--;
    return data;
}

// Deletion at end
int deleteAtEnd(DoublyLinkedList * dll)
{
    if(dll->start->next == NULL)
    {
        printf("Doubly Linked List is empty, nothing to delete\n");
        return INT_MIN;
    }
    int data;
    Node * ptr = dll->start->next;
    while(ptr->next != NULL)
        ptr = ptr->next;
    if(ptr->prev == NULL) // Only one element is present
        dll->start->next = NULL;
    else // Other cases
        ptr->prev->next = NULL;
    data = ptr->data;
    free(ptr);
    dll->len--;
    printf("%d was deleted from the start of the doubly linked list.\n", data);
    return data;
}
// Deletion of an element at a particular position
// Here, position is determined by usual 1-base counting.
int deleteAtPosition(DoublyLinkedList * dll, int position)
{
    if(dll->start->next == NULL)
    {
        printf("Doubly Linked List is empty, nothing to delete\n");
        return INT_MIN;
    }
    Node * ptr = dll->start;
    int data;
    for(int i = 0; i < position; i++)
    {
        if(ptr->next == NULL && i < position)
        {
            printf("Invalid Location\n");
            return INT_MIN;
        }
        ptr = ptr->next;
    }

    if(ptr->prev == NULL) // If first element is to be deleted
        dll->start->next = ptr->next; 
    else
        ptr->prev->next = ptr->next;

    if(ptr->next != NULL)
        ptr->next->prev = ptr->prev;
    data = ptr->data;
    free(ptr);
    dll->len--;
    printf("%d was deleted from %d position of the singly linked list.\n", data, position);
    return data;
}

// Join two doubly linked lists
void joinDoublyLinkedLists(DoublyLinkedList * dll1, DoublyLinkedList * dll2)
{
    Node * ptr = dll1->start;
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = dll2->start->next;
    dll2->start->next->prev = ptr;
    free(dll2->start);
    free(dll2);
}

int main()
{
    DoublyLinkedList * dll = createDoublyLinkedList();
    insertAtEnd(dll, 30);
    insertAtEnd(dll, 25);
    insertAtEnd(dll, 65);
    insertAtEnd(dll, 20);
    insertAtEnd(dll, 5);
    insertAtEnd(dll, 75);
    insertAtEnd(dll, 10);
    insertAtEnd(dll, 20);
    display(dll);

    DoublyLinkedList * dll1 = createDoublyLinkedList();
    insertAtEnd(dll1, 20);
    insertAtEnd(dll1, 85);
    insertAtEnd(dll1, 61);
    insertAtEnd(dll1, 20);
    insertAtEnd(dll1, 56);
    insertAtEnd(dll1, 75);
    insertAtEnd(dll1, 17);
    insertAtEnd(dll1, 90);
    display(dll1);

    joinDoublyLinkedLists(dll, dll1);
    display(dll);
}