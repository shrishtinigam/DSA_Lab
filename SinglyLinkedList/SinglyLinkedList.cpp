#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

struct SinglyLinkedList
{
    Node * start;
};

Node* createNode(int data){
    Node * temp = new Node();
    temp->data = data;
    temp->next = NULL;
    return temp;
}

SinglyLinkedList * createSinglyLinkedList()
{
    SinglyLinkedList * sll = new SinglyLinkedList();

    /* Creating a start node that will store the location of the first node.
     * It stores null at the time of declaration.                           */
    sll->start = createNode(INT_MIN); // Data in the start node is never to be accessed. If INT_MIN is the data displayed, an error has possibly occured
    cout << "A new singly linked list was created!\n";
    return sll;
}

/* Insertion */

// Inserts an element at the start of a linked list
void insertAtStart(SinglyLinkedList * sll, int item)
{
    Node * newnode = createNode(item);
    newnode->next = sll->start->next;
    sll->start->next = newnode;
    cout << item << " was inserted at the start of the singly linked list!\n";
}

void InsertAtEnd(int data, Node * head){

}

void display(SinglyLinkedList * sll)
{
    int count = 0;
    // Printing data
    Node * ptr = sll->start->next; // Setting pointer to the first element in the singly linked list
    cout << "Start: " << sll->start << "\n";
    while(ptr != NULL)
    {
        count++;
        cout << ptr->data << "      ";
        ptr = ptr->next;
    }
    // Printing the location
    Node * ptr2 = sll->start->next; 
    cout << "\n"<< sll->start->next << " ";
    while(ptr2 != NULL)
    {
        cout << ptr2->next << " ";
        ptr2 = ptr2->next;
    }
    cout << "\nTotal Elements in the Linked List: "<< count << "\n\n";
}

int main()
{
    SinglyLinkedList * sll = createSinglyLinkedList();
    insertAtStart(sll, 5);
    insertAtStart(sll, 6);
    insertAtStart(sll, 7);
    insertAtStart(sll, 8);
    display(sll);
    return 0;
}










