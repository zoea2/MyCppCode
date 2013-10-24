#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    int t,n;
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        int price[n];
        for (int i = 0;i < n;i++)
            cin>>price[i];
        if (n < 3)
        {
            cout<<"0"<<endl;
            continue;
        }
        sort(price,price + n,cmp);
        int sum = 0,i = 2;
        for ( ;i < n ;i += 3)
        {
            sum += price[i];
        }
         cout<<sum<<endl;
    }
}
