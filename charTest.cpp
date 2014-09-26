#include <iostream>
#include <string>

using namespace std;

int main()
{
    //int *a = {1,2,3};
    //char *arr = {'a','b','c'};
    //char *arr1 = {'a','b','c','\0'};
    char arr4[] = "Hello";
    char arr2[3] = {'a','b','d'};
    char arr3[] = {'a','b','c','\0'};
    //char arr4[] = "Hello";
    cout << strlen(arr3) << strlen(arr2) << endl << arr4;
    arr4[5] = 'D';
    cout << endl << arr4 << endl;
    return 0;
}

