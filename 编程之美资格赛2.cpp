#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
struct node
{
    int des;
    long long len;
    node(int y,long long l)
    {
        des = y;
        len = l;
    }
};
vector<node>vec[100002];
vector<long long>path;
bool visit[100002];
bool finded = 0;
bool tri;
void dfs(int x,int y)
{
    for(int i = 0;i < vec[x].size();i++)
    {
        if(finded)
        return;
        node temp = vec[x][i];
        //cout<<x <<"to"<<temp.des<<endl;
        if(!visit[temp.des])
        {
            visit[temp.des] = true;
            path.push_back(temp.len);
            if(temp.des == y)
                finded = true;
            else
            {
                dfs(temp.des,y);
            }
            if(!finded)
                path.pop_back();
            visit[temp.des] = false;
        }
    }
}
int main()
{
    int t,n,m,x,y;
    long long len;
    scanf("%d",&t);
    for(int e = 1;e <= t;e++)
    {
        memset(vec,0,sizeof(vec));
        memset(visit,0,sizeof(visit));
        scanf("%d",&n);
        for(int i = 1;i < n;i++)
        {
            scanf("%d%d%lld",&x,&y,&len);
            vec[x].push_back(node(y,len));
            vec[y].push_back(node(x,len));
        }
        scanf("%d",&m);
        printf("Case #%d:\n",e);
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d",&x,&y);
            path.clear();
            finded = false;
            tri = false;
            memset(visit,0,sizeof(visit));
            visit[x] = true;
            dfs(x,y);
            //cout<<"dfsdone\n"<<endl;
            for(int j = 0;j < path.size();j++)
            {
                if (!tri)
                {
                    for(int k = j+1;k < path.size();k++)
                    {
                        if (!tri)
                        {
                            for(int o = k + 1;o < path.size();o++)
                            {
                                long long a = path[j];
                                long long b = path[k],c = path[o];
                                if (a + b > c && a + c > b && b + c > a)
                                    tri = true;
                            }
                        }
                        else
                        break;
                    }
                }
                else
                break;
            }
            //cout<<"pathdone"<<endl;
            if(tri)
            printf("Yes\n");
            else
            printf("No\n");
        }
    }
}
