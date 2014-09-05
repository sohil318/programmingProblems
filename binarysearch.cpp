#include <iostream>
using namespace std;

int main()
{
    int n, i, flag = 0, low, high, mid, x;
    cout << "Enter Size : \t";
    cin >> n;
    int a[n];
    for ( i = 0; i < n; i++)
        cin >> a[i];
    low = 0;
    high = n;
    cout << "Enter Search Element : \t";
    cin >> x;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if ( a[mid] == x )
        {
            cout << "\nSearch Element at position : " << mid+1 << endl;
            return 0;
        }
        else if (a[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << "\nSearch element not found. \n";
    return 0;
}
