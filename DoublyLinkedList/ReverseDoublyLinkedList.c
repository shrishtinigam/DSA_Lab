// ReverseDoublyLinkedList.c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/*  Question -
*   There are few elements is given in the list. Given elements are not in a sorted way. Write one 
*   function to reverse the given list (using recursion and without using recursion)
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
    if(dll->start->next == NULL)
    {
        printf("Empty Doubly Linked List, nothing to display.\n");
        return;
    }
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
    if(dll->start->next == NULL)
    {
        printf("Empty Doubly Linked List, nothing to search for.\n");
        return INT_MIN;
    }
    int count = 1;
    Node * ptr = dll->start->next;
    while(ptr->data != item)
    {
        if(ptr->data != item && ptr->next == NULL)
        {
            printf("%d not found in the doubly linked list.\n", item);
            return INT_MIN;
        }
        ptr = ptr->next;
        count++;
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
    printf("%d was deleted from %d position of the doubly linked list.\n", data, position);
    return data;
}


// Reverse a doubly linked list by iterative method
void reverse_1(DoublyLinkedList * dll)
{
    printf("Reversing doubly linked list by iterative method\n");
    Node * ptr = dll->start->next->next; 
    Node * ptr1;
    while(ptr != NULL)
    {
        ptr1 = ptr->next;
        if(ptr->prev != NULL)
        {
            ptr->prev->next = ptr->next;
            if(ptr->next != NULL)
                ptr->next->prev = ptr->prev;
            ptr->next = dll->start->next;
            ptr->prev = NULL;
            dll->start->next->prev = ptr;
            dll->start->next = ptr;
        }
        ptr = ptr1;
    }
}

// Reverse a doubly linked list with recursion
void reverse_2(Node * ptr, Node * start)
{
    if(ptr->next == NULL)
    {
        printf("Reversing doubly linked list using recursion\n");
        start->next = ptr;
        return;
    }
    reverse_2(ptr->next, start);
    ptr->next->prev = ptr->next->next;
    ptr->next->next = ptr;
    if(ptr->prev == NULL)
    {
        ptr->prev = ptr->next;
        ptr->next = NULL;
    }
}

int main()
{
    DoublyLinkedList * dll = createDoublyLinkedList();
    insertAtEnd(dll, 30);
    insertAtEnd(dll, 25);
    insertAtEnd(dll, 65);
    insertAtEnd(dll, 20);
    insertAtEnd(dll, 57);
    insertAtEnd(dll, 75);
    insertAtEnd(dll, 10);
    insertAtEnd(dll, 29);
    display(dll);
    // Reversing using iterative method
    reverse_1(dll);
    display(dll);
    // Reversing using recursive method
    reverse_2(dll->start->next, dll->start);
    display(dll);
}