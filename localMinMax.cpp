#include <iostream>
using namespace std;

int main()
{
    int n, count = 0;
    int a[100];
    cout << "Enter Array Size : \t";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter Number : \t";
        cin >> a[i];
    }
    int rising = 1, falling = 1, local = 0 ;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i-1])
        {
            if (falling == 1)
                local++;
            rising = 1;
            falling = 0;
        }
        else if (a[i] < a[i-1])
        {
            if (rising == 1)
                local++;
            falling = 1;
            rising = 0;
        }
        if ( i == n-1)
            local++;
    }
    cout << "\nNth element =  \t" << local << endl;
}
