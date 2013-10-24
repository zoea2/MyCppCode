#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i,n) for(int i = 0;i < n;i++)
using namespace std;
struct cow
{
    int st,end,index;
};
cow cows[100001];
int res[100001];
bool cmp (cow a,cow b)
{
    if(a.end != b.end)
        return a.end > b.end;
    else
        return a.st < b.st;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF && n)
    {
        memset(cows,0,sizeof(cows));
        memset(res,0,sizeof(res));
        int start,end;
        rep(i,n)
        {
            scanf("%d%d",&start,&end);
            cows[i].st = start;
            cows[i].end = end;
            cows[i].index = i;
        }
        sort(cows,cows+n,cmp);
        res[cows[0].index] = 0;
        for(int i = 1;i < n;i++)
        {
            if(cows[i-1].end > cows[i].end)
            {
                if(cows[i-1].st <= cows[i].st)
                    res[cows[i].index] = res[cows[i-1].index] + 1;
                else
                    res[cows[i].index] = res[cows[i-1].index];
            }
            else
            {
                if(cows[i-1].st < cows[i].st)
                    res[cows[i].index] = res[cows[i-1].index] + 1;
                else
                    res[cows[i].index] = res[cows[i-1].index];
            }
        }
        rep(i,n)
            printf("%d\n",res[i]);
    }
}
