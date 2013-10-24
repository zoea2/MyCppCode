#include<iostream>
using namespace std;
int father[100001];
int find(int x)
{
    if (father[x] != x)
        father[x] = find(father[x]);
    return father[x];
}
int main()
{
    int n,m;
    cin>>n;
    int count = 1;
    char q;
    int a,b;
    while(n != 0)
    {
        cin>>m;
        cout<<"case "<<count<<":"<<endl;
        count++;
        for (int i = 0;i <= n;i++)
            father[i] = i;
        for (int i = 0;i < m;i++)
        {
            cin>>q>>a>>b;
            if (q == 'F')
            {
                a = find(a);
                b = find(b);
                if(father[a] != b)
                {
                    father[a] = b;
                    cout<<"Merge"<<endl;
                }
                else
                cout<<"Done"<<endl;
            }
            else if (q == 'Q')
            {
                a = find(a);
                b = find(b);
                if (a == b)
                cout<<"Yes"<<endl;
                else
                cout<<"No"<<endl;
            }
        }
        cin>>n;
    }
}
