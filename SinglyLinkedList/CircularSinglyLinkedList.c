// CircularSinglyLinkedList.c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
    Functions provided: 

    insertAtStart
    insertAtEnd
    insertAtPosition -> not done

    display
    search -> not done

    deleteAtStart
    deleteAtEnd
    deleteAtPosition -> not done
*/

typedef struct Node{
    int data;
    struct Node * next;
}Node;

typedef struct CircularSinglyLinkedList
{
    Node * start;
    int len;
}CircularSinglyLinkedList;

Node * createNode(int item)
{
    Node * temp = (Node *)malloc(sizeof(Node));
    temp->data = item;
    temp->next = NULL;
    return temp;
}

CircularSinglyLinkedList * createCircularSinglyLinkedList()
{
    CircularSinglyLinkedList * sll = (CircularSinglyLinkedList *)malloc(sizeof(CircularSinglyLinkedList));
    sll->len = 0;

    /* Creating a start node that will store the location of the first node.
     * It stores null at the time of declaration.                           */
    sll->start = (Node *)malloc(sizeof(Node));
    sll->start->data = INT_MIN; // Data in the start node is never to be accessed. If INT_MIN is the data displayed, an error has possibly occured
    sll->start->next = NULL;
    printf("A new circular singly linked list was created!\n");
    return sll;
}

/* Insertion */ 

// Inserts an element at the start of a linked list
void insertAtStart(CircularSinglyLinkedList * csll, int item)
{
    Node * newnode = createNode(item);
    if(csll->start->next == NULL) // If csll is empty
    {
        csll->start->next = newnode;
        newnode->next = csll->start->next;
    }
    else
    {
        Node * ptr = csll->start->next;
        while(ptr->next != csll->start->next)
            ptr = ptr->next;
        newnode->next = csll->start->next;
        csll->start->next = newnode;
        ptr->next = newnode; // to maintain circular nature of the csll
    }
    printf("%d was inserted at the start of the circular singly linked list!\n", item);
    csll->len++;
} 

// Inserts an element at the end of a linked list
void insertAtEnd(CircularSinglyLinkedList * csll, int item)
{
    Node * newnode = createNode(item);
    if(csll->start->next == NULL) // If csll is empty
    {
        csll->start->next = newnode;
        newnode->next = csll->start->next;
    }
    else
    {
        Node * ptr = csll->start->next;
        while(ptr->next != csll->start->next)
            ptr = ptr->next;
        newnode->next = ptr->next;
        ptr->next = newnode;
    }
    printf("%d was inserted at the end of the circular singly linked list!\n", item);
    csll->len++;
}

/* Traversal */ 

void display(CircularSinglyLinkedList * csll)
{
    if(csll->start->next == NULL)
    {
        printf("Empty.\n");
        return;
    }
    Node * ptr = csll->start->next;
    if(ptr == ptr->next)
        printf("%d      ", ptr->data);
    else
    {
        while(ptr->next != csll->start->next)
        {
            printf("%d       ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d      ", ptr->data);
    }
    printf("\n");
    Node * ptr2 = csll->start->next; 
    printf("%d ", ptr->next);
    while(ptr2->next != csll->start->next)
    {
        printf("%d ", ptr2->next);
        ptr2 = ptr2->next;
    }
    printf("%d ", ptr2->next);  // -> to check circular nature
    printf("\n");
}

/* Deletion */

// Deletion at start
int deleteAtStart(CircularSinglyLinkedList * csll)
{
    if(csll->start->next == NULL)
    {
        printf("Circular Singly Linked List is empty, nothing to delete\n");
        return INT_MIN;
    }
    Node * ptr = csll->start->next;
    if(ptr == ptr->next)
        csll->start->next = NULL;
    else
    {
        while(ptr->next != csll->start->next)
            ptr = ptr->next;
        ptr->next = csll->start->next->next;
        ptr = csll->start->next;
        csll->start->next = ptr->next;
    }
    int data = ptr->data;
    free(ptr);
    printf("%d was deleted from the start of the singly linked list.\n", data);
    csll->len--;
    return data;
}

// Deletion at end
int deleteAtEnd(CircularSinglyLinkedList * csll)
{
    if(csll->start->next == NULL)
    {
        printf("Circular Singly Linked List is empty, nothing to delete\n");
        return INT_MIN;
    }
    Node * ptr = csll->start->next;
    Node * ptr2 =  csll->start->next;
    if(ptr2 == ptr2->next)
        csll->start->next = NULL;
    else
    {
        while(ptr->next->next != csll->start->next)
            ptr = ptr->next;
        ptr2 = ptr;
        ptr2 = ptr2->next;
        ptr->next = csll->start->next;
    }
    int data = ptr2->data;
    free(ptr2);
    printf("%d was deleted from the end of the singly linked list.\n", data);
    csll->len--;
    return data;
}

int main()
{
    CircularSinglyLinkedList * csll = createCircularSinglyLinkedList();
    insertAtEnd(csll, 50);
    display(csll);
    insertAtEnd(csll, 60);
    display(csll);
    insertAtEnd(csll, 70);
    display(csll);
    deleteAtStart(csll);
    display(csll);
    deleteAtStart(csll);
    display(csll);
    deleteAtStart(csll);
    display(csll);
    insertAtEnd(csll, 50);
    display(csll);
    insertAtEnd(csll, 60);
    display(csll);
    insertAtEnd(csll, 70);
    display(csll);
    deleteAtStart(csll);
    display(csll);
    deleteAtStart(csll);
    display(csll);
    deleteAtStart(csll);
    display(csll);
}