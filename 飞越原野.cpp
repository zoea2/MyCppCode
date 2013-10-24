#include <cstdio>
#include <cstring>
#include <queue>


using namespace std;

struct pos
{
    int x,y,time,fly;
    pos(int a,int b,int c,int d)
    {
        x = a;
        y = b;
        time = c;
        fly = d;
    }
};

char graph[101][101];
bool vis[101][101][101];
int dir[8] = {-1,0,1,0,0,-1,0,1};

int main()
{
    int m,n,d;
    scanf("%d%d%d",&m,&n,&d);
    memset(graph,0,sizeof(graph));
    memset(vis,false,sizeof(vis));
    getchar();
    for(int i = 1;i <= m;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            scanf("%c",&graph[i][j]);
            //getchar();
            //printf("%c",graph[i][j]);
        }
        getchar();
        //printf("\n");
    }
    pos cur = pos(1,1,0,d);
    queue<pos> q;
    q.push(cur);
    vis[1][1][d] = true;
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        //printf("%d %d\n",cur.x,cur.y);
        if(cur.x == m && cur.y == n)
        {
            /*for(int i = 1;i <= m;i++)
            {
                for(int j = 1;j <= n;j++)
                {
                    printf("%c %d ",graph[i][j],step[i][j]);
                }
                printf("\n");
            }*/

            printf("%d\n",cur.time);
            return 0;
        }
        for(int i = 0;i < 8 ;i+= 2)
        {
            if(cur.x + dir[i] > 0 && cur.x + dir[i] <= m && cur.y + dir[i+1] > 0 && cur.y + dir[i+1] <= n)
            {
                if(graph[cur.x + dir[i]][cur.y + dir[i+1]] == 'P' && vis[cur.x+dir[i]][cur.y+dir[i+1]][cur.fly] == false)
                {
                    q.push(pos(cur.x + dir[i],cur.y + dir[i+1],cur.time+1,cur.fly));
                    //printf("size &d\n",q.size());
                    vis[cur.x+dir[i]][cur.y+dir[i+1]][cur.fly] = true;
                }
            }
            else
                continue;
            for(int j = 2;j <= cur.fly;j++)
            {
                int tempx = cur.x + j*dir[i];
                int tempy = cur.y + j*dir[i+1];
                if(tempx > 0 && tempx <= m && tempy > 0 && tempy <= n)
                {
                    if(graph[tempx][tempy] == 'P' && !vis[tempx][tempy][cur.fly-j])
                    {
                        q.push(pos(tempx,tempy,cur.time+1,cur.fly-j));
                        vis[tempx][tempy][cur.fly-j] = true;
                    }
                }
            }

        }
    }
    printf("impossible\n");
}
