#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
using namespace std;
vector<int> vec[101];
int inder[101];
int main()
{
    int n,m;
    ios::sync_with_stdio(false);
    cin>>n>>m;
    int x,y;
    memset(inder,0,sizeof(inder));
    memset(vec,0,sizeof(vec));
    for (int i = 0;i < m;i++)
    {
        cin>>x>>y;
        vec[x].push_back(y);
        inder[y]++;
    }
    queue<int> q;
    for (int i = 1;i <= n;i++)
        if (inder[i] == 0)
            q.push(i);
    int count = 0;
    while(!q.empty())
    {
        int a = q.front();
        q.pop();
        for (int i = 0;i < vec[a].size();i++)
        {
            inder[vec[a][i]]--;
            if (inder[vec[a][i]] == 0)
            q.push(vec[a][i]);
        }
        count++;
    }
    if (count == n)
    cout<<1<<endl;
    else
    cout<<0<<endl;
}
