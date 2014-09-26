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
    Node *temp = newNode(100);
    temp->leftChild = newNode(50);
    temp->leftChild->leftChild = root;
    temp->rightChild = newNode(150);
    temp->rightChild->rightChild = newNode(180);
    root = temp;
    return root;
}

int height = 0;

int getBTHeight(Node* root, int level)
{
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

int diameterTree(Node* root)
{
    static int maxHt = 0;
    int ht, leftHeight = 0, rightHeight = 0;

    if (!root)
        return 0;
    

    if (root->leftChild)
        leftHeight = getBTHeight(root->leftChild, 0);
    height = 0;
    if (root->rightChild)
        rightHeight = getBTHeight(root->rightChild, 0);
    height = 0;

    if ((leftHeight + rightHeight + 1) > maxHt)
        maxHt = leftHeight + rightHeight + 1;
    
    diameterTree(root->leftChild);
    diameterTree(root->rightChild);
    return maxHt;

}


int main()
{
    
    Node *root = createTree();
    cout << "\nDiameter of the tree : \t " << diameterTree(root) << endl;
    //cout << endl << "\nNo of Nodes : \t" << nodesCount(root) << endl;
    return 0;

}
