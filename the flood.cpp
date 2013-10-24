#include <cstdio>
#include <cstring>
using namespace std;
int graph[101][101];
int cover[101][101];
bool split = 0;
int dir[8] = {-1,0,1,0,0,-1,0,1};
void flood(int n,int m,int x,int y,int att)
{
    for (int i = 0;i < 8;i+= 2)
    {
        if (x + dir[i] >= 0 && x + dir[i]<n && y + dir[i+1] >= 0 && y + dir[i+1] < m)
        {
            if(!cover[x+dir[i]][y+dir[i+1]] && graph[x+dir[i]][y+dir[i+1]] <= att)
            {
                cover[x+dir[i]][y+dir[i+1]] = 1;
                flood(n,m,x+dir[i],y+dir[i+1],att);
            }
        }
    }
}
void island(int n,int m,int x,int y,int att)
{
    for (int i = 0;i < 8;i+= 2)
    {
        if (x + dir[i] >= 0 && x + dir[i]<n && y + dir[i+1] >= 0 && y + dir[i+1] < m)
        {
            if(!cover[x+dir[i]][y+dir[i+1]])
            {
                cover[x+dir[i]][y+dir[i+1]] = 1;
                island(n,m,x+dir[i],y+dir[i+1],att);
            }
        }
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int testc = 0;
    while(n != 0 ||m != 0)
    {
        testc++;
        memset(graph,0,sizeof(graph));
        split = 0;
        int result = 0;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                scanf("%d",&graph[i][j]);
        for(int i = 1;i <= 1000;i++)
        {
            if(!split)
            {
                memset(cover,0,sizeof(cover));
                for (int j = 0;j < n;j++)
                {
                    if(j == 0 || j == n-1)
                    {
                        for (int k = 0;k < m;k++)
                        {
                            if (!cover[j][k] && graph[j][k] <= i)
                            {
                                cover[j][k] = 1;
                                flood(n,m,j,k,i);
                            }
                        }
                    }
                    else
                    {
                        if (!cover[j][0] && graph[j][0] <= i)
                        {
                                cover[j][0] = 1;
                                flood(n,m,j,0,i);
                        }
                        if (!cover[j][m-1] && graph[j][m-1] <= i)
                        {
                                cover[j][m-1] = 1;
                                flood(n,m,j,m-1,i);
                        }
                    }
                }
                int count = 0;
                for (int j = 0;j < n;j++)
                {
                    if(!split){
                        for (int k = 0;k < m;k++)
                        {
                            if(!cover[j][k])
                            {
                                cover[j][k] = 1;
                                count++;
                                if(count > 1)
                                {
                                    split = true;
                                    result = i;
                                    break;
                                }
                                island(n,m,j,k,i);

                            }
                        }
                    }
                    else
                    break;
                }
            }
            else
            break;

        }
        if(split)
                printf("Case %d: Island splits when ocean rises %d feet.\n",testc,result);
            else
                printf("Case %d: Island never splits.\n",testc);
        scanf("%d%d",&n,&m);
    }
}
