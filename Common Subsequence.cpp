#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[21][21];
int main()
{
	int t;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		string s1,s2;
		cin>>s1>>s2;
		int len1 = s1.size(),len2 = s2.size();
		for(int i = 1;i <= len1;i++){
			for(int j = 1;j <= len2;j++){
				if(s1[i-1] == s2[j-1])
					dp[i][j] = dp[i-1][j-1] + 1;
				else
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
		cout<<dp[len1][len2]<<endl;
	}
}
