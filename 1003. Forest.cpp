#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int level,width;
bool is = true;
void dfs(int cur,vector<int> vec[],bool visit[],int count,int count2[])
{
    count2[count]++;
    if(width < count2[count])
    width = count2[count];
    for (int i = 0;i < vec[cur].size();i++)
    {
        if (visit[vec[cur][i]])
        {
            is = false;
            return;
        }
        else
        {
            visit[vec[cur][i]] = true;
            dfs(vec[cur][i],vec,visit,count+1,count2);
        }

    }
    if (level < count)
    level = count;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int x,y;
    while(n != 0)
    {
        bool visit[101] = {0};
        vector<int> vec[n+1];
        int ind[101] = {0};
        level = 0;
        is = true;
        int count2[105] = {0};
        width = 0;
        for (int i = 0;i < m;i++)
        {
            cin>>x>>y;
            vec[x].push_back(y);
            ind[y]++;
        }
        for (int i = 1;i <= n;i++)
        {
            if (!visit[i]&&ind[i] == 0)
            {
                visit[i] = true;
                dfs(i,vec,visit,0,count2);
            }
        }
        for (int i = 1;i <= n;i++)
        {
            if (visit[i] == 0)
            is = false;
        }
        if (is)
        cout<<level<<" "<<width<<endl;
        else
        cout<<"INVALID"<<endl;

        cin>>n>>m;
    }
}
