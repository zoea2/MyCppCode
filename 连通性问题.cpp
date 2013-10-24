#include <cstdio>
#include <cstring>
using namespace std;
int father[100001];
int find(int a)
{
    if (father[a] != a)
    father[a] = find(father[a]);
    return father[a];
}
int main()
{
    for (int i = 0;i <= 100000;i++)
    father[i] = i;
    int x,y;
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        int a = find(x);
        int b = find(y);
        if (a != b)
        {
            printf("%d %d\n",x,y);
            father[a] = b;
        }
    }
}
