#include <cstdio>
#include <iostream>
using namespace std;
int INF = 0x7fffffff;
/*struct closepath
{
    int index;
    int weight;
};*/
int graph[102][102];
int main()
{
    int t,r,cr;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&r,&cr);
        //cout<<r<<cr;
        int g[r*cr+1][4];
        for (int i = 1;i <= r;i++)
        {
            for (int j = 1;j <= cr;j++)
                scanf("%d",&graph[i][j]);
        }
        int visit[10001] = {0};
        for (int i = 1;i <= r;i++)
        {
            for (int j = 1;j <= cr;j++)
            {
                g[(i-1)*cr+j][0] = graph[i-1][j];
                g[(i-1)*cr+j][1] = graph[i+1][j];
                g[(i-1)*cr+j][2] = graph[i][j-1];
                g[(i-1)*cr+j][3] = graph[i][j+1];
            }
        }
        //cout<<"done1"<<endl;
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        //cout<<"done1"<<endl;
        int c[r*cr+1];
        for (int i = 1;i<=r;i++)
        {
            for (int j = 1;j <= cr;j++)
            {
                c[(i-1)*cr+j] = INF;
            }
        }
        if (r == 1 && cr == 1)
        {
            printf("%d\n",graph[1][1]);
            continue;
        }
        if (g[(x1-1) * cr + y1][0] > 0)
                c[(x1-2)*cr+y1] = g[(x1-1) * cr + y1][0];
        if (g[(x1-1) * cr + y1][1] > 0)
                c[(x1)*cr+y1] = g[(x1-1) * cr + y1][1];
        if (g[(x1-1) * cr + y1][2] > 0)
                c[(x1-1)*cr+y1-1] = g[(x1-1) * cr + y1][2];
        if (g[(x1-1) * cr + y1][3] > 0)
                c[(x1-1)*cr+y1+1]= g[(x1-1) * cr + y1][3];
        visit[(x1-1)*cr+y1] = 1;
        //for (int i = 1;i <= cr * r;i++)
        //cout<<i<<" "<<c[i]<<endl;
        //cout<<"done3"<<endl;
        for (int i = 0;i < r * cr;i++)
        {
            int min = INF;
            int index,indey;
            for (int w = 1;w <= r;w++)
            {
                for (int j = 1;j <= cr;j++)
                {
                    if (!visit[(w-1)*cr+j])
                    {
                        if (c[(w-1)*cr+j] < min)
                        {
                            index = w;
                            indey = j;
                            min = c[(w-1)*cr+j];
                        }
                    }
                }
            }
            //cout<<index<<" "<<indey<<endl;
            visit[(index-1)*cr+indey] = 1;
            if (index == x2 && indey == y2)
            {
                printf("%d\n",min+graph[x1][y1]);
                break;
            }
            if (g[(index-1)*cr+indey][0] > 0&& g[(index-1)*cr+indey][0] + min < c[(index-2)*cr+indey] && !visit[(index-2)*cr+indey])
                c[(index-2)*cr+indey] = g[(index-1)*cr+indey][0] + min;
            if (g[(index-1)*cr+indey][1] > 0&& g[(index-1)*cr+indey][1] + min < c[(index)*cr+indey] && !visit[(index)*cr+indey])
                c[(index)*cr+indey] = g[(index-1)*cr+indey][1] + min;
            if (g[(index-1)*cr+indey][2] > 0&& g[(index-1)*cr+indey][2] + min < c[(index-1)*cr+indey-1] && !visit[(index-1)*cr+indey-1])
                c[(index-1)*cr+indey-1] = g[(index-1)*cr+indey][2] + min;
            if (g[(index-1)*cr+indey][3] > 0&& g[(index-1)*cr+indey][3] + min < c[(index-1)*cr+indey+1] && !visit[(index-1)*cr+indey+1])
                c[(index-1)*cr+indey+1] = g[(index-1)*cr+indey][3] + min;
            //for (int q = 1;q <= r * cr;q++)
            //cout<<c[q]<<endl;
            //cout<<i<<endl;

        }
        //cout<<c[(x2-1)*cr+y2]<<endl;
    }
}
