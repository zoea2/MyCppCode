#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstdlib>
using namespace std;
long long count;
string result;
string change1(int a)
{
    string b;
    char temp;
    while (a != 0)
    {
        temp = (a % 2) + '0';

        b = temp + b;
        a /= 2;
    }

    return b;
}
int change2(string b)
{
    long long total = 0;
    int temp;
    for (int i = 0;i < b.length();i++)
    {
       temp = b[b.length() - 1 - i] - '0';
       total += temp * pow (2.0,i);
    }

    return total;
}
void cmp(string a,string b)
{

    int cha = a.length() - b.length();
    if (cha < 0)
        cha = -cha;
    int sht = (a.length() > b.length()) ? b.length() : a.length();
    for (int i = 0;i < cha;i++)
    {
       result.insert(i,1,'1');
    }
    if (a.length() > b.length())
    {
        for (int i = sht - 1; i >= 0 ;i--)
        {
           char temp = (b[i] ^ a[i + cha]) + '0' ;
           result.insert(cha,1,temp);

        }
    }
    else
    {
        for (int i = sht - 1; i >= 0 ;i--)
        {
            char temp = (a[i] ^ b[i + cha])+'0' ;
            result.insert(cha,1,temp);
        }
    }

}
int main()
{
    int t;
    int n;
    scanf("%d",&t);
    while (t)
    {
        t--;
        scanf("%d",&n);
        count = 0;
        int peo[n];
        string store[n];
        for (int i = 0;i < n;i++)
        {
            scanf("%d",&peo[i]);
            store[i] = change1(peo[i]);
        }

        for (int i = 0;i < n;i++)
        {
            for (int j = i + 1;j < n ;j++)
            {
                cmp(store[i],store[j]);
                count += change2(result);

                result.clear();
            }
        }
        printf("%d\n",count);


    }
}
