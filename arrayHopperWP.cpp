#include <iostream>
using namespace std;

int min(int x, int y) { return (x < y)? x: y; }

int minJumps(int arr[], int n)
{
    int *jumps = new int[n];
    int *njumps = new int[n];
    int i, j, temp;

    if (n == 0 || arr[0] == 0)
        return 10000000;

    jumps[0] = 0;
    njumps[0] = 0;
    for (i = 1; i < n; i++)
    {
        jumps[i] = 10000000;
        for (j = 0; j < i; j++)
        {
            if (i <= j + arr[j] && jumps[j] != 10000000)
            {
                jumps[i] = min(jumps[i], jumps[j] + 1);
                if (jumps[i] == jumps[j] + 1)
                    temp = j;
                break;
            }
        }
        njumps[i] = j;
        //cout << "\t" << arr[j] << "\t" << j << endl;
    }
    cout << endl;
    i = n-1;
    while (i != 0)
    {
        cout << "\t" << arr[i];
        i = njumps[i];
    }
    cout << "\t" << arr[0];
    return jumps[n-1];
}

int main()
{
    int arr[] = {1, 3, 5, 8, 1, 2, 6, 7, 6, 8, 9};
    int size = sizeof(arr)/sizeof(int);
    int count = minJumps(arr,size);
    cout << "\nMinimum jumps to last element :" << count << endl;
    return 0;
}
