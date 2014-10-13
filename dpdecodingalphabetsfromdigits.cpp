#include <iostream>
using namespace std;

int countEncoding (char str[], int len)
{
    int count[len];
    
    if (len == 0)
        return 1;
        
    count[0] = 1;
    count[1] = 1;
    if ((str[0] - '0' < 3) && (str[1] - '0' < 7)) 
            count[0] += 1;
    
    for (int i = 2; i < len; i++)
    {
        count[i] = count[i - 1] + 1;
        if ((str[i-1] - '0' < 3) && (str[i] - '0' < 7)) 
            count[i] += 1;
    }
    return count[len-1];
}

int main()
{
    char str[] = "111";
    int len = sizeof(str)/ sizeof(char);
    int count = countEncoding(str, len-1);

    cout << "\nMaximum Number of encoding possible : \t" << count << endl;
    return 0;
}



