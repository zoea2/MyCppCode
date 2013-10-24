#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,m,v,p,q;
int value[61][3];
int ipt[61][3];
int num[61];
int dp[61][32005];
int index0[61];
int ct;
void init()
{
    scanf("%d",&m);
    memset(value,0,sizeof(value));
    memset(ipt,0,sizeof(ipt));
    memset(num,0,sizeof(num));
    memset(dp,0,sizeof(dp));
    memset(index0,0,sizeof(index0));
    ct = 0;
    for(int i = 1;i <= m;i++)
    {
        scanf("%d%d%d",&v,&p,&q);
        if(q == 0)
        {
            value[++ct][0] = v;
            ipt[ct][0] = p;
            index0[i] = ct;
        }
        else
        {
            q = index0[q];
            value[q][++num[q]] = v;
            ipt[q][num[q]] = p;
        }
    }
}
int main()
{
    while(scanf("%d",&n) != EOF)
    {
        init();
        for(int i = 1;i <= ct;i++)
        {
            for(int j = value[i][0];j <= n;j++)
            {
                if(j - value[i][0] >= 0)
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-value[i][0]] + value[i][0] * ipt[i][0]);
                if(j - value[i][0] - value[i][1] >= 0)
                    dp[i][j] = max(dp[i][j],dp[i-1][j-value[i][0]-value[i][1]] + value[i][0] * ipt[i][0] + value[i][1] * ipt[i][1]);
                if(j - value[i][0] - value[i][2] >= 0)
                    dp[i][j] = max(dp[i][j],dp[i-1][j-value[i][0]-value[i][2]] + value[i][0] * ipt[i][0] + value[i][2] * ipt[i][2]);
                if(j - value[i][0] - value[i][1] - value[i][2] >= 0)
                    dp[i][j] = max(dp[i][j],dp[i-1][j-value[i][0]-value[i][1]-value[i][2]] + value[i][0] * ipt[i][0] + value[i][1] * ipt[i][1]+value[i][2] * ipt[i][2]);
            }
        }
        printf("%d\n",dp[ct][n]);
    }
}
