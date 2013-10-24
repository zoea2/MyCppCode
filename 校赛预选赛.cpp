#include<iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int graph[51][51];
//int visit[51];
long long count0[51];
int sub[51][51];
long long sum = 0;
void solve(int n,int pos)
{
    int count = 0;
    long long sum0 = 0;
    for(int i = 0;i < n;i++)
    {
        if(graph[pos][i] == 1)
        {
            sub[pos][count++] = i;
        }
    }
    if (count == 0)
    {
        count0[pos] = 1;
        return;
    }
    for(int i = 0;i < count;i++)
    {
        if(count0[sub[pos][i]] == 0)
            solve(n,sub[pos][i]);
        sum0 += count0[sub[pos][i]];
    }
    count0[pos] = sum0;
}
int main()
{
    int t;
    int n;
    scanf("%d",&t);
    while(t--)
    {
        sum = 0;
        memset(graph,0,sizeof(graph));
        memset(sub,0,sizeof(sub));
        memset(count0,0,sizeof(count0));
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                scanf("%d",&graph[i][j]);
        for(int i = 0;i < n;i++)
        {
            solve(n,i);
        }
        for(int i = 0;i < n;i++)
        {
            sum += count0[i];
        }
        printf("%lld\n",sum);
    }
}
