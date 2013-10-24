#include <cstring>
#include <cstdio>

int main()
{
    int t,w;
    scanf("%d",&t);
    for(int c = 1;c <= t;c++)
    {
        scanf("%d",&w);
        int dp[w+1];
        memset(dp,0,sizeof(dp));
        dp[1] = 1;
        dp[2] = 5;
        for(int i = 3;i <= w;i++)
        {
            dp[i] = dp[i-1] + dp[i-2] * 4;
            for(int j = 3;j < i;j++)
            {
                if(j % 2 == 1)
                    dp[i] += dp[i - j] * 2;
                else
                    dp[i] += dp[i - j] * 3;
            }
            if(i % 2 == 0)
            dp[i] += 3;
            else
            dp[i] += 2;
        }
        printf("%d %d\n",c,dp[w]);
    }
}
