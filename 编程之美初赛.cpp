#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    int n,ca,cb;
    for(int c = 1;c <= t;c++)
    {
        scanf("%d%d%d",&n,&ca,&cb);
        int temp;
        if (n == 0)
        {
            printf("Case #%d: 0\n",c);
            continue;
        }
        if(n == 1)
        {
            if(ca >= cb)
            printf("Case #%d: 1\n",c);
            else
            printf("Case #%d: -1\n",c);
            continue;
        }
        if(n % 2 == 0)
            temp = n / 2;
        else
            temp = n / 2 + 1;
        if(ca / cb >= temp)
        {
            printf("Case #%d: 1\n",c);
            continue;
        }
        if (cb / ca >= temp)
        {
            printf("Case #%d: -1\n",c);
            continue;
        }
        if (ca / temp >= 2 && cb / temp >= 2 && n % 2 == 0)
            printf("Case #%d: 0\n",c);
        else if(ca / temp >= 2 && cb / temp >= 2 && n % 2 == 1 )
            printf("Case #%d: 1\n",c);
        else if(ca / temp >= 2 && cb / temp >= 2 && n % 2 == 1)
            printf("Case #%d: 1\n",c);
        else if (ca / temp >= 1 && cb / temp < 2)
            printf("Case #%d: 1\n",c);
        else if(cb / temp >= 2)
            printf("Case #%d: -1\n",c);
        else if(ca > cb)
            printf("Case #%d: 1\n",c);
        else if(ca == cb)
            printf("Case #%d: 0\n",c);
        else if(ca < cb)
            printf("Case #%d: -1\n",c);
    }
}
