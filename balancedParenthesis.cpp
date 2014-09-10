#include <iostream>
#include <vector>
using namespace std;

void balancedParenthesis(int n, int open, int close, int pos)
{
    static char expr[100];
    if (close == n)
    {
        for (int it = 0; it < 2*n; it++)
            cout << expr[it];
        cout << endl;
        return;
    }
    else
    {
    if (open < n)
    {
        expr[pos] = '(';
        balancedParenthesis(n, open+1, close, pos+1);
    }
    if (open > close)
    {
        expr[pos] = ')';
        balancedParenthesis(n, open, close+1, pos+1);
    }
    }
}

int main()
{
    int n;
    cout << "\nEnter n :";
    cin >> n;
    vector<char> expr;
    balancedParenthesis(n, 0, 0, 0);

}
