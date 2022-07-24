#include <iostream>
#include <queue>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNewNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Inserting in a binary search tree*/
Node* Insert(Node* root, int data){
    if(root == NULL){
        root = createNewNode(data);
    }else if(data <= root->data){
        root->left = Insert(root->left, data);
    }else{
        root->right = Insert(root->right, data);
    }
    return root;
}

/* Searching in a binary search tree*/
bool Search(Node* root, int data){
    if(root == NULL)
        return false;
    else if(root->data == data)
        return true;
    else if(data <= root->data)
        return Search(root->left, data);
    else 
        return Search(root->right, data);
}

/* Finding the maximum and minimum Node in a binary search tree*/
int findMinIterative(Node* root){
    if(root == NULL){
        cout << "Error: Tree is empty\n";
        return -1;
    }

    while(root->left != NULL){
        root = root->left;
    }

    return root->data;
}

int findMaxIterative(Node* root){
    if(root == NULL){
        cout << "Error: Tree is empty\n";
        return -1;
    }

    while(root->right != NULL){
        root = root->right;
    }

    return root->data;
}

int findMaxRecursive(Node* root){
    if(root == NULL){
        cout << "Error: Tree is empty\n";
        return -1;
    }
    if(root->right != NULL)
        return findMaxRecursive(root->right);
    return root->data;   
}

int findMinRecursive(Node* root){
    if(root == NULL){
        cout << "Error: Tree is empty\n";
        return -1;
    }
    if(root->left != NULL)
        return findMinRecursive(root->left);
    return root->data;
}

/* Finding the height of a binary search tree */
int findHeight(Node * root){
    if(root == NULL){
        return -1;
    }
    return max(findHeight(root->left), findHeight(root->right)) + 1;
}

/* Level Order Traversal / Breadth First Traversal */
/* Time-Complexity = O(n) - all three cases, Space-Complexity = O(1) - best case, O(n) - worst, average case. (for a perfect binary tree).*/
void levelOrderTraversal(Node * root){
    if(root == NULL)
        return;
    queue<Node*> Q;
    Q.push(root);
    while(!Q.empty()){
        Node* current = Q.front();
        cout << current->data << " ";
        if(current->left != NULL)
            Q.push(current->left);
        if(current->right != NULL)
            Q.push(current->right);
        Q.pop();
    }
}

/* PreOrder Order Traversal / A type of Depth First Traversal */
/* Time-Complexity = O(n), Space-Complexity = O(h) -> O(n) - worst case, O(log n) - average case*/
void Preorder(Node* root){
    if(root == NULL)
        return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

/* Inorder Order Order Traversal / A type of Depth First Traversal */
/* Time-Complexity = O(n), Space-Complexity = O(h) -> O(n) - worst case, O(log n) - average case*/
void Inorder(Node* root){
    if(root == NULL)
        return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

/* PostOrder Order Traversal / A type of Depth First Traversal */
/* Time-Complexity = O(n), Space-Complexity = O(h) -> O(n) - worst case, O(log n) - average case*/
void PostOrder(Node* root){
    if(root == NULL)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

/* Check if a given binary tree is a BST */
/* Method - 1 */
bool IsSubtreeLesser(Node* root, int value){
    // Check if all the elements in a given tree are lesser than a given value or not
    if(root == NULL)
        return true;

    if(root->data <= value and 
    IsSubtreeLesser(root->left, value) and 
    IsSubtreeLesser(root->right, value))
        return true;

    return false;
}
bool IsSubtreeGreater(Node* root, int value){
    // Check if all the elements in a given tree are greater than a given value or not
    if(root == NULL)
        return true;

    if(root->data > value and 
    IsSubtreeGreater(root->left, value) and 
    IsSubtreeGreater(root->right, value))
        return true;

    return false;
}

bool IsBinarySearchTree(Node* root){
    if(root == NULL)
        return true;

    if(IsSubtreeLesser(root->left, root->data) and 
        IsSubtreeGreater(root->right, root->data) and 
        IsBinarySearchTree(root->left) and 
        IsBinarySearchTree(root->right))
        return true;

    return false;
}

/* Method - 2 - O(n) - doesn't allow duplicates */
bool IsBSTUtil(Node* root, int minValue, int maxValue);
bool IsBinarySearchTree2(Node* root){
    return IsBSTUtil(root, INT_MIN, INT_MAX);
}
bool IsBSTUtil(Node* root, int minValue, int maxValue){
    if(root == NULL)
        return true;

    if(root->data > minValue
        and root->data < maxValue 
        and IsBSTUtil(root->left, minValue, root->data)
        and IsBSTUtil(root->right, root->data, maxValue))
        return true;
    
    return false;
}

/* Method 3 - Inorder traversal - O(n) - duplicates allowed */
bool IsBSTUtil2(Node* root, int lastValue);
bool IsBinarySearchTree3(Node * root){
    int lastValue;
    return IsBSTUtil2(root, root->data);
}
bool IsBSTUtil2(Node* root, int lastValue){
    if(root == NULL)
        return true;

    IsBSTUtil2(root->left, lastValue);
    if(root->data >= lastValue)
        lastValue = root->data;
    else
        return false;
    IsBSTUtil2(root->right, lastValue);
    return true;
}

/* Deleting a node from binary search tree */

Node* FindMinAddress(Node * root){
    if(root == NULL){
        cout << "Error: Tree is empty\n";
        return NULL;
    }

    while(root->left != NULL){
        root = root->left;
    }

    return root;
}

Node * Delete(Node * root, int data){
    /* Searching for the data in the tree */
    if(root == NULL)
        return root;
    else if(data < root->data)
        root->left = Delete(root->left, data);
    else if(data > root->data)
        root->right = Delete(root->right, data);
    else{
            /* Case 1: No child */
            if(root->left == NULL and root->right == NULL){
                delete root;
                root = NULL;
            }
            /* Case 2: One child */
            else if(root->left == NULL){
                Node* temp = root;
                root = root->right;
                delete temp;
            }
            else if(root->right == NULL){
                Node* temp = root;
                root = root->left;
                delete temp;
            }
            /* Case 3: Two child */
            else{
                Node* temp = FindMinAddress(root->right);
                root->data = temp->data;
                root->right = Delete(root->right, temp->data);
            }
    }
    return root;

}

/* Case - 3
*   Find min in the right 
*   Copy the value in targetted node
*   Delete duplicate from right-subtree
*
*   OR 
*
*   Find max in left 
*   Copy the value in targetted node
*   Delete duplicate from left-subtree
*
*/

/* Function to find Inorder Successor in a BST */
struct Node* Getsuccessor(struct Node* root,int data) {
	// Search the Node - O(h)
	struct Node* current = Find(root,data);
	if(current == NULL) return NULL;
	if(current->right != NULL) {  //Case 1: Node has right subtree
		return FindMin(current->right); // O(h)
	}
	else {   //Case 2: No right subtree  - O(h)
		struct Node* successor = NULL;
		struct Node* ancestor = root;
		while(ancestor != current) {
			if(current->data < ancestor->data) {
				successor = ancestor; // so far this is the deepest node for which current node is in left
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		return successor;
	}
}

int main()
{
    Node* root = NULL;
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,25);
    root = Insert(root,8);
    root = Insert(root,12);
    root = Insert(root,9);

    int number;
    cout << "Enter number to be searched\n";
    cin >> number;
    if(Search(root, number) == true)
        cout << "Found\n";
    else
        cout << "Not Found\n";

    cout << findMinRecursive(root) << "\n";
    //cout << findMaxRecursive(root) << "\n";
    //cout << findMinIterative(root) << "\n";
    cout << findMaxIterative(root) << "\n";

    cout << findHeight(root)<< "\n";

    levelOrderTraversal(root);
    cout << "\n";

    Preorder(root);
    cout << "\n";
    Inorder(root);
    cout << "\n";
    PostOrder(root);
    cout << "\n";

    cout << IsBinarySearchTree(root) << "\n";
    cout << IsBinarySearchTree2(root) << "\n";
    cout << IsBinarySearchTree3(root) << "\n";

    // Delete(root, 12); // 0 children
    // Delete(root, 8); // 1 child
    // Delete(root, 15); // 2 children (root)
    Delete(root, 10); // 2 children
    
    levelOrderTraversal(root);
    cout << "\n";
}