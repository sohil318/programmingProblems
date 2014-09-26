#include <iostream>
#include <queue>
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

void printNodesAtEachLevel(Node *root, int level, int direction)
{
    if (level == 0)
    {
        cout << "\t" << root->val;
        return;
    }
    if (direction % 2 == 0)
    {
        if (root->leftChild)
            printNodesAtEachLevel(root->leftChild, level-1, direction);
        if (root->rightChild)
            printNodesAtEachLevel(root->rightChild, level-1, direction);
    }
    else
    {
        if (root->rightChild)
            printNodesAtEachLevel(root->rightChild, level-1, direction);
        if (root->leftChild)
            printNodesAtEachLevel(root->leftChild, level-1, direction);

    }
    return;
}

int getBTHeight(Node* root, int level)
{
    static int height = 0;
    if ((root->leftChild == NULL) && (root->rightChild == NULL))
    {    if (level > height)
            height = level;
        return height;
    }
    if (root->leftChild)
    getBTHeight(root->leftChild, level + 1);
    if (root->rightChild)
    getBTHeight(root->rightChild, level + 1);
    return height;
}

void levelOrderTraversalRecursion(Node* root)
{
    int height = getBTHeight(root, 0);
    for (int i = 0; i <= height; i++)
    {
        cout << endl;
        printNodesAtEachLevel(root, i, i);
    }
}

void levelOrderTraversal(Node* root)
{
    queue<Node *> qe;
    Node *temp = newNode(-1);
    Node *front;

    if (root)
    {
        qe.push(root);
        qe.push(temp);
    }
    while(qe.size())
    {
        front = qe.front();
        if (front->val == -1)
        {
            cout << endl;
            qe.push(temp);
            if (qe.size() == 2)
                break;
        }
        else
        {
            cout << "\t" << front->val;
            if (front->leftChild)
                qe.push(front->leftChild);    
            if (front->rightChild)
                qe.push(front->rightChild);
        }
        qe.pop();
    }
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
    cout << "\nInOrder Traversal : \n";
    inOrderTraversal(root);
    cout << endl;
    cout << "\nPreOrder Traversal : \n";
    preOrderTraversal(root);
    cout << endl;
    cout << "\nPostOrder Traversal : \n";
    postOrderTraversal(root);
    cout << endl;
    cout << "\nLevelOrder Traversal : \n";
    levelOrderTraversal(root);
    cout << "\nLevelOrder Traversal Recursion : \n";
    levelOrderTraversalRecursion(root);
    cout << endl << "\nNo of Nodes : \t" << nodesCount(root) << endl;
    return 0;

}
