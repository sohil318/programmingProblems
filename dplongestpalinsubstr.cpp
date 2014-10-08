#include <iostream>
using namespace std;

void printString(char a[], int index, int len)
{
    cout << "\nSubstring Palindrome :\t";
    for (int i = 0; i < len; i++)
        cout <<  a[ index + i];
    cout << endl;
}

int dpsolution(char arr[], int len)
{
    int mat[len][len], j, size, index, templen = 0;
    if (arr[0] != '\0')
        size = 1;

    for (int i = 0; i < len; i++)
        mat[i][i] = 1;

    for (int i = 0; i < len-1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            mat[i][i + 1] = 1;
            index = i;
            size = 2;
        }
    }
    for (int substrlen = 3; substrlen <= len; substrlen++)
    {
        for (int i = 0; i < len - substrlen + 1; i++)
        {
            j = i + substrlen - 1;
            if ((arr[i] == arr[j]) && (mat[i+1][j-1] == 1))
            {
                mat[i][j] = 1;
                templen = j-i;
                templen += 1;
                if (templen > size)
                {    
                    size = templen;
                    index = i;
                }
            }
            else
                mat[i][j] = 0;
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
    printString (arr, index, size);
    return size;
}

int main()
{
    char arr[] = "BABABCBABAAAABA";
    int len = sizeof(arr)/ sizeof(char);
    
    int tlen = dpsolution(arr, len - 1);
    cout << "\nDP Solution for longest palindromic substring =   " << tlen << endl;
    return 0;
}



