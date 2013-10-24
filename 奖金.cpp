#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> vec[10001];
int ind[10001] = {0};
struct emp
{
    int index;
    int cla;
};
int main()
{
    int n,m;
    cin>>n;
    emp e[n+1];
    for (int i = 1;i <= n;i++)
    {
        e[i].index = i;
        e[i].cla = 0;
    }
    cin>>m;
    int x,y;
    for (int i = 0;i < m;i++)
    {
        cin>>x>>y;
        vec[y].push_back(x);
        ind[x]++;
    }
    int count = 0,count0 = 0;
    queue<emp> q;
    for (int i = 1;i <= n;i++)
    {
        if (!ind[i])
        q.push(e[i]);
    }
    while(!q.empty())
    {
        emp temp = q.front();
        q.pop();
        count0++;
        for (int i = 0;i < vec[temp.index].size();i++)
        {
            if (!--ind[vec[temp.index][i]])
            {
                e[vec[temp.index][i]].cla = temp.cla + 1;
                q.push(e[vec[temp.index][i]]);
            }
        }
    }
    if (count0 < n)
    cout<<"Poor Xed"<<endl;
    else
    {
        for (int i = 1;i <= n;i++)
        count += e[i].cla + 100;
        cout<<count<<endl;
    }
}
