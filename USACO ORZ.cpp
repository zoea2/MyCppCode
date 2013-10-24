#include <cstring>
#include <cstdio>
#include<algorithm>
#include<set>
using namespace std;
int edge[16];
int tri[3];
int n;
set<pair<int,int> >s;
void dfs(int num){
	if (num == n){
		if(tri[0] <= tri[1] && tri[1] <= tri[2] && tri[0] + tri[1] > tri[2]){
			s.insert(make_pair(tri[0],tri[1]));
		}
		return;
	}
	for(int i = 0;i < 3;i++){
		tri[i] += edge[num];
		dfs(num+1);
		tri[i] -= edge[num];
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){		
		s.clear();
		memset(tri,0,sizeof(tri));
		scanf("%d",&n);
		for(int i = 0;i < n;i++)
			scanf("%d",&edge[i]);
		dfs(0);
		printf("%d\n",s.size());
	}
	
	
}
