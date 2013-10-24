#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    string a;
    int count0;
    while (cin>>a&&a!="XXX")
    {
        count0 = 0;
        char temp;
        for (int i = 0;i < a.length();i++)
        {
            if (a[i] < '0' || a[i] >'9')
            {
                printf("%c",a[i]);
                temp = a[i];
            }
            else
            {
                while (a[i]>='0'&&a[i]<='9')
                {
                    count0 *= 10;
                    count0 += a[i] - '0';
                    i++;
                }
                for (int j = 0;j < count0-1;j++)
                cout<<temp;

            }
        }
        cout<<endl;
    }
}
