#include <iostream>
using namespace std;
struct EdgeNode
{
    int to;
    int next;
};
bool visited[100001] = {0};
void DFS(int now,int &count,bool visited[],EdgeNode edges[],int ans[],int head[])
{
    for (int k = head[now];k!= 0;k = edges[k].next)
    {
        if (!visited[k])
        {
            visited[k] = true;
            DFS(edges[k].to,count,visited,edges,ans,head);
        }
    }
    ans[count++] = now;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int head[10001] = {0};
    EdgeNode Edges[100001];
    int from,des;
    for (int i = 1;i <=m;i++)
    {
        cin>>from>>des;
        Edges[i].to = des;
        Edges[i].next = head[from];
        head[from] = i;
        Edges[i+m].to = from;
        Edges[i+m].next = head[des];
        head[des] = i + m;
    }
    for (int i = 1;i <= n;i++)
    cout<<head[i]<<" ";
    cout<<endl;
    for (int i = 1;i <= 2*m;i++)
    cout <<Edges[i].to<<" "<<Edges[i].next<<endl;
    int count = 0;
    int ans[100002];
    DFS(1,count,visited,Edges,ans,head);
    for (int i = 0;i < 2*m+1;i++)
    cout<<ans[i]<<endl;
}
