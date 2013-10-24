#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
struct node
{
    int x,y;
    int sum;
    bool visit;
    node(int a,int b,int s)
    {
        x = a;
        y = b;
        sum = s;
        visit = false;
    }

};

char graph[101][102];
char a[20];
vector<node> arc;
vector<node> dow;
int main()
{
    int n;
    scanf("%d",&n);
    while(n != 0)
    {

        memset(graph,0,sizeof(graph));
        arc.clear();
        dow.clear();
        for (int i = 1;i <=n;i++)
        {
            getchar();
            for (int j = 1;j <= n;j++)
                scanf("%c",&graph[i][j]);

        }
        int across = 0,down = 0;
        int count = 0;
        for (int i = 1;i <=n;i++)
        {
            for (int j = 1;j <= n;j++)
            {
                while (graph[i][j] != '#')
                {
                    count++;
                    if (j+1 <= n)
                    j++;
                    else    break;
                }
                if (count > 1)
                    across++;
                count = 0;
            }
        }

        for (int i = 1;i <=n;i++)
        {
            for (int j = 1;j <= n;j++)
            {
                while (graph[j][i] != '#')
                {
                    count++;
                    if (j+1 <= n)
                    j++;
                    else    break;
                }
                if (count > 1)
                    down++;
                count = 0;
            }
        }
        getchar();
        scanf("%s",&a);

        int x,y,sum;
        for (int i = 0;i < across;i++)
        {
            scanf("%d%d%d",&y,&x,&sum);
            arc.push_back(node(x,y,sum));
        }
        getchar();
        scanf("%s",&a);
        for (int i = 0;i < down;i++)
        {
            scanf("%d%d%d",&y,&x,&sum);
            dow.push_back(node(x,y,sum));
        }
        count = 0;
        int countp = 0;
        while (count < across + down)
        {
            for (int i = 0;i < across;i++)
            {
                if (arc[i].visit == false)
                {
                    sum = 0;
                    countp = 0;
                    for (int j = arc[i].y;j <= n;j++)
                    {
                        if (graph[arc[i].x][j] == '.')
                        {
                            x = arc[i].x;
                            y = j;
                            countp++;
                            if (countp >1)
                            break;
                        }
                        else if (graph[arc[i].x][j] != '#')
                        sum += graph[arc[i].x][j] - '0';
                        else
                        break;
                    }
                    if (countp == 1)
                    {
                        graph[x][y] = arc[i].sum - sum + '0';
                        count++;
                        arc[i].visit = true;

                    }
                    else if (countp== 0)
                    {
                        arc[i].visit = true;
                        count++;
                    }
                }
            }

            for (int i = 0;i < down;i++)
            {
                if (dow[i].visit == false)
                {
                    sum = 0;
                    countp = 0;
                    for (int j = dow[i].x;j <= n;j++)
                    {
                        if (graph[j][dow[i].y] == '.')
                        {
                            x = j;
                            y = dow[i].y;
                            countp++;
                            if (countp >1)
                            break;
                        }
                        else if (graph[j][dow[i].y] != '#')
                        sum += graph[j][dow[i].y] - '0';
                        else
                        break;
                    }
                    if (countp == 1)
                    {
                        graph[x][y] = dow[i].sum - sum + '0';
                        count++;
                        dow[i].visit = true;
                    }
                    else if (countp== 0)
                    {
                        dow[i].visit = true;
                        count++;
                    }
                }
            }
        }
        for (int i = 1;i <=n;i++)
        {
            for (int j = 1;j <= n;j++)
                printf("%c",graph[i][j]);
            printf("\n");
        }
        printf("\n");
        scanf("%d",&n);

    }

}
