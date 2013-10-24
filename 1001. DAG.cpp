#include <iostream>
#include <vector>
using namespace std;
struct edge
{
    int dis;
    edge(int a)
    {
        dis = a;
    }
};
int visit[101] = {0};
vector<edge> v[101];
bool is = 0;
void dfs(int current)
{
    if (is == 1)
    return;
    for (int j = 0;j < v[current].size();j++)
    {
        if (visit[v[current][j].dis] == -1)
            is = 1;
        else if (visit[v[current][j].dis] == 0)
        {
            visit[v[current][j].dis] = -1;
            dfs(v[current][j].dis);
            visit[v[current][j].dis] = 1;
        }
        else if (visit[v[current][j].dis] == 1)
            continue;
    }


}
int main()
{
    int n,m;
    int x,y;
    cin>>n>>m;
    for (int i = 0; i < m;i++)
    {
        cin>>x>>y;
        v[x].push_back(edge(y));
    }
    for (int i = 1;i <= n;i++)
    {
        if (visit[i] == 0)
        {
            visit[i] = -1;
            dfs(i);
            visit[i] = 1;
        }
    }
    if (is == 1)
    cout<<0<<endl;
    else
    cout<<1<<endl;
}
