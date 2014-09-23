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

void allLeafPaths(Node* root, vector<int> path)
{
    if (!root)
        return;
    
    path.push_back(root->val);
    allLeafPaths(root->leftChild, path);
    allLeafPaths(root->rightChild, path);
    
    if ((root->leftChild == NULL) && (root->rightChild == NULL))
    {
        cout << "\nPath to " << root->val << " : ";
        for( vector<int>::iterator it = path.begin(); it != path.end(); it++)
            cout << "\t" << *it;
    }
    path.pop_back();
    return;
}

int main()
{
    Node *root = createTree();
    vector<int> path;
    inOrderTraversal(root);
    cout << "\nAll Paths : \n" << endl;
    allLeafPaths(root, path);
    

    return 1;
}
