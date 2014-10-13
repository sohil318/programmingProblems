#include <iostream>
using namespace std;

int calculateProd(int a[], int start, int end)
{
    int prod = 1;
    //cout << "\nStart : \t" << start << "\t End : \t" << end;
    for (int i = start; i < end; i++)
        prod *= a[i];
    //cout << "\nProd = \t" << prod;
    return prod;
}

int* getMaxProd(int a[], int start, int end)
{
    int i, j, count = 0, *resultArray, firstNegIndex, lastNegIndex;
    resultArray = (int *)malloc(sizeof(int) * 3);
    for (i = start; i < end; i++)
    {
        if ((a[i] < 0) && (count == 0))
            firstNegIndex = i;
        if (a[i] < 0)
        {
            count++;
            lastNegIndex = i;
        }
    }
    //cout << "\nCount = \t" << count << "First Neg Index = \t " << firstNegIndex << "\tLast Neg Index : \t" << lastNegIndex <<"\n";
    if (count % 2 == 0)
    {
        resultArray[0] = start;
        resultArray[1] = end - 1;
        resultArray[2] = calculateProd(a, start, end);
    }   
    else if (a[firstNegIndex] > a[lastNegIndex])
    {
        //    cout << "\nIn first else\n";
        resultArray[0] = firstNegIndex;
        resultArray[1] = end - 1;
        resultArray[2] = calculateProd(a, firstNegIndex + 1, end);
    }
    else
    {
        //    cout << "\nIn second else\n";
        resultArray[0] = start;
        resultArray[1] = lastNegIndex - 1;
        resultArray[2] = calculateProd(a, start, lastNegIndex);
    }
    return resultArray;
}

int* findLCSP(int a[], int len)
{
    int max = a[0], *tempArray, *resultArray, startIndex, endIndex;
    tempArray = (int *)malloc(sizeof(int) * 3);
    resultArray = (int *)malloc(sizeof(int) * 3);
    startIndex = 0;
    endIndex = 0;
    for (int i = 0; i < len; i++)
    {
        endIndex = i;
        if (a[i] == 0)
        {
            tempArray = getMaxProd(a, startIndex, endIndex);
            if (tempArray[2] > max)
            {
                max = tempArray[2];
                resultArray[0] = tempArray[0];
                resultArray[1] = tempArray[1];
                resultArray[2] = tempArray[2];
            }
            startIndex = i + 1;
        }
    }
    cout << "Inside == 0" << startIndex << endIndex;
    tempArray = getMaxProd(a, startIndex, endIndex + 1);
    //cout << "\tTemp Array : \t " << tempArray[0] << "\t " << tempArray[1] << "\t" << tempArray[2];
    if (tempArray[2] > max)
    {
        max = tempArray[2];
        resultArray[0] = tempArray[0];
        resultArray[1] = tempArray[1];
        resultArray[2] = tempArray[2];
    }
    return resultArray;
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int len = sizeof(arr)/ sizeof(int);

    int *sum = findLCSP(arr, len);

    cout << "\nSum of longest continous sequence product : \t" << sum[2] << "\tstarting at index : " << sum[0] << "\t and ending at index : " << sum[1] << "\n";
    return 0;
}


