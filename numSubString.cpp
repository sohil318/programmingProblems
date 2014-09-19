#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main()
{
    int n, n1, i = 0;
    string s, s1;
    cout << "\nEnter Number : \t";
    cin >> n;
    s = to_string(n);
    cout << "\nEnter Sub Number : \t";
    cin >> n1;
    s1 = to_string(n1);
    cout << "SUB-String Index " << strstr(s.c_str(), s1.c_str()) - s.c_str() << endl;
    return 0;
}

