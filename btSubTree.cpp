#include <iostream>
#include <vector>
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
    root->rightChild->leftChild = newNode(8);
    root->rightChild->rightChild = newNode(15);
    root->leftChild->leftChild->leftChild = newNode(2);
    root->leftChild->leftChild->leftChild->leftChild = newNode(1);
    root->leftChild->leftChild->leftChild->rightChild = newNode(3);
    root->rightChild->leftChild->leftChild = newNode(7);
    root->rightChild->leftChild->rightChild = newNode(9);
    root->leftChild->rightChild->leftChild = newNode(7);
    root->leftChild->rightChild->rightChild = newNode(9);
    root->rightChild->rightChild->leftChild = newNode(14);
    root->rightChild->rightChild->rightChild = newNode(16);
    root->leftChild->rightChild->leftChild->leftChild  = newNode(2);
    root->leftChild->rightChild->leftChild->rightChild = newNode(11);
    root->rightChild->leftChild->leftChild->leftChild  = newNode(2);
    root->rightChild->leftChild->leftChild->rightChild  = newNode(11);
    return root;
}

Node* createSubTree()
{
    Node *root = newNode(8);
    root->leftChild = newNode(7);
    root->rightChild = newNode(9);
    root->leftChild->leftChild = newNode(2);
    root->leftChild->rightChild = newNode(11);
    return root;
}

int checkSubTreeProperty(Node* root, Node *subRoot)
{
    if (!subRoot)
        return 1;

    if (!root)
        return 0;

    int lret = checkSubTreeProperty(root->leftChild, subRoot->leftChild); 
    int rret = checkSubTreeProperty(root->rightChild, subRoot->rightChild);
    if (root->val == subRoot->val)
        return (1 && lret && rret);
    return 0;
}

int preOrderTraversal(Node* root, Node *subRoot)
{
    static int ret = 0;
    if (!subRoot)
        return 0;

    if (!root)
        return 0;

    if (root->val == subRoot->val)
    {
        ret += checkSubTreeProperty(root, subRoot);
        //cout << "\nReturn == "<< ret;
    }
    preOrderTraversal(root->leftChild, subRoot);
    preOrderTraversal(root->rightChild, subRoot);
    return ret;
}


int main()
{
    Node *root = createTree();
    Node *subRoot = createSubTree();
    if (preOrderTraversal(root, subRoot))
        cout << "\nSubTree is available.\n";
    else
        cout << "\nSubTree is NOT available.\n";
    return 1;
}

