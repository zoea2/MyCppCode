#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <queue>
using namespace std;

int INF = 0x7fffffff;
int graph[1001][1001];
bool visit[1001];
int lv[1001];
queue<int> q;
int min0 = 0;

void bfs(int i,int n,int &cnt)
{

    q.push(i);
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        visit[cur] = 1;
        cnt++;
        for(int j = 0;j < n;j++)
        {
            if(graph[cur][j] == 1 && !visit[j])
            {
                q.push(j);
                lv[j] = lv[cur] + 1;
                if(min0 < lv[j])
                    min0 = lv[j];
            }

        }
    }
}
int main()
{
    int n,m;
    while(true)
    {
        scanf("%d",&n);
        map<string,int> mp;
        if(n == 0)
            break;
        string s,s0;
        char temp1[11],temp2[11];
        for(int i = 0;i < n;i++)
        {
            scanf("%s",&temp1);
            s = string(temp1);
            mp[s] = i;
        }
        scanf("%d",&m);
        memset(graph,0,sizeof(graph));

        for(int i = 0;i < m;i++)
        {
            scanf("%s%s",&temp1,&temp2);
            s = string(temp1);
            s0 = string(temp2);
            graph[mp[s]][mp[s0]] = 1;
            graph[mp[s0]][mp[s]] = 1;
        }
        min0 = 0;
        for(int i = 0;i < n;i++)
        {
            memset(lv,0,sizeof(lv));
            memset(visit,0,sizeof(visit));
            int count = 0;
            bfs(i,n,count);
            if(count < n-1)
            {
                min0 = -1;
                break;
            }
        }
        printf("%d\n",min0);
    }
}
