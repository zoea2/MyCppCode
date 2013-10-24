#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>

#define INF 10000

using namespace std;
int n,m;
int graph[41][41];
bool visit[41][41];
int dirs[8] = {-1,0,1,0,0,1,0,-1};
int level[41][41];
int mindist,maxdist;

bool isValid0(int i,int j,int x,int y){
	if (i + x > 0 && i + x <= n && j + y > 0 && j + y <= m){
	    //cout<<"isvalid "<<i<<" "<<j<<" "<<i+x<<" "<<j+y<<endl;
	    return true;
	}
	return false;
}
void bfs(int x,int y){
	memset(visit,0,sizeof(visit));
	deque<pair<int,int> > q;
	q.push_back(make_pair(x,y));
	visit[x][y] = true;
	memset(level,0,sizeof(level));
	level[x][y] = graph[x][y];
	while(!q.empty()){
		pair<int,int> cur = q.front();
		q.pop_front();
		for(int i = 0;i < 8;i+=2){
			if(isValid0(cur.first,cur.second,dirs[i],dirs[i+1]) && !visit[cur.first+dirs[i]][cur.second+dirs[i+1]]){
				visit[cur.first+dirs[i]][cur.second+dirs[i+1]] = true;
				level[cur.first+dirs[i]][cur.second+dirs[i+1]] = level[cur.first][cur.second]+graph[cur.first+dirs[i]][cur.second+dirs[i+1]];
				//cout<<cur.first+dirs[i]<<" "<<cur.second+dirs[i+1]<<" "<<level[cur.first+dirs[i]][cur.second+dirs[i+1]];
				if(maxdist < level[cur.first+dirs[i]][cur.second+dirs[i+1]])
					maxdist = level[cur.first+dirs[i]][cur.second+dirs[i+1]];
				if(graph[cur.first+dirs[i]][cur.second+dirs[i+1]] == 1) 
					q.push_back(make_pair(cur.first+dirs[i],cur.second+dirs[i+1]));
				else
					q.push_front(make_pair(cur.first+dirs[i],cur.second+dirs[i+1]));
			}			
			
				 
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= m;j++)
				scanf("%d",&graph[i][j]);
		mindist = INF;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				maxdist = 0;
				bfs(i,j);
				if(mindist > maxdist)
					mindist = maxdist;
			}
		}
		printf("%d\n",mindist);

	}
}
