// CircularDoublyLinkedList.c
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

}
/* Traversal */

/* Display function provided for illustrative purposes.*/
void display(CircularDoublyLinkedList * dcll)
{
    if(dcll->start->next == NULL)
    {
        printf("Empty.\n");
        return;
    }
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
    printf("\n");
    Node * ptr2 = dcll->start->next; 
    printf("%d ", ptr->next);
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
    printf("%d was deleted from the start of the doubly linked list.\n", data);
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
    printf("%d was deleted from the end of the doubly linked list.\n", data);
    dcll->len--;
    return data;
}

// Deletion of an element at a particular position
// Here, position is determined by usual 1-base counting.
int deleteAtPosition(CircularDoublyLinkedList * dcll, int position)
{

}

int main()
{
    CircularDoublyLinkedList * dcll = createCircularDoublyLinkedList();
    insertAtEnd(dcll, 30);
    display(dcll);
    insertAtEnd(dcll, 60);
    display(dcll);
    insertAtEnd(dcll, 340);
    display(dcll);
    insertAtEnd(dcll, 10);
    display(dcll);
    deleteAtEnd(dcll);
    display(dcll);
    deleteAtEnd(dcll);
    display(dcll);
    deleteAtEnd(dcll);
    display(dcll);
    deleteAtEnd(dcll);
    display(dcll);
    deleteAtEnd(dcll);
    display(dcll);
    deleteAtEnd(dcll);
    display(dcll);
    deleteAtEnd(dcll);
    display(dcll);
    deleteAtEnd(dcll);
    display(dcll);
}