#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    while (n != 0 || m != 0)
    {
        int num[n];
        for (int i = 0;i < n;i++)
            scanf("%d",&num[i]);
        sort(num,num + n);
        int i = m ;
        cout<<num[0];
        for (;i < n;i += m )
        cout<<" "<<num[i];
        cout<<endl;
        cin>>n>>m;
    }
}
