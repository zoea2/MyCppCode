#include <iostream>
#include <cstdio> 
#include <set>
#include <cmath>
#include <cstring>
using namespace std;
bool visit[100000002];
int prime[100000];
int count0 = 0;
bool isPP = false;
bool isPal(int num)
{
	int count = 0;
	int temp = num;
	while(temp != 0){
		count++;
		temp /= 10;
	}
	while(num != 0){
		int t = pow(10,count-1);
		if(num % 10 != num / t)
			return false; 		
		num %= t;
		num /= 10;
		count -= 2;		
	}
	return true;
}
int biSearch(int n)
{
	isPP = false;
	int low = 0;
	int high = count0 - 1;
	int mid;
	while(high >= low){
		mid = (low + high) / 2;
		if(prime[mid] == n)
		{
			isPP = true;
			return mid;			
		}
		else if(prime[mid] > n)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return low;
}
int main()
{
	memset(visit,0,sizeof(visit));
	prime[count0++] = 2;
	for(int i = 3;i <= 10000000;i+=2){
		if(visit[i] == false){
			if(isPal(i)){
				prime[count0++] = i;
				//cout<<prime[count0-1]<<endl;
			}
			for(int j = 2;j * i <= 10000000;j++){
				visit[i*j] = true;
			}
		}
	}
	int n,m;
	scanf("%d%d",&n,&m);
	while(n != 0 || m != 0){
		int low = biSearch(n);
		int high = biSearch(m);
		for(int i = low;i < high; i++){
			printf("%d\n",prime[i]);
		}
		if(isPP){
			printf("%d\n",prime[high]);
		}
		scanf("%d%d",&n,&m);
	}
	
	//int t;
	//cin>>t;
	//cout<<isPal(t)<<endl;
}
