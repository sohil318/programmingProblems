#include <iostream>
using namespace std;

int main()
{
    int n, count = 0;
    cout << "Enter Element : \t";
    cin >> n;
    while (n > 0)
    {
        if (n % 2 == 0)
            n /= 2;
        else
            n -= 1;
        count++;
    }
    cout << "\nNth element =  \t" << count << endl;
    return 0;
}

