#include<cstdio>
#include <vector>
#include <cstring>
#include <set>
using namespace std;
struct node{
	int value[55];
};
node smgTree[50001*3];
void init(int o,int l,int r,long long c,int index){
	int m = (l + r) / 2;
	if(l == r) smgTree[o].value[0] += c;
	else{
		if(index <= m)	init(o*2,l,m,c,index);
		else	init(o*2+1,m+1,r,c,index);
	}
}
void update(int o,int l,int r,int c,int ol,int orr,int k){
	if(l >= ol && r <= orr){
		for(int i = l;i <= r;i++){
			if(i % k == ol % k ){
				if(k == 1)
					smgTree[o].value[0] += c;
				else
					smgTree[o].value[k*(k-1)/2 + i % k] += c;
				//printf("c = %d\n",c);
				break;
			}
		}
		if(l == r)
			return;
	}
	else {
		int m = (l+r) / 2;
		if(m >= ol)	update(o*2,l,m,c,ol,orr,k);
		if(m+1 <= orr)	update(o*2+1,m+1,r,c,ol,orr,k); 
	}
}
int ans(int o,int l,int r,int index){
	int res = 0;
	if(index >= l && index <= r){
		int count = 0;
		for(int k = 1;k <= 10;k++){
			res += smgTree[o].value[count + index % k];
			count += k;
		}
	}
	if(l == r)
	return res;
	int m = (l + r) / 2;
	if(index <= m)	res += ans(o*2,l,m,index);
	else	res += ans(o*2+1,m+1,r,index);
	return res;
}
int main(){
	int n,q,p,a,b,k,c;
	int temp;
	while(scanf("%d",&n) != EOF){
		memset(smgTree,0,sizeof(smgTree));
		for(int i = 1;i <= n;i++){
			scanf("%d",&temp);
			init(1,1,n,temp,i);
		}
		/*for(int i = 1;i < 2 * n;i++){
			for(int j = 0;j < 50;j++)
			printf("%lld\n",smgTree[i].value[j]);
			
		}*/
		scanf("%d",&q);
		for(int i = 0;i < q;i++){
			scanf("%d",&p);
			if(p == 2){
				scanf("%d",&a);
				printf("%d\n",ans(1,1,n,a));
			}
			else{
				scanf("%d%d%d%d",&a,&b,&k,&c);
				//printf("%d %d %d %d\n",a,b,c,k);
				update(1,1,n,c,a,b,k);
				/*for(int i = 1;i < 2 * n;i++){
					for(int j = 0;j < 55;j++)
						printf("%lld ",smgTree[i].value[j]);
					printf("\n");
				}*/
					
			
		
			}
		}
	}
}
