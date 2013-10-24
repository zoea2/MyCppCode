#include <cstdio>
#include <string>
#include <set>
#include <cctype>
using namespace std;
int main()
{
    int n,m;
    scanf("%d",&n);
    while(n!= 0)
    {
        set<string> s;
        scanf("%d",&m);
        char temp[10];
        for (int i = 0;i < n;i++)
        {
            scanf("%s",&temp);
            string temp0 = temp;
            for (int j = 0;j < temp0.length();j++)
            temp0[j] = tolower(temp0[j]);
            s.insert(temp0);
        }
        for (int i = 0;i < m;i++)
        {
            scanf("%s",&temp);
            string temp0 = temp;
            for (int j = 0;j < temp0.length();j++)
            temp0[j] = tolower(temp0[j]);
            //if (s.count(temp0)!=0)
                s.erase(temp0);
        }
        printf("%d\n",s.size());
        scanf("%d",&n);
    }
}
