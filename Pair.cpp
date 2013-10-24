#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>

using namespace std;
#define MAXNUM 10000
//bool visit[MAXNUM+1];
int n;
int count0;
bool isFind;
bool match[MAXNUM+1];
int father[MAXNUM+1];
int deg[MAXNUM+1];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		//memset(visit,0,sizeof(visit));
		memset(match,0,sizeof(match));
		memset(deg,0,sizeof(deg));
		int x,y;
		set<int> vec[MAXNUM+1];
		for(int i = 1;i < n;i++){
			scanf("%d%d",&x,&y);
			vec[x].insert(y);
			vec[y].insert(x);
			deg[x]++;
			deg[y]++;
		}
		if(n % 2 == 1){
			printf("No\n");
			continue;
		}
		queue<int> q;
		for(int i = 1;i <= n;i++){
			if(deg[i] == 1)
				q.push(i);
		}
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			if(!vec[cur].empty()){
				int next = *(vec[cur].begin());
				for(set<int>::iterator it = vec[next].begin();it!=vec[next].end();it++){
					vec[*it].erase(next);
					deg[*it]--;
					if(deg[*it] == 1 && !match[*it])
						q.push(*it);
				}
				match[cur] = true;
				match[next] = true;
			}			
		}
		isFind = false;
		for(int i =1;i <= n;i++)
			if(!match[i])
				isFind = true;
		if(isFind)
			printf("No\n");
		else
			printf("Yes\n");		
	}
}
