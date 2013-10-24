#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(string a,string b)
{
    if(a+b > b+a)
    return true;
    else
    return false;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n)
    {
        string num[n];
        for(int i = 0;i < n;i++)
            cin>>num[i];
        sort(num,num+n,cmp);
        for(int i = 0;i < n;i++)
        cout<<num[i];
        cout<<endl;
        scanf("%d",&n);
    }
}
