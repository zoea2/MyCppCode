#include <iostream>
using namespace std;
struct monkey
{
    int next;
};
int main()
{
    int t,n,m;
    cin>>t;

    while(t--)
    {
        cin>>n>>m;
        monkey a[n+1];
        for (int i = 0;i < n;i++)
        {
            a[i].next = i+1;
        }
        a[n].next = 1;
        int p = 0;
        int q;
        for (int i = 1;i < n;i++)
        {
            int count = m;
            while(count--)
            {
                q = p;
                p = a[p].next;
            }
            if (a[0].next = p)
            a[0].next = a[p].next;
            a[q].next = a[p].next;

        }
        cout<<a[0].next<<endl;
    }
}
