#include <iostream>
using namespace std;

int main()
{
    int n, i, flag = 0, sum = 0, leftsum = 0;
    cout << "Enter Size : \t";
    cin >> n;
    int a[n];
    for ( i = 0; i < n; i++)
    {
        cout << "Enter element "<< i+1 << " : \t";
        cin >> a[i];
        sum += a[i];
    }
    for (i = 0; i < n; i++)
    {
        if (((sum - a[i])%2 == 0) && (leftsum == (sum - a[i])/2))
            break;
        
        leftsum = leftsum + a[i];
    }
    if (i == n)
        cout << "\nNo such element found . \n";
    else
        cout << "\n Element " << a[i] << " at position " << i+1 << "in the array has sum of left and right elements equal. " << endl;
    return 0;
}

