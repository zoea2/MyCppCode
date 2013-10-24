#include <iostream>
using namespace std;
void reverse(int ans[],int s,int t)
{
    int temp;
    while(s < t)
    {
        temp = ans[s];
        ans[s] = ans[t];
        ans[t] = temp;
        s++;
        t--;
    }
}
void Hamilton(int ans[],bool map[][401],int n)
{
    int s = 1,t;
    int ansi = 2;
    int i,j,w,temp;
    bool visited[401] = {false};
    for (i = 1;i <= n;i++)
    {
        if (!map[s][i])
        break;
    }
    t = i;
    visited[s] = true;
    visited[t] = true;
    ans[0] = s;
    ans[1] = t;
    while(true)
    {
        while(true)
        {
            for (i = 1;i <= n;i++)
            {
                if (!map[t][i]&&!visited[i])
                {
                    ans[ansi++] = i;
                    visited[i] = true;
                    t = i;
                    break;
                }
            }
            if (i > n)
            break;
        }
        w = ansi-1;
        i = 0;
        reverse(ans,i,w);
        temp = s;
        s = t;
        t = temp;
        while(true)
        {
            for (i = 1;i <= n;i++)
            {
                if (!map[t][i]&&!visited[i])
                {
                    ans[ansi++] = i;
                    visited[i] = true;
                    t = i;
                    break;
                }
            }
            if (i > n)
            break;
        }
        if (map[s][t])
        {
            for (i = 1;i < ansi-2;i++)
            {
                if (!map[ans[i]][t]&&!map[s][ans[i+1]])
                break;
            }
            w = ansi - 1;
            i++;
            t = ans[i];
            reverse(ans,i,w);
        }
        if (ansi == n)
        return;
        for (j = 1;j <= n;j++)
        {
            if (visited[j]) continue;
            for (i = 1;i < ansi-2;i++)
            {
                if (!map[ans[i]][j])  break;
            }
            if (!map[ans[i]][j]) break;
        }
        s = ans[i-1];
        t = j;
        reverse(ans,0,i-1);
        reverse(ans,i,ansi-1);
        ans[ansi++] = j;
        visited[j] = true;
    }

}
int main()
{
    int n,m;
    cin>>n>>m;
    while(n!=0||m!=0)
    {
        int k,t;
        bool map[401][401] = {0};
        for (int i = 0;i < m;i++)
        {
            cin>>k>>t;
            map[k][t] = true;
            map[t][k] = true;
        }
        for (int i = 1;i <= 2*n;i++)
        {
            map[i][i] = true;
        }
        int ans[400];
        Hamilton(ans,map,2*n);
        for (int i = 0;i < 2*n;i++)
        cout<<ans[i]<<" ";
        cout<<endl;
        cin>>n>>m;
    }
}
