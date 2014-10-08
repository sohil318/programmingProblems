#include <iostream>
using namespace std;

int maxFun(int a, int b)
{
    return (a > b ? a : b);
}

int findLPSS(char arr[], int start, int end)
{
    if (start == end)
        return 1;
    else if ((start == end - 1) && (arr[start] == arr[end]))
    {
        return 2;
    }
    else if (arr[start] == arr[end])
    {
        return findLPSS(arr, start+1, end-1) + 2;
    }
    else if (arr[start] != arr[end])
    {
        return maxFun(findLPSS(arr, start, end-1), findLPSS(arr, start+1, end));
    }
    return -1;
}

int dpsolution(char arr[], int len)
{
    int mat[len][len], j;
    for (int i = 0; i < len; i++)
        mat[i][i] = 1;
    for (int substrlen = 2; substrlen <= len; substrlen++)
    {
        for (int i = 0; i < len - substrlen + 1; i++)
        {
            j = i + substrlen - 1;
            if ((arr[i] == arr[j]) && (substrlen == 2))
                mat[i][j] = 2;
            else if (arr[i] == arr[j])
                mat[i][j] = mat[i+1][j-1] + 2;
            else
                mat[i][j] = maxFun(mat[i][j-1], mat[i+1][j]);
        }
    }
    /*
    cout << endl;
    for (int i = 0; i < len; i++)
    {
        for (j = 0; j < len; j++)
            cout << mat[i][j] << "\t";
        cout << endl;
    }
    */
    return mat[0][len-1];
}

int main()
{
    char arr[] = "BABABCBABAAAABA";
    int len = sizeof(arr)/ sizeof(char);

    int palinlen  = findLPSS(arr, 0, len-1);

    cout << "\nLongest palindromic sub sequence : \t" << palinlen << "\n";

    cout << "\nDP Solution = \t" << dpsolution(arr, len - 1) << endl;
    return 0;
}



