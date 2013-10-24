#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
struct node
{
    int des;
    int col;
    node(int a = 0,int b = 0)
    {
        des = a;
        col = b;
		}
};
vector<node> vec[100002];
int n,m;
int level[100002];
int visit[100002];
int min0[100002];
int sameLevel[100002];
void bfs()
{
    memset(visit,0,sizeof(visit));
    queue<int> q;
    q.push(n);
    visit[n] = true;
    level[n] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0;i < vec[cur].size();i++)
        {
            if(!visit[vec[cur][i].des])
            {
                q.push(vec[cur][i].des);
                level[vec[cur][i].des] = level[cur] + 1;
                visit[vec[cur][i].des] = true;
            }
        }
    }
}
void bfs2()
{
    memset(visit,0,sizeof(visit));
    queue<int> q;
    int max = level[1];
    q.push(1);
    visit[1] = true;
    int count = 0;
    while(!q.empty())
    {
        int cur = q.front();
        
        sameLevel[count++] = cur;
        q.pop();
        //visit[cur] = true;
        while(!q.empty() && level[q.front()] == level[sameLevel[0]]){
			sameLevel[count++] = q.front();
			//visit[q.front()] = true;
			q.pop();
		}
        int min = 1000000000;
        for(int i = 0;i < count;i++){
			cur = sameLevel[i];
            for(int j = 0;j < vec[cur].size();j++){
				if(!visit[vec[cur][j].des] && level[vec[cur][j].des] == level[cur] - 1 && min > vec[cur][j].col)
				{
					min = vec[cur][j].col;
				}
			}
        }
        for(int i = 0;i < count;i++)
        {
			cur = sameLevel[i];
            for(int j = 0;j < vec[cur].size();j++){
				if(!visit[vec[cur][j].des] && level[vec[cur][j].des] == level[cur] - 1  && min == vec[cur][j].col)
            	{
                		q.push(vec[cur][j].des);
                		visit[vec[cur][j].des] = true;
            	}
			}			
        }
        min0[max - level[sameLevel[0]]] = min;
        count = 0;
    }
}

int main()
 {
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        memset(vec,0,sizeof(vec));
        int a,b,c;
        for(int i = 0;i < m;i++){
            scanf("%d%d%d",&a,&b,&c);
                          
            vec[a].push_back(node(b,c));
            vec[b].push_back(node(a,c));            
            
        }
        bfs();
        bfs2();    
        printf("%d\n",level[1]);
        for(int i = 0;i < level[1] ;i++)
        {
            if(i != level[1] - 1)
            printf("%d ",min0[i]);
            else
            printf("%d\n",min0[i]);
        }
    }
    return 0;
}          

