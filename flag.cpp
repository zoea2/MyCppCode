#include <cstring>
#include <cstdio>
using namespace std;
int dp[41];
int main()
{
	dp[1] = 2;
	dp[2] = 2;
	for(int i = 3;i <= 40;i++)
		dp[i] = dp[i-1] + dp[i-2];
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		printf("%d\n",dp[n]);
	}
}
