#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
struct node
{
    int time;
    int des;
    int index;
    node(int a,int b,int c)
    {
        des = a;
        time = b;
        index = c;
    }

};
vector<node> vec[101];
bool visit[101];
bool block[101];
int d[101];
int main()
{
    int n,m,x,y,t;
    ios::sync_with_stdio(false);
    cin>>n>>m;
    bool blank = false;
    while(n!=0||m!=0)
    {
        if (blank)
        cout<<endl;
        else
        blank = true;
        memset(vec,0,sizeof(vec));
        cout<<sizeof(vec);
        char* a = new char[10000];
        cout<<sizeof(a);
        memset(block,0,sizeof(block));
        for (int i = 1;i <= m;i++)
        {
            cin>>x>>y>>t;
            vec[x].push_back(node(y,t,i));
            vec[y].push_back(node(x,t,i));
        }
        int q,temp;
        string s;
        cin>>q;
        int post = 1;
        while(q--)
        {
            cin>>s>>temp;
            if(s == "Block")
                block[temp] = true;
            else if(s == "Pass")
                block[temp] = false;
            else if(s == "To")
            {
                int cur = post;
                memset(visit,0,sizeof(visit));
                memset(d,0,sizeof(d));
                for (int i = 0;i < vec[cur].size();i++)
                {
                    if (block[vec[cur][i].index] == false)
                    {
                        if (d[vec[cur][i].des] == 0)
                        {
                            d[vec[cur][i].des] = vec[cur][i].time;
                        }
                        else if (d[vec[cur][i].des] > vec[cur][i].time)
                        {
                            d[vec[cur][i].des] = vec[cur][i].time;
                        }
                    }
                }
                visit[cur] = true;
                for (int j = 0;j < n;j++)
                {
                    int min = 0x7fffffff;
                    //int count = 0;
                    for (int i = 1;i <= n;i++)
                    {
                        if (d[i]!=0 && min > d[i]&&!visit[i])
                        {
                            cur = i;
                            min = d[i];
                        }
                    }
                    visit[cur] = true;
                    //count += min;
                    for (int i = 0;i < vec[cur].size();i++)
                    {
                        if (!block[vec[cur][i].index])
                        {
                            if(!visit[vec[cur][i].des] && (min + vec[cur][i].time < d[vec[cur][i].des] || d[vec[cur][i].des] == 0))
                                d[vec[cur][i].des] = min + vec[cur][i].time;
                        }
                    }
                }
                if (visit[temp])
                {
                    cout<<d[temp]<<endl;
                    post = temp;
                }
                else
                {
                    cout<<-1<<endl;
                }
            }
        }
        cin>>n>>m;
    }
}
