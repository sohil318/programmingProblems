#include <iostream>
using namespace std;

int main() {
    int i, j, k, l, t1, t2;
    int a[10] = {1,3,5,7,9,11,13,15,17,19};
    int b[5] = {2,4,6,8,10};

    /*
       for (i = 0; i < 10 ; i++)
       cin>>a[i];
       for (j = 0; j < 5; j++)
       cin>>b[j];
       */
    while (b[0] < a[9]) 
    {
        if (b[0] < a[9])
        {
            for (i = 0; i < 10; i++)
                if ( b[0] > a[i] )
                    continue;
                else
                    break;
            
            t2 = a[9];
            for ( k = 9; k > i; k--)
                a[k] = a[k-1];
            
            a[i] = b[0];

            for ( l = 0 ; l < 5; l++)
                if (b[l] < t2)
                    continue;
                else
                    break;
            
            for (k = 0; k < l-1; k++)
                b[k] = b[k+1];
            
            b[l-1] = t2;
        }
    }
    cout << "Both arrays are sorted when combined together \n";
    for (i = 0; i < 10 ; i++)
        cout << a[i] << "\t";
    cout << endl;
    for (j = 0; j < 5; j++)
        cout << b[j] << "\t";
    return 0;
}
