#include <iostream>
#include <stack>
using namespace std;

typedef struct IntList {
    int val;
    IntList *next;
} IntList;

void addFront(IntList **head, int n)
{
    IntList *temp = new IntList;
    if (!(*head))
    {
        temp->val = n;
        temp->next = NULL;
        *head = temp;
        return;
    }
    temp->val = n;
    temp->next = *head;
    *head = (temp);
}

IntList* addBack(IntList **head, int n)
{
    IntList *front = *head;
    IntList *temp = new IntList;
    if (!(*head))
    {
        temp->val = n;
        temp->next = NULL;
        *head = temp;
        return temp;
    }
    while (front->next)
    {
        front = front->next;
    }
    temp->val = n;
    temp->next = NULL;
    front->next = (temp);
    return temp;
}

int calcLength(IntList * head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

IntList *linkListReversal(IntList *head, int len)
{
    int count = 1;
    IntList *prev, *next, *mid;
    while (count < len)
    {
        count++;
        head = head->next;
    }
    mid  = head;
    head = head->next;
    prev = NULL;
    //cout << "mid = " << mid->val;
    //cout << "prev = " << prev->val;
    //cout << "head = " << head->val;

    while (next)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    mid->next = prev;
    
    return prev;
}

IntList* reverseSecondHalf(IntList *head)
{
    int len;
    len = calcLength(head);
    if (len % 2 == 0)
        return linkListReversal(head, len/2);
    else
        return linkListReversal(head, len/2 + 1);
}

int checkPalindrome(IntList *head, IntList *mid)
{
    while (mid)
    {
        if (head->val != mid->val)
            return 0;
        head = head->next;
        mid  = mid->next;
    }
    return 1;
}


IntList* createCycleinList(IntList *head)
{   
    addBack(&head, 4);
    addBack(&head, 5);
    addBack(&head, 6);
    addBack(&head, 7);
    addBack(&head, 8);
    addBack(&head, 7);
    addBack(&head, 6);
    addBack(&head, 5);
    addBack(&head, 4);
    return head;
}

void printList(IntList *head)
{
    cout << "Printing List ... ";
    while (head)
    {
        cout << head->val << "\t";
        head = head->next;
    }
}

int main() {
    IntList *l1 = NULL;
    l1 = createCycleinList(l1);
    cout << "\nInitial State of Linked List : \n";
    printList(l1);
    IntList *mid = reverseSecondHalf(l1);
    cout << "\nModified State of Linked List : \n";
    printList(l1);
    if (checkPalindrome(l1, mid))
        cout << "\nLinked List is a Palindrome.";
    else
        cout << "\nLinked List is NOT a Palindrome.";
    
    cout << endl;
    return 0;
}

