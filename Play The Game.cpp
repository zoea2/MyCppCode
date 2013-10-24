#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAXN 17
using namespace std;
int weight[MAXN][MAXN],n;
int Lx[MAXN],Ly[MAXN];
int left[MAXN];
bool s[MAXN],t[MAXN];

bool match(int i){
	s[i] = true;
	for(int j = 1;j <= n;j++){
		printf("%d %d\n",i,j);
		if(Lx[i] + Ly[j] == weight[i][j] && !t[j]){
			t[j] = true;
			if(!left[j] || match(left[j])){
				left[j] = i;
				printf("i = %d j = %d\n",i,j);
				return true;
			} 
		}
	}
	return false;
}

void update(){
	int a = 1<<30;
	for(int i = 1;i <= n;i++){
		if(s[i]){
			for(int j = 1;j <= n;j++){
				printf("s i=%d j=%d\n",i,j);
				if(!t[j]){
					a = min(a,Lx[i]+Ly[j] - weight[i][j]);
				}
			}
		}
	}
	for(int i = 1;i <= n;i++){
		if(s[i])	Lx[i] -= a;
		if(t[i])	Ly[i] += a;
	}
}

void KM(){
	for(int i = 1;i <= n;i++){
		left[i] = Lx[i] = Ly[i] = 0;
		for(int j = 1;j <= n;j++)
			Lx[i] = max(Lx[i],weight[i][j]);
		printf("Lx[i] = %d\n",Lx[i]);
	}
	for(int i = 1;i <= n;i++){
		for(;;){
			for(int j = 1;j <= n;j++)
				s[j] = t[j] = 0;
			if(match(i))	break;
			else	update();
		}
	}
}

int main(){
	//printf("%d\n",MAXN);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				scanf("%d",&weight[i][j]);
			}
		}
		KM();
		int ans = 0;
		for(int i = 1;i <= n;i++){
			ans += weight[left[i]][i];
		}
		printf("%d\n",ans);
	}
}
