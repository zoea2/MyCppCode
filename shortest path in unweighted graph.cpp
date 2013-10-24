#include <iostream>
#include <queue>
using namespace std;
int INF = 0x7FFFFFFF;
int graph[1001][1001] = {0};
int main()
{
    int n,m;
    cin>>n>>m;
    int temp1,temp2;
    for (int i = 0;i < m;i++)
    {
        cin>>temp1>>temp2;
        graph[temp1][temp2] = 1;
        graph[temp2][temp1] = 1;
    }
    queue<int> q;
    q.push(1);
    int dis[1001];
    for (int i = 0;i < 1002;i++)
        dis[i] = INF;
    dis[1] = 0;
    int flag[1001] = {0};
    flag[1] = 1;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (int i = 1;i <= n;i++)
        {
            if (graph[temp][i] == 1&&!flag[i])
            {
                dis[i] = dis[temp] + 1;
                q.push(i);
                flag[i] = 1;
            }
        }
    }
    for (int i = 1;i <= n;i++)
    {
        if (dis[i] == INF)
        cout<<-1<<" ";
        else
        cout<<dis[i]<<" ";
    }
    cout<<endl;
}
