// source code of submission 1062446, Zhongshan University Online Judge System
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n ;

    int c = 1;
    int a[n][n];

    int k;
    if (n % 2 == 0)
    k = n / 2;
    else
    k = (n + 1) / 2;


    for (int i = 0; i < k; ++ i)
    {


        for (int m = i; m < n - i; ++ m)
        {
            a[i][m ]= c;
            ++ c;

        }

        for (int m = 0 + 1 + i; m < n - i ; ++ m)
        {
            a[m][n - i - 1] = c;
            ++ c;

        }

        for (int m = n - 2 - i; m >  i ; -- m)
        {
            a[n - 1 - i][m] = c;
            ++ c;
        }

        for (int m = n - 1 - i; m > i ; -- m)
        {
            a[m][i] = c;
            c ++;
        }
    }
    for (int k = 0; k < n; ++ k )
        {

            for (int l = 0; l < n - 1; ++ l)
            cout << a[k][l]<< " ";
            cout << a[k][n - 1];
            cout << endl;
        }



    return 0;
}
