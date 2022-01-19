#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node * left;
    struct Node * right;
}Node;

typedef struct BinarySearchTree{
    Node * root;
}BinarySearchTree;

Node * createNode(int item)
{
    Node * temp = (Node *)malloc(sizeof(Node));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
} 

/*
 *  Creates a binary search tree structure with one node. Root pointer points to that node.
*/

BinarySearchTree * createBinarySearchTree(int item)
{
    BinarySearchTree * bst = (BinarySearchTree *)malloc(sizeof(BinarySearchTree));
    bst->root = createNode(item);
    printf("A new binary search tree was created! \n");
    return bst;
}

/* 
* Inserts node according to binary search tree rules
*/
Node * insert_node(Node * node, int item)
{
    if(node == NULL)
        return NULL;
    if(item <= node->data)
        node->left = insert_node(node->left, item);
    else if(item > node->data)
        node->right = insert_node(node->right, item);
    return node;
}
void insert(BinarySearchTree * bst, int item)
{
    Node * newnode = createNode(item);
    newnode = insert_node(bst->root, item);
}
/*
* Deletes node
*/

/*
* Searches for a given item in the binary search tree
*/

bool search(int item, Node * root)
{
    if(root == NULL)
        return false;
    if(root->data == item)
    {
        printf("Item %d was found.\n", item);
        return true;
    }
    else if(item < root->data)
    {
        if(search(item, root->left))
            return true;
    }
    else
    {
        if(search(item, root->right))
            return true;
    }
    return false;
}
/*
* Traversal
*/

void Inorder(Node * root)
{
    if(root == NULL)
        return;
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}
void InorderTraversal(BinarySearchTree * tree)
{
    printf("Printing inorder traversal of the tree! \n");
    Inorder(tree->root);
}

int main()
{
    BinarySearchTree * bst = createBinarySearchTree(4);
    InorderTraversal(bst);
    insert(bst, 7);
    InorderTraversal(bst);
    insert(bst, 2);
    InorderTraversal(bst);
    insert(bst, 10);
    InorderTraversal(bst);
    insert(bst, 5);
    InorderTraversal(bst);
}