#include <iostream>
using namespace std;
int INF = 0x7FFFFFFF;
int graph[501][501];
int main()
{
    int t;
    char a;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        //cout<<n;
        int visit[501] = {0};
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= n;j++)
                cin>>graph[i][j];
        }
        int c[n+1];
        for (int i = 1;i <= n;i++)
        {
            c[i] = graph[1][i];
            //cout<<c[i]<<" "<<i<<endl;
        }
        int count = 0;
        for (int i = 1;i < n;i++)
        {
            int min = INF;
            int index;
            for (int j = 2;j <= n;j++)
            {
                if (min > c[j] && c[j]>0)
                {
                    min = c[j];
                    index = j;
                }
                //cout<<c[j]<<endl;
            }
            c[index] = 0;
            if(count < min)
            count = min;
            for (int j = 1;j <= n;j++)
            {
                if (c[j] > graph[index][j])
                    c[j] = graph[index][j];
            }
        }
        cout<<count<<endl;
        if (t > 0)
        cout<<endl;
    }
}
