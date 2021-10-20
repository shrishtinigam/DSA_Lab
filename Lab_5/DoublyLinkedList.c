// DoublyLinkedList.c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
    A doubly linked list here is defined by its "start".
    "start" is a node pointer that points to the first element.

    Here, start is a proper node with memory allocated to it.
    Note that start doesn't store any actual data.
    The next of the start node stores the location of the first element in the doubly linked list. 
    The prev of the start node is NULL and never accessed.
    The data of the start node is INT_MIN and never accessed.

    Thus, if we create a doubly linked list "dll", dll->start->next gives us the first element.

    The first element's prev node is NULL. (Thus, it is not connected to the start node.)

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
    deleteAtPosition

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

void introduction()
{
    printf("~ To display the DLL, enter 1.\n\n");
    printf("INSERTION\n~ To insert an element at the start DLL, enter 2 and the element.\n");
    printf("~ To insert an element at the end of the DLL, enter 3 and the element.\n");
    printf("~ To insert an element at a specific position of the DLL, enter 4, the element and the position.\n\n");
    printf("DELETION\n~ To delete an element from the start DLL, enter 5.\n");
    printf("~ To delete an element from the end of the DLL, enter 6.\n");
    printf("~ To delete an element from a specific position of the DLL, enter 7 and the position.\n");
    printf("\n~ To search for an element, enter 8 and the element.\n\n");
    printf("~ To print this message again, enter 9.\n");
    printf("~ To exit, enter 0.\n\n");
}

int main()
{
    printf("\nWelcome to Doubly Linked List (DLL) Generator!\n\n");
    introduction();
    int x = -1;
    int item, position;
    DoublyLinkedList * dll = createDoublyLinkedList();
    printf("\n");
    while(x != 0)
    {
        scanf("%d", &x);
        switch (x)
        {
            case 0: printf("Exiting... Thank you!\n"); break;
            case 1: display(dll); break;

            case 2: printf("data: "); scanf("%d", &item); insertAtStart(dll, item); break;
            case 3: printf("data: "); scanf("%d", &item); insertAtEnd(dll, item); break;
            case 4: printf("data: "); scanf("%d", &item); printf("position: "); scanf("%d", &position); insertAtPosition(dll, item, position); break;

            case 5: deleteAtStart(dll); break;
            case 6: deleteAtEnd(dll); break;
            case 7: printf("position: "); scanf("%d", &position); deleteAtPosition(dll, position); break;

            case 8: printf("data to be searched: "); scanf("%d", &item); search(dll, item); break;

            case 9: introduction(); break;
            default: printf("Invalid value, try again.\n"); break;
        }
    }
}