#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
int graph[101][101];
int cost[101][101];
int dir[8] = {0,-1,0,1,-1,0,1,0};
class node
{
    public:
    int x;
    int y;
    int weight;
    node()
    {

    }
    node(int x,int y,int w)
    {
        this->x = x;
        this->y = y;
        this->weight = w;
    }
};
class cmp
{
    public:
    bool operator() (node a,node b)    const
    {
        return a.weight > b.weight;
    }
};
void dijkstra(int sx,int sy,int dx,int dy,int n,int m)
{
    priority_queue<node,vector< node >, cmp> q;
    cost[sx][sy] = graph[sx][sy];
    //printf("%d\n",cost[sx][sy]);
    q.push(node(sx,sy,cost[sx][sy]));
    node cur;
    while(!q.empty())
    {
        cur = q.top();
        q.pop();
        if(cur.x == dx && cur.y == dy)
            return;
        for(int i = 0;i < 8;i+= 2)
        {
            if(cur.x+dir[i] > 0 && cur.x+dir[i] <= n && cur.y+dir[i+1]>0 && cur.y+dir[i+1]<= m)
            {
                if(cost[cur.x+dir[i]][cur.y+dir[i+1]] > cost[cur.x][cur.y]+graph[cur.x+dir[i]][cur.y+dir[i+1]])
                {
                    //printf("%d ",cost[cur.x+dir[i]][cur.y+dir[i+1]] );
                    cost[cur.x+dir[i]][cur.y+dir[i+1]] = cost[cur.x][cur.y]+graph[cur.x+dir[i]][cur.y+dir[i+1]];
                    q.push(node(cur.x+dir[i],cur.y+dir[i+1],cost[cur.x+dir[i]][cur.y+dir[i+1]]));
                    //printf("%d \n",cost[cur.x+dir[i]][cur.y+dir[i+1]] );
                }
            }
        }
    }
}
int main()
{
    int t,n,m,sx,sy,dx,dy;
    scanf("%d",&t);
    while(t--)
    {
        memset(graph,0,sizeof(graph));
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                scanf("%d",&graph[i][j]);
                //printf("%d ",graph[i][j]);
                cost[i][j] = 10001;
            }
            //printf("\n");
        }

        scanf("%d%d%d%d",&sx,&sy,&dx,&dy);
        dijkstra(sx,sy,dx,dy,n,m);
        //if(cost[dx][dy] < 9999)
        printf("%d\n",cost[dx][dy]);
        //else
        //printf("9999\n");

    }
}
