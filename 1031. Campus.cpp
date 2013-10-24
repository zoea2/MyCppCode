#include <iostream>
#include <map>
#include <cstring>
#define INF 1000000
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<string,int>m;
        m.clear();
        int count = 0;
        string s1,s2;
        int graph[205][205];
        bool final[205] = {0};
        int sp[205];
        for (int i = 0;i < 205;i++)
        {
                for (int j = 0;j < 205;j++)
                {
                    graph[i][j]=((i==j)?0:INF);
                }
        }
        for (int i = 0;i < n;i++)
        {
            int d;
            cin>>s1>>s2>>d;
            if (!m.count(s1))
                m[s1] = count++;
            if (!m.count(s2))
                m[s2] = count++;
            graph[m[s1]][m[s2]] = graph[m[s2]][m[s1]] = d;
        }
        count;
        cin>>s1>>s2;
        if(!m.count(s1)||!m.count(s2))
        {
            if (s1 == s2)
            cout<<0<<endl;
            else
            cout<<"-1"<<endl;
            continue;
        }
        for (int i = 0;i < count;i++)
            sp[i] = graph[m[s1]][i];
        sp[m[s1]] = 0;
        final[m[s1]] = true;
        int temp;
        int min;
        for (int i = 0;i < count;i++)
        {
            min = INF;
            temp = m[s1];
            for (int j = 0;j < count;j++)
            {
                if (!final[j])
                {
                    if (sp[j] < min)
                    {
                        temp = j;
                        min = sp[j];
                    }
                }
            }
            final[temp] = true;
            for (int j = 0;j < count;j++)
            {
                if (!final[j]&&min + graph[temp][j]<sp[j])
                sp[j] = min + graph[temp][j];
            }
        }
        if(final[m[s2]])
            cout<<sp[m[s2]]<<endl;
        else
        cout<<-1<<endl;

    }
}






