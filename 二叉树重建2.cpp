#include <cstring>
#include <cstdio>
#include <string>
#include <queue>

using namespace std;
char s1[30],s2[30];
int lchild[30];
int rchild[30];
char root; 

int index(char c){
	return c - 'A' + 1;
}
void solve(const char a[],const char b[]){

	//int length = strlen(b);
	if(strlen(a)<=1)
		return;
	char r = a[0];
	int subid;
	for(int i = 0;i < strlen(b);i++){
		if(b[i] == r)
			subid = i;
	}	
	string tempa,tempb;
	if(subid > 0){
		lchild[index(r)] = index(a[1]);
		//printf("%d leftchild %d\n",index(r),lchild[index(r)]);
		tempa = string(a);
		tempb = string(b);
		tempa = tempa.substr(1,subid);
		tempb = tempb.substr(0,subid);
		//printf("%s\n%s\n",tempa.c_str(),tempb.c_str());
		solve(tempa.c_str(),tempb.c_str());	
	}	
	if(subid < strlen(a) - 1){
		rchild[index(r)] = index(a[subid+1]);
		//printf("%d rightchild %d\n",index(r),rchild[index(r)]);
		tempa = string(a);
		tempb = string(b);
		tempa = tempa.substr(subid+1);
		tempb = tempb.substr(subid+1);
		//printf("%s\n%s\n",tempa.c_str(),tempb.c_str());
		solve(tempa.c_str(),tempb.c_str());	
	}
	
	
}
void bfs(){
	queue<int> q;
	q.push(index(root));
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		printf("%c",(char)(cur-1+'A'));
		if(lchild[cur]!=0)
			q.push(lchild[cur]);
		if(rchild[cur]!=0)
			q.push(rchild[cur]);
	}
	printf("\n");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s%s",&s1,&s2);
		//int len = strlen(s1);
		//printf("%d\n",len);
		root = s1[0];
		memset(lchild,0,sizeof(lchild));
		memset(rchild,0,sizeof(rchild));
		solve(s1,s2);
		bfs();
	}
	
}
