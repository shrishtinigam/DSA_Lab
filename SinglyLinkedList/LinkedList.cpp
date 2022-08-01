#include<iostream>
using namespace std;

/* Without making a separate nexted list struct */

struct Node
{
    int data;
    Node * next;
};

Node * InsertAtBeginning(Node * head, int x){
    Node * temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
    return head;
}

Node * InsertAtEnd(Node * head, int x){
    Node * start = head;
    while(head->next != NULL){
        head = head->next;
    }
    Node * temp = new Node();
    temp->data = x;
    temp->next = NULL;
    head->next = temp; 
    return start;
}

Node * InsertAtN(Node * head, int val, int pos){
    if(pos < 1){
        cout << "Position is INVALID.\n";
        return head;
    }

    Node * temp = new Node();
    temp->data = val;

    if(pos == 1){
        temp->next = head;
        head = temp;
        return head;
    }

    Node * ptr = head;
    pos = pos - 2;
    while(pos--){
        ptr = ptr->next;
        if(pos and ptr->next == NULL){
            cout << "Position is INVALID.\n";
            return head;
        }
    }
    temp->next = ptr->next;
    ptr->next = temp; 
    return head;
}

Node * DeleteAtN(Node * head, int pos){
    if(pos < 1){
        cout << "Position is INVALID.\n";
        return head;
    }
    Node * ptr = head;
    if(pos == 1){
        head = ptr->next;
        delete ptr;
        return head;
    }
    pos = pos - 2;
    while(pos--){
        cout << "pos: " << pos << " ";
        ptr = ptr->next;
        if(ptr->next == NULL){
            cout << "Position is INVALID.\n";
            return head;
        }
    }
    Node * ptr2 = ptr->next;
    ptr->next = ptr2->next;
    delete ptr2;
    return head;
}


/* Iterative method for forward printing of values in a linked list is 
better as we are using only one temporary variable in heap as opposed to 
making n stack function calls */

void Display(Node * head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next; 
    }
    cout << '\n';
}

void DisplayRecursive(Node * head){
    if(head == NULL){
        cout << "\n";
        return;
    }
    cout << head->data << " ";
    DisplayRecursive(head->next);
}

/* While displaying in reverse, if we do it iteratively, we will have to 
declare an array in heap memory. So, recursion for reverse printing is 
better or just as good. We can say it better because iterative method 
would require us to convert our linked list into another data structure*/

void DisplayReverse(Node * head){
    if(head == NULL)
        return;
    DisplayReverse(head->next);
    cout << head->data << " ";
}

Node *  ReverseIterative(Node * head){
    Node * curr, * prev, *next;
    curr = head;
    prev = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node *  ReverseRecursive(Node * head){
    if(head->next == NULL)
        return head;
    Node * temp = ReverseRecursive(head->next);
    Node * ptr = head->next;
    ptr->next = head;
    head->next = NULL;
    return temp;
}

int main()
{
    Node * head = NULL;
    head = ReverseIterative(head);
    head = InsertAtBeginning(head, 4);
    head = InsertAtBeginning(head, 76);
    head = InsertAtBeginning(head, 23);
    head = InsertAtBeginning(head, 9);

    head = InsertAtEnd(head, 34);
    head = InsertAtEnd(head, 3);
    head = InsertAtEnd(head, 383);

    Display(head);

    head = InsertAtN(head, 99222, 5);
    head = InsertAtN(head, 95555, 2);
    head = InsertAtN(head, 93333, 4);
    head = InsertAtN(head, 99777, 7);
    head = InsertAtN(head, 99999, 12);

    Display(head);
    cout << "HELLO\n\n";
    head = DeleteAtN(head, 3);
    Display(head);
    head = DeleteAtN(head, 4);
    Display(head);
    head = DeleteAtN(head, 15);
    Display(head);
    head = DeleteAtN(head, 9);
    Display(head);
    head = DeleteAtN(head, 9);
    Display(head);
    head = DeleteAtN(head, 9);
    Display(head);
    head = DeleteAtN(head, 8);
    Display(head);

    head = InsertAtN(head, 1000, 1);
    head = InsertAtN(head, 1001, 2);
    head = InsertAtN(head, 1002, 4);
    head = InsertAtBeginning(head, 1003);
    head = InsertAtBeginning(head, 1004);
    head = InsertAtBeginning(head, 1005);

    Display(head);
    head = ReverseIterative(head);
    Display(head);
    head = InsertAtN(head, 1002, 4);
    head = InsertAtBeginning(head, 1003);
    Display(head);
    DisplayRecursive(head);
    
    DisplayReverse(head);
    cout << "\n\n\n";
    Display(head);
    head = ReverseRecursive(head);
    Display(head);
}