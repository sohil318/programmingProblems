#include <iostream>
#include <stack>

using namespace std;

typedef struct Node {
    int val;
    Node *leftChild;
    Node *rightChild;
} Node;

Node* newNode(int data)
{
    Node *temp = new Node;
    temp->val = data;
    temp->leftChild = NULL;
    temp->rightChild = NULL;
    return temp;
}

Node* createTree()
{
    Node *root = newNode(10);
    root->leftChild = newNode(6);
    root->rightChild = newNode(13);
    root->leftChild->leftChild = newNode(4);
    root->leftChild->rightChild = newNode(8);
    root->rightChild->leftChild = newNode(11);
    root->rightChild->rightChild = newNode(15);
    root->leftChild->leftChild->leftChild = newNode(2);
    root->leftChild->leftChild->leftChild->leftChild = newNode(1);
    root->leftChild->leftChild->leftChild->rightChild = newNode(3);
    root->leftChild->rightChild->leftChild = newNode(7);
    root->leftChild->rightChild->rightChild = newNode(9);
    root->rightChild->rightChild->leftChild = newNode(14);
    root->rightChild->rightChild->rightChild = newNode(16);
    
    return root;
}

void printLinkedList(Node* root)
{
    while (root->leftChild)
    {
        root = root->leftChild;
    }
    while (root)
    {
        cout << "\t" << root->val;
        root = root->rightChild;
    }
}

void inOrderTraversal(Node* root)
{
    if (!root)
        return;

    inOrderTraversal(root->leftChild);
    cout << "\t" << root->val;
    inOrderTraversal(root->rightChild);
    return;
}

int findNodeLevel(Node* root, int level, int num)
{
    int x;
    if (!root)
        return x;
    
    if (!root->leftChild) 
    x = findNodeLevel(root->leftChild, level + 1, num);
    if (root->val == num)
    {
        cout << level << endl;
        return level;
    }
    if (!root->rightChild) 
    x = findNodeLevel(root->rightChild, level + 1, num);
    return x;
}

void kDistanceNodes(Node* root, int num, int k)
{
    cout << findNodeLevel(root, 1, num); 

/*    if (!root)
        return NULL;
    
    if (root->leftChild)
    {
        Node *left = linkedList(root->leftChild);
        while(left->rightChild)
            left = left->rightChild;
        
        left->rightChild = root;
        root->leftChild = left;
    }

    if (root->rightChild)
    {
        Node *right = linkedList(root->rightChild);
        while(right->leftChild)
            right = right->leftChild;
        
        right->leftChild = root;
        root->rightChild = right;
    }
*/
//    return root;
}

int main()
{
    Node *root = createTree();
    int num, k;
    cout << "\n Inorder Traversal : \n";
    inOrderTraversal(root);
    cout << "\n Enter node number : \t";
    cin >> num;
    cout << "\n Enter distance : \t";
    cin >> k;
    kDistanceNodes(root, num, k);
    cout << endl;
    return 1;
}



