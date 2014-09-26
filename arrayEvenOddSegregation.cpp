#include <iostream>
using namespace std;

void segregateInPlace(int a[], int n)
{
    int i = 0, j = n - 1, temp; 
    while (i < j)
    {
        if ((a[i] % 2 == 0) && (a[j] % 2 == 1))
        {
            i++;
            j--;
        }
        else if ((a[i] % 2 == 1) && (a[j] % 2 == 0)) 
        {
            temp = a[i];
            a[i++] = a[j];
            a[j--] = temp;
        }
        else if (a[i] % 2 == 0)
            i++;
        else
            j--;
    }
    
    cout << "\nSegregated Array : \n";
    for ( i = 0; i < n; i++)
    {
        cout << "\t" << a[i];
    }
    cout << endl; 
    return;
}

void segregateInOrder(int a[], int n)
{
    int i = 0, j = n - 1, k, temp; 
    for (i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
            continue;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] % 2 == 1)
                continue;
            break;
        }
        if ((a[i] % 2 == 1) && (a[j] % 2 == 0)) 
        {
            temp = a[j];
            for ( k = j; k > i; k--)
                a[k] = a[k-1];
            a[i] = temp;
        }
    }
    
    cout << "\nSegregated Array InOrder: \n";
    for ( i = 0; i < n; i++)
    {
        cout << "\t" << a[i];
    }
    cout << endl; 
    return;
}

int main()
{
    int n, i;
    cout << "Enter Size : \t";
    cin >> n;
    int a[n];
    for ( i = 0; i < n; i++)
    {
        cout << "Enter element "<< i+1 << " : \t";
        cin >> a[i];
    }
    segregateInOrder(a, n);
    segregateInPlace(a, n);
    return 0;
}
