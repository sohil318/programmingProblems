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
    static int height = 0;

int heightTree(Node* root, int level)
{
    static int height = 0;
    if ((root->leftChild == NULL) && (root->rightChild == NULL))
    {    if (level > height)
            height = level;
        return height;
    }
    if (root->leftChild)
    heightTree(root->leftChild, level + 1);
    if (root->rightChild)
    heightTree(root->rightChild, level + 1);
    return height;
}

int main()
{
    Node *root = createTree();
    cout << "\nHeight of the tree \t :" << heightTree(root, 1) << endl;
    return 1;
}
