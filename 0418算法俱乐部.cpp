#include<iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    string a;
    cin>>a;
    long length = a.length();
    char max = a[0];
    for (long i = 1;i < length;i++)
    {
        if (max < a[i])
        max = a[i];
    }
    int k = 2;
    if (max >= '2'&&max<='9')
    {
        k = max - '2' + 3;
    }
    else if (max>= 'A'&&max<='Z')
    {
        k = max - 'A'+ 11;
    }
    long num;

    for (int i = k;i <= 36;i++)
    {
        num = 0;
        for (int j = 0;j < a.length();j++)
        {
            if (a[j]>= '0'&&a[j]<='9')
            {
                num = (num * i + (a[j] - '0')) % (i-1);
            }
            else if (a[j]>= 'A'&&a[j]<='Z')
            {
                num = (num * i + (a[j] - 'A' + 10))%(i-1);
            }
        }
        if (num % (i - 1) == 0)
        {
            cout<<i;
            return 0;
        }
    }
    cout<<"No solution.";
}
