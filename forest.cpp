#include <cstdio>
#include <cstring>
using namespace std;
int graph[101][101];
int visit[101];
int indeg[101];
int level[101];
int width[101];
bool flag;
void dfs(int n,int pos)
{
    for(int i = 1;i <= n;i++)
    {
        if(!flag)
        return;
        if(graph[pos][i] == 1 && visit[i])
        {
            flag = false;
            return;
        }
        else if(graph[pos][i] == 1 && !visit[i])
        {
            visit[i] = 1;
            level[i] = level[pos] + 1;
            width[level[i]]++;
            dfs(n,i);
        }
    }
}
int main()
{
    int n,m,x,y;
    scanf("%d%d",&n,&m);
    while(n != 0)
    {
        flag = true;
        memset(graph,0,sizeof(graph));
        memset(visit,0,sizeof(visit));
        memset(indeg,0,sizeof(indeg));
        memset(level,0,sizeof(level));
        memset(width,0,sizeof(width));
        //memset(level,0,sizeof(level));
        for (int i = 0;i < m;i++)
        {
            scanf("%d%d",&x,&y);
            graph[x][y] = 1;
            indeg[y]++;
        }
        for (int i = 1;i <= n;i++)
        {
            if(flag == true)
            {
                if(indeg[i] == 0 && visit[i] == 0)
                {
                    width[0]++;
                    visit[i] = 1;
                    dfs(n,i);
                }
            }
            else
                break;
        }
        for(int i = 1;i <= n;i++)
        {
            if(visit[i] == 0)
                flag = false;
        }

        if(flag)
        {
            int max = 0;
            for(int i = 1;i <= n;i++)
                if(max < level[i])
                    max = level[i];
            printf("%d ",max);
            max = 0;
            for(int i = 0;i <= n;i++)
                if(max < width[i])
                    max = width[i];
            printf("%d\n",max);
        }
        else
            printf("INVALID\n");
        scanf("%d%d",&n,&m);
    }
}
