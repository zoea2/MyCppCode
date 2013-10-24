#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n,m;
    scanf("%d",&n);
    string temp;
    char tempc[100];
    while(n != 0)
    {
        map<string,int> ma;
        map<string,int> maind;
        int tempm = 0;
        for (int z = 0;z < n;z++)
        {
            scanf("%s",&tempc);
            scanf("%d",&m);
            for (int i = 0;i<m;i++)
            {
                scanf("%s",&tempc);
                temp = tempc;
                if (ma.count(temp) == 0)
                {
                    ma[temp] = 1;
                    maind[temp] = z * tempm + i + 1;
                }
                else
                ma[temp]++;
            }
            tempm = m;
        }
        map<int,string> ma0;
        for (map<string,int>::iterator i = ma.begin();i != ma.end();i++)
        {
            if (ma0.count((*i).second) == 0)
            ma0[(*i).second] = (*i).first;
            else
            {
                if (maind[(*i).first] < maind[ma0[(*i).second]])
                ma0[(*i).second] = (*i).first;
            }
        }
        cout<<(*(--ma0.end())).second<<endl;
        scanf("%d",&n);
    }
}
