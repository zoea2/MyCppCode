#include <cstdio>
#include <vector>

using namespace std;

const int N = 100 + 10;

vector<int> chl[N];
int deg[N];
int queue[N], tail;

int main()
{
	int n, x, i, j;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		while (scanf("%d", &x), x > 0)
		{
			chl[i].push_back(x);
			deg[x] ++;
		}
	}
	tail = 0;
	for (i=1; i<=n; i++) if (deg[i] == 0) queue[tail++] = i;
	for (i=0; i<tail; i++)
	{
		x = queue[i];
		for (j=0; j<chl[x].size(); j++)
		{
			deg[chl[x][j]] --;
			if (deg[chl[x][j]] == 0) queue[tail++] = chl[x][j];
		}
	}
	for (i=0; i<tail-1; i++) printf("%d ", queue[i]);
	printf("%d\n", queue[tail-1]);
	return 0;
}
