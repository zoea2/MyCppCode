#include <cstdio>
#include <cstring>
#define INT 1000000007
long long dp[2002];

int main()
{
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    dp[2] = 1;
    for(int i = 4;i <= 2000;i+=2)
    {
        for(int j = 2;j <= i;j+=2)
        dp[i] += (dp[j-2] * dp[i - j]) % INT;
        dp[i] %= INT;
    }
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
}
