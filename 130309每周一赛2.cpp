#include <iostream>
#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n;

    ios::sync_with_stdio;
    scanf("%d",&n);
    int m[n];
    int temp;
    int count = 0;
    for (int i = 0;i < n;i++)
    {
        scanf("%d",&temp);
        if(temp == 1)
            count++;
        m[i] = temp;
    }
    int i = 0;
    sort(m,m+n);
    int sum = 0;
    //int count = 0;
    while(m[i] < n-1)
    {
        sum += m[i];
        n--;
        n -= m[i];
        i++;
    }
    sum += n-1;
    printf("%d",sum);
}
