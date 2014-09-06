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

void addBack(IntList **head)
{
    int n;
    IntList *front = *head;
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
    while (front->next)
    {
        front = front->next;
    }
    temp->val = n;
    temp->next = NULL;
    front->next = (temp);

}
void delFront(IntList **head)
{
    IntList *temp = *head;
    if (temp)
    {
        cout << " Deleting Front Element : " << temp->val << endl;
        *head = temp->next;
        delete(temp);
    }
    else
        cout << "No element at the front. \n";
}
void delBack(IntList **head)
{
    IntList *front = *head;
    IntList *back;
    if (front)
    {
        if (front->next)
        {
            while (front->next)
            {
                back = front;
                front = front->next;
            }
            cout << " Deleting Last Element : " << front->val << endl;
            back->next = NULL;
            delete(front);
        }
        else
        {
            cout << " Deleting Last Element : " << front->val << endl;
            delete(front);
            *head = NULL;
        }
    }
    else
        cout << "No element in the list. \n";
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

IntList *recLinkListReversal(IntList *head, int k)
{
    IntList *prev = NULL, *next = NULL, *temp = head;
    int count = 1;
    while ((count <= k) && (temp))
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        count++;
        temp = next;
    }
    if (next)
        head->next = recLinkListReversal(next, k);

    return prev;
}

void kWidthListReversal(IntList **head)
{
    int k;
    cout << "\nEnter k bucket size to reverse in slots of k : ";
    cin >> k;
    *head = recLinkListReversal(*head, k);
}

void kthElementListSwap(IntList **head)
{
    int k, count = 0, i;
    IntList *temp = *head, *front, *back, *prevBack, *prevFront, *nextBack, *nextFront;
    cout << "\nEnter k bucket size to reverse in slots of k : ";
    cin >> k;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    //cout << "Total Elements : " << count;
    if (k > count)
    {
        cout << "\nLinked List size is smaller than K.\n";
        return;
    }
    else if ((k == (count+1)/2) && (count%2 == 1))
    {
        cout << "\nkth Element is same from both ends hence they are swapped.\n";
        return;
    }
    else if (k > count/2)
    {
        k = count + 1 - k;
    }
    i = 1;
    front = *head;
    while (i < count - k + 1)
    {
        prevFront = front;
        front = front->next;
        nextFront = front->next;
        if ((i == k-1) and (k > 1))
        {
            prevBack = prevFront;
            back = front;
            nextBack = nextFront;
        }
        else if (k==1)
        {
            prevBack = NULL;
            back = *head;
            nextBack = (*head)->next;
        }
        i++;
    }
    //cout << "\nprevFront :" << prevFront->val << "nextFront : " << nextFront->val; 
    //cout << "\nprevBack :" << prevBack->val << "nextBack : " << nextBack->val; 
    if (back->next == front)
    {
        front->next = back;
        if (prevBack)
            prevBack->next = front;
        else
            *head = front;
        back->next = nextFront;
    }
    else
    {
        prevFront->next = back;
        back->next = nextFront;
        if (prevBack)
            prevBack->next = front;
        else
            *head = front;
        front->next = nextBack;
    }
    //cout << "\nFront = \t" << front->val << "\tBack = \t" << back->val;
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
    int choice;
    while (1)
    {
        cout << "\nEnter your Choice (1 - 8) := \n 1. Add to front \n 2. Add to back \n 3. Delete from Front \n 4. Delete from back \n 5. Search if element is present \n 6. Reverse in k chunks \n 7. Swap kth element \n 8. Exit. \n \n";
        cin >> choice;
        switch (choice)
        {
            case 1:
                addFront(&l1);
                printList(l1);
                break;
            case 2:
                addBack(&l1);
                printList(l1);
                break;
            case 3:
                delFront(&l1);
                printList(l1);
                break;
            case 4:
                delBack(&l1);
                printList(l1);
                break;
            case 5:
                searchList(l1);
                printList(l1);
                break;
            case 6:
                kWidthListReversal(&l1);
                printList(l1);
                break;
            case 7:
                kthElementListSwap(&l1);
                printList(l1);
                break;
            case 8:
                printList(l1);
                exit(1);
                break;
            default:
                cout << "Enter appropriate choices. \n";
        }
    }
    return 0;
}

