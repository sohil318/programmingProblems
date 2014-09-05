#include <iostream>
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
        cout << "\nEnter your Choice (1 - 6) := \n 1. Add to front \n 2. Add to back \n 3. Delete from Front \n 4. Delete from back \n 5. Search if element is present \n 6. Exit. \n \n";
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
                printList(l1);
                exit(1);
                break;
            default:
                cout << "Enter appropriate choices. \n";
        }
    }
    return 0;
}

