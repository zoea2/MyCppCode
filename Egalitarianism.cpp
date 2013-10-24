#include <iostream>
#include <cstdio>
#include <set>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
char fs[51][51];
int n,d;
int level[51];
bool visit[51];
int pre[51];

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int i = 1;i <= n;i++){
			if(fs[cur][i] == '1' && !visit[i]){
				visit[i] = true;
				level[i] = level[cur] + 1;
				q.push(i);
			}
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>d;
		memset(level,0,sizeof(level));
		memset(visit,0,sizeof(visit));
		//getchar();
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				cin>>fs[i][j];
			}
			//getchar();
		}
		int max = 0;
		bool isTrue = true;
		for(int i = 1;i <= n;i++){
			memset(level,0,sizeof(level));
			memset(visit,0,sizeof(visit));
			visit[i] = true;
			bfs(i);
			for(int j = 1;j <= n;j++){
				if(max < level[j])
					max = level[j];
				
			}
			for(int j = 1;j <= n;j++){
				if(level[j] == 0 && j != i){
					isTrue = false;
					//printf("i%d j%d\n",i,j);
					break;
					}
			}

		}
			if(max == 0 ||!isTrue)
				printf("-1\n");
			else 
				printf("%d\n",max * d);
		}
		//system("pause");
	}
