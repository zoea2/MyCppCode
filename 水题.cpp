#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include<algorithm>
#include <queue>
using namespace std;
bool graph[102][102];
bool visit[102];
int level[102];
int n = 100;
void bfs(){
	queue<int> q;
	visit[0] = true;
	q.push(0);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int i = 1;i <= n;i++){
			if(graph[cur][i] == true && visit[i] == false){
				visit[i] = true;
				q.push(i);
				level[i] = level[cur] + 1;
			}
		}
	}
}
int main()
{
	int t;
	cin>>t;
	int m;
	while(t--){
		cin>>m;
		int x,y;
		memset(graph,0,sizeof(graph));
		memset(level,0,sizeof(level));
		memset(visit,0,sizeof(visit));
		for(int i = 0;i < m;i++){
			cin>>x>>y;
			graph[x][y] = true;
			graph[y][x] = true;
		}
		bfs();
		for(int i = 1;i <= n;i++){
			if(level[i] != 0){
				printf("%d:%d\n",i,level[i]);
			}
			
		}
		printf("---\n");
	}
}
