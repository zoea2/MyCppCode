#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <set>
using namespace std;
bool visit[202];
vector<int>path;
class box
{
    public:
    int num;
    int lock;
    vector<int> keys;
};
multiset<int> key;
box boxs[202];
bool flag;
void dfs(box cur,int count,int n)
{
    if(!flag)
    {
        key.erase(key.find(cur.lock));
        visit[cur.num] = true;
        count--;
        path.push_back(cur.num);
        cout<<cur.num<<"in ";
        if(count == 0)
        {
            flag = true;
            //cout<<endl;
            return;
        }
        for(int i = 0;i < cur.keys.size();i++)
            key.insert(cur.keys[i]);
        int unopen = 0;
        for(int i = 1;i <= n;i++)
        {
            if(!flag)
            {
                if(key.count(boxs[i].lock) > 0 && !visit[boxs[i].num])
                {
                    dfs(boxs[i],count,n);
                    unopen++;
                }

            }
            else
            break;
        }

        if(unopen == 0 && !flag)
        {
            key.insert(cur.lock);
            visit[cur.num] = false;
            path.pop_back();
            cout<<cur.num<<"out ";
            count++;
            return;
        }

    }
}
int main()
{
    ifstream input;
    input.open("C:\\Users\\Administrator\\Desktop\\D-small-attempt13.in");
    int t;
    //cin>>t;
    input>>t;
    int k,n;
    ofstream output;
    output.open("C:\\Users\\Administrator\\Desktop\\D-small-attempt13.out");
    for (int c = 1;c <= t;c++)
    {
        memset(boxs,0,sizeof(boxs));
        flag = false;
        path.clear();
        memset(visit,0,sizeof(visit));
        input>>k>>n;
        key.clear();
        int ke;
        for(int i = 0;i < k;i++)
        {
            //cin>>ke;
            input>>ke;
            key.insert(ke);
        }
        for (int i = 1;i <= n;i++)
        {
            //cin>>ke;
            input>>ke;
            boxs[i].num = i;
            boxs[i].lock = ke;
            //cin>>k;
            input>>k;
            for(int j = 0;j < k;j++)
            {
                //cin>>ke;
                input>>ke;
                boxs[i].keys.push_back(ke);
            }
        }
        for(int i = 1;i <= n;i++)
        {
            if(key.count(boxs[i].lock) > 0&&!visit[i])
                dfs(boxs[i],n,n);
        }
        if(flag)
        {
            output<<"Case #"<<c<<":";
            for(int i = 0;i < path.size();i++)
                output<<" "<<path[i];
            output<<"\n";

        }
        else
            output<<"Case #"<<c<<": IMPOSSIBLE\n";
         cout<<"Case #"<<c<<": IMPOSSIBLE\n";

    }
    input.close();
    output.close();
}
