#include <cstdio>
#include <set>
#include <queue>
#include <iostream>
#include <fstream>
using namespace std;
ofstream out("/home/iladmin/sicily/web/temp.txt");
int main()
{
    int max,len;
     bool flag = true;
    while(scanf("%d%d",&max,&len)!=EOF)
    {   out<<max<<endl<<len<<endl;
        multiset<int> s;
    set<int> q;
    int temp;
    if(flag)
            flag = false;
        else
            printf("\n");
    for (int i = 0;i<len;i++)
    {
        scanf("%d",&temp);
        q.insert(temp);
        out<<temp<<" ";
    }
    char ques;
    scanf("%c",&ques);
    out<<ques<<" ";
    int count = 1;
    int p = 1;
    while(ques != 'e')
    {
        if (ques == 'a')
        {
            scanf("%d",&temp);
            s.insert(temp);
            out<<temp<<endl;
        }

        else if (ques == 'r')
        {
            if (p == 1)
            {
                if (s.empty())
                {
                    cout<<"-1"<<endl;
                }
                else if (count == *(q.begin()))
                {
                    cout<<*(s.begin())<<endl;
                    q.erase(q.begin());
                    s.erase(s.begin());
                }
                else
                    s.erase(s.begin());
            }
            else if (p == 2)
            {
                if (s.empty())
                {
                    cout<<"-1"<<endl;
                }
                else if (count == *(q.begin()))
                {
                    cout<<*(--s.end())<<endl;
                    q.erase(q.begin());
                    s.erase(--s.end());
                }
                else
                    s.erase(--s.end());
            }
            count++;
            out<<endl;
        }
        else if (ques == 'p')
        {
            scanf("%d",&temp);
            p = temp;
            out<<temp<<endl;
        }
        scanf("%c",&ques);
        out<<ques<<" ";
    }
    //printf("\n");
    }
}
