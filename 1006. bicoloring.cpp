#include <iostream>
#include <queue>
using namespace std;
vector<int> vec[1001];
int visit[1001] = {0};
bool is = true;
int main()
{
    int n,m;
    int u,v;
    cin>>n>>m;
    for (int i = 0;i < m;i++)
    {
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    visit[1] = 1;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (int i = 0;i < vec[temp].size();i++)
        {
            if (visit[vec[temp][i]] == 0)
            {
                if (visit[temp] == 1)
                visit[vec[temp][i]] = 2;
                else
                visit[vec[temp][i]] = 1;
                q.push(vec[temp][i]);
            }
            else if (visit[vec[temp][i]] == 1)
            {
                if (visit[temp] == 1)
                {
                    is = false;
                    break;
                }
            }
            else if (visit[vec[temp][i]] == 2)
            {
                if (visit[temp] == 2)
                {
                    is = false;
                    break;
                }
            }
        }
        if (!is)
        break;
    }
    if (is)
    cout<<"yes"<<endl;
    else
    cout<<"no"<<endl;
}
