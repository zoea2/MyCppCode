#include <cstdio>
#include <cstring>

int dp[1002];
int seq[1002];

int max(int l)
{
    int m = 0;
    for(int j = 1;j <= l;j++)
    {
        if(dp[j] % 2 == 0)
        {
            if(seq[l+1] > seq[j] && m < dp[j])
                m = dp[j];
        }
        else
            if(seq[l+1] < seq[j] && m < dp[j])
                m = dp[j];
    }
    return m;
}
int main()
{
    int n;
    while(scanf("%d",&n) && n != 0)
    {

        memset(dp,0,sizeof(dp));
        memset(seq,0,sizeof(seq));
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&seq[i]);
            //printf("%d\n",sec[i]);
        }
        dp[1] = 1;
        for(int i = 2;i <= n;i++)
        {
            dp[i] = max(i-1) + 1;
        }
        //for(int i = 1;i <= n;i++)
            //printf("%d %d\n",dp[i][0],dp[i][1]);
        //printf("%d\n",n);

        printf("%d\n",dp[n]);
    }
}
