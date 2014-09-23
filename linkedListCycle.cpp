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

IntList* createCycleinList(IntList *head)
{   
    addBack(&head, 4);
    addBack(&head, 5);
    addBack(&head, 6);
    addBack(&head, 7);
    addBack(&head, 8);
    IntList* temp = addBack(&head, 9);
    temp->next = head;
    addFront(&head, 3);
    addFront(&head, 2);
    addFront(&head, 1);
    return head;
}

IntList* listCycleFinder(IntList *head)
{
    IntList *slow = head, *fast = head;
    while (1)
    {
        //cout << slow->val << fast->val;
        if ((fast->next == NULL) || (fast->next->next == NULL))
        {
            cout << "\nNo Cycle Found";
            return NULL;
        }
        else
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (slow == fast)
            break;
    }
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
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
    IntList *l1 = NULL, *l2;
    l1 = createCycleinList(l1);
    l2 = listCycleFinder(l1);
    if (l2)
        cout << l2->val;
    //IntList *fast = l1, *slow = l2;
    
    return 0;
}
