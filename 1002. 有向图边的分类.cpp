#include <iostream>
#include <vector>
using namespace std;
struct edge
{
    int dis;
    int cs;
    edge(int a)
    {
        dis = a;
    }
};
vector<edge> v[101];
int f[101] = {0};
int d[101] = {0};
int visit[101] = {0};
int times = 0;
void dfs(int current)
{
    for (int i = 0;i < v[current].size();i++)
    {
        if (visit[v[current][i].dis] == -1)
        {
            v[current][i].cs = 1;
        }
        else if (visit[v[current][i].dis] == 0)
        {
            v[current][i].cs = 0;
            visit[v[current][i].dis] = -1;
            times++;
            d[v[current][i].dis] = times;
            dfs(v[current][i].dis);
            times++;
            visit[v[current][i].dis] = 1;
            f[v[current][i].dis] = times;
        }
        else if (visit[v[current][i].dis] == 1)
        {
            if (d[current] < d[v[current][i].dis])
            v[current][i].cs = 2;
            else
            v[current][i].cs = 3;
        }
    }
    //times++;
    //f[current] = times;
}
int main()
{
    int n,m;
    int u,t;
    cin>>n>>m;
    for (int i = 0;i < m;i++)
    {
        cin>>u>>t;
        v[u].push_back(edge(t));
    }
    int k;
    cin>>k;
    for (int i = 1;i <=n;i++)
    {
        if (visit[i] == 0)
        {
            visit[i] = -1;
            times++;
            d[i] = times;
            dfs(i);
            times++;
            f[i] = times;
            visit[i] = 1;
        }
    }
    //for (int i = 1;i <= n;i++)
    //cout<<d[i]<<" "<<f[i]<<endl;
    while(k--)
    {
        cin>>u>>t;
        for (int i = 0;i < v[u].size();i++)
        {
            if (v[u][i].dis == t)
            {
                if (v[u][i].cs == 0)
                cout<<"edge ("<<u<<","<<t<<") is Tree Edge"<<endl;
                if (v[u][i].cs == 1)
                cout<<"edge ("<<u<<","<<t<<") is Back Edge"<<endl;
                if (v[u][i].cs == 2)
                cout<<"edge ("<<u<<","<<t<<") is Down Edge"<<endl;
                if (v[u][i].cs == 3)
                cout<<"edge ("<<u<<","<<t<<") is Cross Edge"<<endl;
            }
        }
    }
}
