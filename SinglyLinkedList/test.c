#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node * next;
}Node;

typedef struct SinglyLinkedList
{
    Node * start;
    int len;
}SinglyLinkedList;

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
    sll->start = (Node *)malloc(sizeof(Node));
    sll->start->data = INT_MIN; 
    sll->start->next = NULL;
    return sll;
}

void insertAtEnd(SinglyLinkedList * sll, int item)
{
    Node * newnode = createNode(item);
    Node * ptr = sll->start;
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newnode;
    sll->len++;
}

void checkEven(SinglyLinkedList * sll)
{
    Node * ptr0 = NULL;
    Node * ptr = sll->start->next;
    int count = 0;
    Node * first = NULL;
    Node * first_prev = NULL;
    while(ptr!=NULL)
    {
        printf("hey2 - %d\n", count);
        if(ptr->data % 2 == 0 && count == 0)
        {
            count++;
            first = ptr;
            first_prev = ptr0;
        }
        else if(ptr->data % 2 == 0 && count != 0)
        {
            count++;
        }
        else if(ptr->data % 2 != 0 && (count == 0 || count == 1))
        {
            ptr0 = ptr;
            ptr = ptr->next;
            continue;
        }
        else if(ptr->data % 2 != 0)
        {
            Node * ptr1 = ptr;
            Node * ptr3 = first->next;
            Node * ptr4 = first;
            Node * ptr5 = NULL;
            first_prev->next = ptr0;
            first->next = ptr1;
            while(ptr5 != ptr1)
            {
                printf("hey1\n");
                ptr5 = ptr3->next;
                ptr3->next = ptr4;
                ptr4 = ptr3;
                ptr3 = ptr5;
            }
        }
        ptr0 = ptr;
        ptr = ptr->next;
    }
}
void display(SinglyLinkedList * sll)
{
    int count = 0;
    Node * ptr = sll->start->next;
    while(ptr != NULL)
    {
        count++;
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    SinglyLinkedList * sll = createSinglyLinkedList();
    insertAtEnd(sll, 17);
    insertAtEnd(sll, 14);
    insertAtEnd(sll, 12);
    insertAtEnd(sll, 45);
    insertAtEnd(sll, 46);
    insertAtEnd(sll, 34);
    insertAtEnd(sll, 20);
    insertAtEnd(sll, 57);
    checkEven(sll);
    display(sll);
}
