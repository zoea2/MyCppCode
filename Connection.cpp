#include <cstdio>
#include <cstring>
using namespace std;
int graph[101][101];
int visit[101];
void dfs(int n,int pos)
{
    for (int i = 0;i < n;i++)
    {
        if (graph[pos][i] && !visit[i])
        {
            visit[i] = 1;
            dfs(n,i);
        }
    }
}
int main()
{
    int n,m,x,y;
    scanf("%d%d",&n,&m);
    while(n != 0 || m != 0)
    {
        memset(graph,0,sizeof(graph));
        memset(visit,0,sizeof(visit));
        for (int i = 0;i < m;i++)
        {
            scanf("%d%d",&x,&y);
            graph[x][y] = 1;
            graph[y][x] = 1;
        }
        int count = 0;
        for (int i = 0;i < n;i++)
        {
            if (!visit[i])
            {
                visit[i] = 1;
                dfs(n,i);
                count++;
            }
        }
        printf("%d\n",count-1);
        scanf("%d%d",&n,&m);
    }
}
