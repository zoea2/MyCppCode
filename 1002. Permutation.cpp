#include <cstring>
#include <cstdio>
int dp[101][101];
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k) != EOF)
    {
        memset(dp,0,sizeof(dp));
        for(int i = 1;i <= n;i++)
        {
            dp[i][0] = 1;
            dp[i][i-1] = 1;
        }
        for(int i = 3;i <= n;i++)
        {
            for(int j = 1;j <= i - 1;j++)
            {
                dp[i][j] = ((dp[i-1][j]*(j+1) % 2007 + dp[i-1][j-1]*(i-j) % 2007) + 2007) % 2007;
            }
        }
    //printf("%d\n",dp[3][1]);
        printf("%d\n",dp[n][k]);
    }
}
