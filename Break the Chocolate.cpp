#include <cstdio>
#include <cstring>
using namespace std;
long long m2(long long num)
{
	long long sum = 2;
	long long count = 1;
	if(num == 1)
		return 0;
	else{
		while(sum < num){
			sum *= 2;
			count++;
		}
		return count;
	}
}
int main()
{
	int t,x,y,z;
	scanf("%d",&t);
	for(int i = 1;i <= t;i++){
		scanf("%d%d%d",&x,&y,&z);
		long long sum = (long long) x * y * z;
		long long res1 = sum - 1;
		long long res2 = m2(x)+m2(y)+m2(z);
        printf("Case #%d: %lld %lld\n",i,res1,res2);
	}
}
