#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;
struct node
{
	int status[9];
	int step;	
};

int res[9];
int init[9] = {1,2,3,4,5,6,7,8,0};
int dirs[4] = {-1,1,-3,3};

bool isValid(int x,int y){
	return (x+y>=0&&x+y<9);
}

int bfs(){
	queue<node> q;
	node start;
	for(int i = 0;i < 9;i++)
		start.status[i] = init[i];
	start.step = 0;
	q.push(start);
	while(!q.empty()){
		node cur = q.front();
		q.pop();
		if(memcmp(cur.status,res,sizeof(res)) == 0)
			return cur.step;
		for(int i = 0;i < 9;i++){
			if(cur.status[i] == 0){
				for(int j = 0;j < 4;j++){
					if(isValid(i,dirs[j])){
						node temp;
						for(int k = 0;k < 9;k++)
							temp.status[k] = cur.status[k];
						temp.step = cur.step+1;
						temp.status[i] = temp.status[i+dirs[j]];
						temp.status[i+dirs[j]] = 0;
						q.push(temp);
					}
				}
				break;
			}
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		for(int i = 0;i < 9;i++)
			scanf("%d",&res[i]);
		int ans = bfs();
		printf("%d\n",ans);
	}
}
