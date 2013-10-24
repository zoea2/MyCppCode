#include <cstdio>
#include <cstring>

int ball[201];
int dp[201][201];

int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&ball[i]);
            ball[i+n] = ball[i];
        }
        memset(dp,0,sizeof(dp));
        int q;
        int ans = 0;
        for(int i = 2;i <= n;i++)
        {
            for(int j = 1 ;j <= n+n-i ;j++)
            {
                int h = j+i-1;
                for(int k = j;k <= h-1;k++)
                {
                    q = dp[j][k] + dp[k+1][h] + ball[j] * ball[k+1] * ball[h+1];
                    if(q > dp[j][h])
                        dp[j][h] = q;
                }

            }
        }
        for(int i = 1;i <= n;i++)
        {
            if(ans < dp[i][i+n-1])
                ans = dp[i][i+n-1];
        }
        printf("%d\n",ans);
    }
}
