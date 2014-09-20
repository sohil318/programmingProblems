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
    Node *root = newNode(50);
    root->leftChild = newNode(7);
    root->rightChild = newNode(2);
    root->leftChild->leftChild = newNode(3);
    root->leftChild->rightChild = newNode(5);
    root->rightChild->leftChild = newNode(1);
    root->rightChild->rightChild = newNode(30);
    /*
    root->leftChild->leftChild->leftChild = newNode(2);
    root->leftChild->leftChild->leftChild->leftChild = newNode(1);
    root->leftChild->leftChild->leftChild->rightChild = newNode(3);
    root->leftChild->rightChild->leftChild = newNode(7);
    root->leftChild->rightChild->rightChild = newNode(9);
    root->rightChild->rightChild->leftChild = newNode(14);
    root->rightChild->rightChild->rightChild = newNode(16);
    */
    return root;
}

void fixTree(Node *root, int diff)
{
    //cout << "\nRoot->val " << root->val;
    root->val += diff;
    if ((root->leftChild == NULL) and (root->rightChild == NULL))
        return;
    else if (root->leftChild == NULL)
        fixTree(root->rightChild, diff);
    else
        fixTree(root->leftChild, diff);
    
    return;
}

int sumProperty(Node* root)
{
    int sum; 
    if (!root)
        return 0;
    
    int left = sumProperty(root->leftChild);
    int right = sumProperty(root->rightChild);

    if ((root->leftChild == NULL) && (root->rightChild == NULL))
        return root->val;
    else if (root->leftChild == NULL)
        sum = right;
    else if (root->rightChild == NULL)
        sum = left;
    else
        sum = left + right;

    if (sum >= root->val)
        root->val = sum;
    else
        fixTree(root->leftChild, root->val - sum);

    return root->val;
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
    //inOrderTraversal(root);
    //cout << endl;
    preOrderTraversal(root);
    cout << endl;
    postOrderTraversal(root);
    cout << endl;
    cout << nodesCount(root);
    sumProperty(root);
    cout << "\nModified Sum Tree: ";
    preOrderTraversal(root);
    cout << endl;
    return 1;
}

