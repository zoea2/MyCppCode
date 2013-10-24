#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int num[1000000];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int temp;
		int count = 0;
		scanf("%d",&temp);
		memset(num,0,sizeof(num));
		while(temp != 0){
			num[count++] = temp;
			scanf("%d",&temp);
		}
		int res = 0;
		for(int i = 0;i < count - 1;i++){
			sort(num+i,num+count);
			
			res += num[i] + num[i + 1];
			num[i+1] += num[i] ;
		}
		cout<<res<<endl;
	}
}
