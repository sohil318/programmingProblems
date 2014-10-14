#include <iostream>
using namespace std;

int* nextLarger(int a[], int len)
{
    int *result;
    int min = a[0];
    result = (int *)malloc(sizeof(int)*len);
    
    for (int i = 0; i < len; i++)
    {
        min = 100000;
        for (int j = i + 1; j < len; j++)
        {
            if ((a[j] > a[i]) && (a[j] < min))
                min = a[j];
        }
        if (min == 100000)
            result[i] = -1;
        else
            result[i] = min;
    }
    return result;
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
    cout << endl;
    int *r = nextLarger(a, n);
    for (i = 0; i < n; i++)
        cout << r[i] << "\t";
    cout << endl;
    return 0;
}


