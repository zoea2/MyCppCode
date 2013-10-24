#include <cstring>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
struct card{
	int height;
	int width;
	bool isAlice;
};
bool cmp(card a,card b){
	if(a.height != b.height){
		return a.height > b.height;
	}
	else if(a.isAlice && !b.isAlice){
		return true;
	}
	else if(b.isAlice && !a.isAlice){
		return false;
	}
	return true;
}
card s[200002];
int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 0;i < n;i++){
			scanf("%d%d",&s[i].height,&s[i].width);
			s[i].isAlice = true;
		}
		for(int i = n;i < 2*n;i++){
			scanf("%d%d",&s[i].height,&s[i].width);
			s[i].isAlice = false;
		}
		sort(s,s+2*n,cmp);
		/*for(int i = 0 ;i < 2 * n;i++){
			printf("%d %d %d\n",s[i].height,s[i].width,s[i].isAlice);
		}*/
		int ans = 0;
		multiset<int> unUsedCard;
		unUsedCard.clear();
		for(int i = 0;i < 2 * n;i++){
			if(s[i].isAlice == true){
				unUsedCard.insert(s[i].width);
			}
			else if(s[i].isAlice == false){
				multiset<int>::iterator it = unUsedCard.lower_bound(s[i].width);
				if(it != unUsedCard.end()){
					unUsedCard.erase(it);
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
}
