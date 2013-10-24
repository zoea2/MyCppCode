#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
int n,st,des;
int dst[151];
bool visit[151];
int step[151];
void bfs(){
	queue<int> q;
	memset(visit,0,sizeof(visit));
	visit[st] = true;
	step[st] = 0;
	q.push(st);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		if(cur == des)
			return;
		for(int i = 1;i <= dst[cur];i++){
			int temp = (cur + i) % n;
			if(temp < 0)
				temp += n;
			if(!visit[temp]){
				visit[temp] = true;
				step[temp] = step[cur] + 1;
				q.push(temp);
				//printf("%d %d\n",cur,temp);
			}			
			temp = (cur - i) % n;
			if(temp < 0)
				temp += n;
			if(!visit[temp]){
				visit[temp] = true;
				step[temp] = step[cur] + 1;
				q.push(temp);
			//	printf("%d %d\n",cur,temp);
			}
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 0;i < n;i++){
			scanf("%d",&dst[i]);
		}
		scanf("%d%d",&st,&des);
		bfs();
		printf("%d\n",step[des]);
	}
}
