#include <cstdio>
#include <cstring>

long long dp[30001];
int coin[5] = {1,5,10,25,50};
int main()
{
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i = 0;i < 5;i++)
    {
        for(int j = coin[i];j <= 30000;j++)
        {
            dp[j] += dp[j-coin[i]];
        }
    }
	int n;
	while(scanf("%d",&n) != EOF)
	{
	    if (dp[n] > 1)
	    printf("There are %lld ways to produce %d cents change.\n",dp[n],n);
	    else
	    printf("There is only 1 way to produce %d cents change.\n",n);
	}
}
