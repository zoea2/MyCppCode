#include <cstdio>
#include<cstring>
using namespace std;
int graph[101][101];
int temp[101][101];
int res[101][101];
int main()
{
	memset(graph,0,sizeof(graph));
	memset(res,0,sizeof(res));
	memset(temp,0,sizeof(temp));
	int n,m,l,x,y;
	scanf("%d%d%d",&n,&m,&l);
	for (int i = 0;i < m;i++)
	{
		scanf("%d%d",&x,&y);
		graph[x][y] = 1;
		temp[x][y] = 1;
	}
	for (int i = 0;i < l-1;i++)
	{
		memset(res,0,sizeof(res));
		for(int j = 1;j <= n;j++)
		{
			for (int k = 1;k <= n;k++)
				for (int z = 1;z <= n;z++)
					res[k][j] += graph[z][j] * temp[k][z];
		}
		for (int j = 1;j <= n;j++)
			for (int k = 1;k <= n;k++)
				temp[j][k] = res[j][k];
	}

	//for (int j = 1;j <= n;j++)
     //   {                for (int k = 1;k <= n;k++)
     //                           printf("%d ",temp[j][k]);
	//		printf("\n");
	//}
	scanf("%d",&n);
	for (int i = 0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",temp[x][y]);
	}
}
