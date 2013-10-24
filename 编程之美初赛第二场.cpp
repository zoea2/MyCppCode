#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
double graph[50001][2];
double calc(int n,double index)
{
    double dis = 0;
    for(int i = 1;i <= n;i++)
    {
        if(dis < sqrt((graph[i][0] - index) * (graph[i][0] - index) + (graph[i][1]) * (graph[i][1])))
            dis = sqrt((graph[i][0] - index) * (graph[i][0] - index)+ (graph[i][1]) * (graph[i][1]));
    }
    return dis;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    double index;
    for(int c = 1;c <= t;c++)
    {
        scanf("%d",&n);
        double min = 10001,max = -10001;
        memset(graph,0,sizeof(graph));
        for(int i = 1;i <= n;i++)
        {
            scanf("%lf%lf",&graph[i][0],&graph[i][1]);
            if(min > graph[i][0])
                min = graph[i][0];
            if(max < graph[i][0])
                max = graph[i][0];
        }
        double mid;
        double rmid;
        while(max - min > 0.0000001)
        {
            mid = (min + max) / 2;
            rmid = (mid + max) / 2;
            if(calc(n,mid) < calc(n,rmid))
                max = rmid;
            else
                min = mid;
        }
        mid = (min + max) / 2;
        printf("Case #%d: %lf\n",c,mid);
    }
}
