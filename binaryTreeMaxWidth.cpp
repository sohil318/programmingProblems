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

void maxWidth(Node* root, int *count, int level)
{
    if (root)
    { 
        count[level]++;
        maxWidth(root->leftChild, count, level+1);
        maxWidth(root->rightChild, count, level+1);
    }
}

void preOrderTraversal(Node* root)
{
    if (!root)
        return;
    cout << "\t" << root->val;
    preOrderTraversal(root->leftChild);
    preOrderTraversal(root->rightChild);
    return;
}

void postOrderTraversal(Node* root)
{
    if (!root)
        return;
    postOrderTraversal(root->leftChild);
    postOrderTraversal(root->rightChild);
    cout << "\t" << root->val;
    return;
}

int main()
{
    int a[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int max = 0;
    Node *root = createTree();
    //inOrderTraversal(root);
    //cout << endl;
    preOrderTraversal(root);
    cout << endl;
    postOrderTraversal(root);
    cout << endl;
    maxWidth(root, a, 0);
    for (int i = 0; i < 10; i++)
        if (max < a[i])
            max = a[i];
    cout << "\nMax Width = \t " << max << endl;
//    cout << "\nModified Sum Tree: ";
//    preOrderTraversal(root);
//    cout << endl;
    return 1;
}

