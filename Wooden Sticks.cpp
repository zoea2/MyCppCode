#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct sticks{
	   int l;
	   int w;
	   sticks(int a,int b){
	   			  l = a;
	   			  w = b;
	   }
};
bool cmp(sticks a,sticks b){
    if(a.l != b.l)
        return a.l< b.l;
    else
        return a.w < b.w;
}


int main()
{
 	int t,n,a,b;
 	scanf("%d",&t);
 	vector<sticks> vec;
 	while(t--){
        scanf("%d",&n);
        for(int i = 0;i < n;i++){
				scanf("%d%d",&a,&b);
				vec.push_back(sticks(a,b));
        }
        sort(vec.begin(),vec.end(),cmp);
        //for(int i = 0;i < n;i++)
            //printf("%d %d\n",vec[i].l,vec[i].w);
        int ans = 1;
        sticks temp = vec[0];
        vec.erase(vec.begin());
        while(!vec.empty()){
				//int min = 1000000;
				int index = -1;
				for(int i = 0;i < vec.size();i++){
                        //printf("skdfjsd\n");
						if(vec[i].l >= temp.l && vec[i].w >= temp.w){
									//min = vec[i].l - temp.l + vec[i].w - temp.w;
									index = i;
									break;
						}
				}
				if (index == -1){
				   		  ans++;
				   		  temp = vec[0];
				   		  vec.erase(vec.begin());
				}
				else{
					 temp = vec[index];
					 vec.erase(vec.begin()+index);
				}
        }
	    printf("%d\n",ans);

 	}

}
