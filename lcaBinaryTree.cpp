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

Node* lca(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if ((root->val == n1) || (root->val == n2))
        return root;

    Node *left = lca(root->leftChild, n1, n2);
    Node *right = lca(root->rightChild, n1, n2);
    
    if (left && right)
        return root;

    if (left == NULL)
        return right;
    else 
        return left;

}

int main()
{
    int num1, num2;
    Node *root = createTree();
    cout << "\nInOrder Traversal  == "; 
    inOrderTraversal(root);
    cout << "\nPreOrder Traversal  == "; 
    preOrderTraversal(root);
    cout << "\nPostOrder Traversal  == "; 
    postOrderTraversal(root);
    cout << "\nTotal Number of Nodes :  ";
    cout << nodesCount(root);
    cout << "\nCalculating LCA of 2 Nodes ........ \nEnter First Number :  ";
    cin >> num1;
    cout << "\nEnter Second Number :  ";
    cin >> num2;
    cout << "\nLCA of the two numbers is : \t"<< (lca(root, num1, num2))->val << endl;
    return 1;
}

