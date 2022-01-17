#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node * left;
    struct Node * right;
}Node;

typedef struct BinaryTree{
    Node * root;
}BinaryTree;

Node * createNode(int item)
{
    Node * temp = (Node *)malloc(sizeof(Node));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
} 

/*
 *  Creates a binary tree structure with one node. Root pointer points to that node.
*/

BinaryTree * createBinaryTree(int item)
{
    BinaryTree * bt = (BinaryTree *)malloc(sizeof(BinaryTree));
    bt->root = createNode(item);
    printf("A new binary tree was created! \n");
    return bt;
}

/*
 * Inserts node at left of the node specified unless node is already present.
*/

void insertAtLeft(Node * root, int item)
{
    Node * newnode = createNode(item);
    if(root->left == NULL)
        root->left = newnode;
    else
        printf("Left node already occupied.\n");
}

/*
 * Inserts node at right of the node specified unless node is already present.
*/

void insertAtRight(Node * root, int item)
{
    Node * newnode = createNode(item);
    if(root->right == NULL)
        root->right = newnode;
    else
        printf("Right node already occupied.\n");
}

void Inorder(Node * root)
{
    if(root == NULL)
        return;
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}
void InorderTraversal(BinaryTree * tree)
{
    printf("Printing inorder traversal of the tree! \n");
    Inorder(tree->root);
}

void Preorder(Node * root)
{
    if(root == NULL)
        return;
    printf("%d ",root->data);
    Preorder(root->left);
    Preorder(root->right);
}
void PreorderTraversal(BinaryTree * tree)
{
    printf("Printing preorder traversal of the tree! \n");
    Preorder(tree->root);
}

void Postorder(Node * root)
{
    if(root == NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ",root->data);
}
void PostorderTraversal(BinaryTree * tree)
{
    printf("Printing postorder traversal of the tree! \n");
    Postorder(tree->root);
}

void delete(Node * root)
{
    Node * temp = root;
    if(root != NULL)
    {
        delete(root->left);
        delete(root->right);
    }
    free(temp);
}

void deleteBinaryTree(BinaryTree * bt)
{
    printf("Deleting Binary Tree...\n");
    delete(bt->root);
}

// Deletes elements using the node of the element to be delted and its parent node.
void deleteNode(Node * root, Node * parent)
{
    // If 0 child
    if(root->left == NULL && root->right == NULL)
    {
        if(root == parent->right)
            parent->right = NULL;
        else if(root == parent->left)
            parent->left = NULL;
        free(root);
        printf("The node had 0 children and now has been deleted.\n");
        return;
    }
    // If 1 child
    if(root->left != NULL && root->right == NULL)
    {
        if(root == parent->right)
            parent->right = root->left;
        else if(root == parent->left)
            parent->left = root->left;
        printf("The node had 1 child and now has been deleted.\n");
        free(root);
        return;
    }
    if(root->left == NULL && root->right != NULL)
    {
        if(root == parent->right)
            parent->right = root->right;
        else if(root == parent->left)
            parent->left = root->right;
        free(root);
        return;
    }
    // If 2 child - we delete the rightmost deepest node from root after exchanging the data in the rightmost deepest node from root and the node to be deleted
    Node * temp = root;
    Node * temp2 = parent;
    while(temp->right != NULL)
    {
        temp = temp->right;
        temp2 = temp2->right;
    }
    root->data = temp->data;
    temp2->right = NULL;
    printf("The node had 2 children and now has been deleted.\n");
    free(temp);
}

bool search(int item, Node * root)
{
    if(root == NULL)
        return false;
    if(root->data == item)
    {
        printf("Item %d was found.\n", item);
        return true;
    }
    if(search(item, root->left))
        return true;
    else if(search(item, root->right))
        return true;
    return false;
}

int main()
{
    BinaryTree * bt = createBinaryTree(12);
    insertAtLeft(bt->root, 45);
    insertAtLeft(bt->root->left, 23);
    insertAtRight(bt->root, 8);
    insertAtRight(bt->root->right, 11);
    insertAtLeft(bt->root->right, 9);
    insertAtRight(bt->root->right->right, 101);
    insertAtLeft(bt->root->right->right, 1);
    insertAtRight(bt->root->right->left, 7);
    insertAtLeft(bt->root->right->left, 65);

    if(!search(10, bt->root))
        printf("Item 10 was not found.\n");

    if(!search(23, bt->root))
        printf("Item 1 was not found.\n");

    // Inorder, Preorder and Postorder traversals of the binary tree
    InorderTraversal(bt);
    printf("\n");
    PreorderTraversal(bt);
    printf("\n");
    PostorderTraversal(bt);
    printf("\n");

    // 0 child deletion
    deleteNode(bt->root->right->right->right, bt->root->right->right);
    InorderTraversal(bt);
    printf("\n");
    // 1 child deletion
    deleteNode(bt->root->right->right, bt->root->right);
    InorderTraversal(bt);
    printf("\n");
    // 2 child deletion
    deleteNode(bt->root->right, bt->root);
    InorderTraversal(bt);
    printf("\n");

    // deletion of whole binary tree
    deleteBinaryTree(bt);
    printf("\n");
}