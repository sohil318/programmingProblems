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

void inOrderTraversal(Node* root)
{
    if (!root)
        return;

    inOrderTraversal(root->leftChild);
    cout << "\t" << root->val;
    inOrderTraversal(root->rightChild);
    return;
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

int nodesCount(Node* root)
{
    if (!root)
    {
        return 0;
    }
    else
        return (nodesCount(root->leftChild) + 1 + nodesCount(root->rightChild));
}

int main()
{
    Node *root = createTree();
    inOrderTraversal(root);
    cout << endl;
    preOrderTraversal(root);
    cout << endl;
    postOrderTraversal(root);
    cout << endl;
    cout << nodesCount(root);
    return 1;
}
