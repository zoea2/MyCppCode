#include <cstdio>
#include <map>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int t,n,m;
    string s,x,y,temp;
    scanf("%d",&t);
    for(int i = 1;i <= t;i++)
    {
        map<string,string> maps;
        scanf("%d%d",&n,&m);
        for(int j = 0;j < m;j++)
        {
            cin>>x>>y;
            maps[x] = y;
        }
        getchar();
        getline(cin,s);
        string res,res0;
        for(int p = 1;p < n;p++)
        {
            int length = s.length();
            for (int j = 0;j < length;j++)
            {
                if (s[j]!= ' ')
                    temp.append(1,s[j]);
                else
                {
                    if(maps.count(temp) == 0)
                        res.append(temp);
                    else
                    {
                        res.append(maps[temp]);
                    }
                    res.append(1,' ');
                    temp.clear();
                }
                if (j == length - 1)
                {
                    if(maps.count(temp) == 0)
                        res.append(temp);
                    else
                        res.append(maps[temp]);
                    //res.append(1,'\0');
                    temp.clear();
                }
            }
            s = res;
            res.clear();
        }
        cout<<"Case #"<<i<<": "<<s<<endl;
    }
}
