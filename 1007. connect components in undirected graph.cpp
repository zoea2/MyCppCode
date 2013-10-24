#include <iostream>
#include <vector>
using namespace std;
vector<int> vec[1001];
int visit[1001];
void dfs(int current)
{
    for (int i = 0;i < vec[current].size();i++)
    {
        if (visit[vec[current][i]] == 0)
        {
            visit[vec[current][i]] = 1;
            dfs(vec[current][i]);
        }
    }
}
int main()
{
    int n,m;
    int v,y;
    cin>>n>>m;
    for (int i = 0;i < m;i++)
    {
        cin>>v>>y;
        vec[v].push_back(y);
        vec[y].push_back(v);
    }
    int count = 0;
    for (int i = 1;i <=n;i++)
    {
        if (visit[i] == 0)
        {
            visit[i] = 1;
            count++;
            dfs(i);
        }
    }
    cout<<count<<endl;
}
