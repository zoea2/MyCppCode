#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
class Trie
{
	public:
		int node[400002][26];
		int val[400002];
		int num;
		Trie(){
			num = 1;
			memset(node[0],0,sizeof(node[0]));
		}
		int idx(char c){
			return c - 'a';
		}
		void insert(char* s,int v){
			int cur = 0;
			int len = strlen(s);
			for(int i = 0;i < len;i++){
				int c = idx(s[i]);
				if(node[cur][c] == 0){
					memset(node[num],0,sizeof(node[num]));
					val[num] = 0;
					node[cur][c] = num++;
				}
				cur = node[cur][c];
			}
			val[cur] = v;
		}
};
int dp[300002];	
Trie t;	
int main()
{
	char s[300002],temp[300002];
	int n;
	int c = 1;
	while(scanf("%s",&s) != EOF){
		memset(t.node,0,sizeof(t.node));
		memset(t.val,0,sizeof(t.val));
		t.num = 1;
		scanf("%d",&n);
		for(int i = 0;i < n;i++){
			scanf("%s",&temp);
			//printf("%s\n",temp);
			t.insert(temp,1);
		}
		int len = strlen(s);
		dp[len] = 1;
		for(int i = len - 1;i >= 0;i--){
			dp[i] = 0;
			int cur = 0;
			for(int j = i;j < len;j++){
				int u = t.idx(s[j]);
				if(t.node[cur][u] != 0){
					cur = t.node[cur][u];					
					if(t.val[cur] != 0){
						//printf("cur %d u %d\n",cur,u);
						dp[i] += dp[j+1];
						dp[i] %= 20071027;
						//printf("%d %d\n",i,j);
					}
				}
				else
					break;
			}
			if(dp[i] < 0)
				dp[i] += 20071027;
			
			//cout<<i<<" "<<dp[i]<<endl;
		}
		printf("Case %d: %d\n",c++,dp[0]);
	}
}
