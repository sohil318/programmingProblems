#include <iostream>
#include <stack>
using namespace std;

typedef struct IntList {
    int val;
    IntList *next;
} IntList;

void addFront(IntList **head)
{
    int n;
    IntList *temp = new IntList;
    cout << "\nEnter Number : ";
    cin >> n;
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


void searchList(IntList *head)
{
    int n;
    cout << "\nEnter Element to be searched : ";
    cin >> n;
    while (head)
    {
        if (head->val == n)
        {
            cout << "\nFound Element \n";
            return;
        }
        head = head->next;
    }
    cout << "\nElement Not found. \n";
}

/****  Merge two Linked Lists ****/

IntList* mergeLL(IntList *first, IntList *second)
{
    IntList *l1 = first, *h3, *h2;
    IntList *l2 = second;
    IntList *l3 = NULL;

    while ((l1) && (l2))
    {
        if (l1->val < l2->val)
        {
            if (l3)
            {
                l3->next = l1;
                l3 = l3->next;
            }
            else
            {
                h3 = l1;
                l3 = h3;
            }
            l1 = l1->next;
            l3->next = NULL;
        }
        else
        {
            if (l3)
            {
                l3->next = l2;
                l3 = l3->next;
            }
            else
            {
                h3 = l2;
                l3 = h3;
            }
            l2 = l2->next;
            l3->next = NULL;
        }
    }
    if (l1)
        l3->next = l1;
    if (l2)
        l3->next = l2;
//    cout << "\nMerged LinkedList : ";
    return h3;
}

/****  Split of Linked Lists ****/
int splitLL(IntList *head, IntList **first, IntList **second)
{
    if (head == NULL)
        return 1;

    IntList *slow = head, *prev;
    IntList *fast = head;
    while ((fast) && (fast->next))
    {
        fast  = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    *second = slow;
    prev->next = NULL;
    *first  = head;
    return 1;
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

/****  MergeSort of Linked Lists ****/

IntList* mergeSort(IntList *head)
{
    IntList *first, *second, *final = NULL;
    IntList *l3 = NULL;
    
    if ((head == NULL) || (head->next == NULL))
        return head;

    splitLL(head, &first, &second);
    //printList(first);
    //printList(second);
    first  = mergeSort(first);
    second = mergeSort(second);

    final = mergeLL(first, second);

    return final;
}

IntList* createLinkList(IntList *head)
{   
    addBack(&head, 8);
    addBack(&head, 5);
    addBack(&head, 2);
    addBack(&head, 7);
    addBack(&head, 9);
    addBack(&head, 1);
    addBack(&head, 3);
    addBack(&head, 6);
    addBack(&head, 4);
    return head;
}


int main() {
    IntList *l1 = NULL;
    l1 = createLinkList(l1);
    cout << "\nInitial State of Linked List : \n";
    printList(l1);
    IntList *sortedLL = mergeSort(l1);
    cout << "\nSorted State of Linked List : \n";
    printList(sortedLL);
    
    cout << endl;
    return 0;
}

