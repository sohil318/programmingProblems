#include <iostream>
using namespace std;

int maxFun(int a, int b)
{
    return (a > b ? a : b);
}

int findLCSS(int arr[], int len)
{
    int max = arr[0], maxall = arr[0];
    for (int i = 0; i < len; i++)
    {
        max = maxFun(arr[i], max + arr[i]);
        cout << max << "\t";
        maxall = maxFun(maxall, max);
    }
    return maxall;
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int len = sizeof(arr)/ sizeof(int);

    int sum = findLCSS(arr, len);

    cout << "\nSum of longest continous sequence sum : \t" << sum << "\n";
    return 0;
}


