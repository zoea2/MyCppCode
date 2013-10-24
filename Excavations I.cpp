#include <cstring>
#include <cstdio>
using namespace std;
int n,m,k;
int bd[51];
int eType[51];
long long dp[51];
int visit[51];
long long com(int a,int b){
	long long ans = 1;
	for(int i = 0 ;i < b;i++){
		ans *= a--;
	}
	for(int i = b;i > 0;i--){
		ans /= i;
	}
	return ans;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(bd,0,sizeof(bd));
		memset(dp,0,sizeof(dp));
		memset(eType,0,sizeof(eType));
		memset(visit,0,sizeof(visit));
		scanf("%d%d%d",&n,&m,&k);
		for(int i = 1;i <= n;i++){
			scanf("%d",&bd[i]);
		}
		for(int i = 1;i <= m;i++){
			int temp;
			scanf("%d",&temp);
			eType[temp] = 1;
		}
		for(int i = 1;i <= n;i++){
			if(eType[bd[i]] == 1){
				if(visit[bd[i]] == 0){
					visit[bd[i]] = 1;
					dp[i] = 1;
					k--;
					m--;
				}
				else if(visit[bd[i]]>0){
					if(k > m){
						visit[bd[i]]++;
						dp[i] = 1;
						k--;
					}
					else{
						int temp = 0;
						for(int j = 1;j <= 50;j++){
							if(eType[j] == 1){
								if(j == bd[i]){
									temp += visit[j];
									//visit[j]--;
								}
								else
									temp += visit[j] - 1;
							}
						}
						int tempn = 0;
						for(int j = 1;j<= n;j++){
							if(bd[j] == bd[i]){
								tempn++;
							}
						}
						//printf("%d",com(tempn,temp));
						if (tempn > temp)
							dp[i] = dp[i-1] * com(tempn,temp);
						else
							dp[i] = dp[i-1] * com(temp-visit[bd[i]],tempn-visit[bd[i]]);
						eType[bd[i]] = 0;
					}
				}
			}
			else
			dp[i] = dp[i-1];
		//	printf("%d ",dp[i]);
		}
		//printf("\n");
		printf("%lld\n",dp[n]);
	}
}
