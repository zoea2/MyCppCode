#include <cstring>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int>a,pair<int,int>b)
{
    return (long long)a.first * b.second < (long long)a.second * b.first;
}

pair<int,int> q[100005];

int main()
{
    int n;
    while(true)
    {
        scanf("%d",&n);
        if(n == 0)
            break;
        memset(q,0,sizeof(q));
        for(int i = 0;i < n;i++)
        {
            scanf("%d%d",&q[i].first,&q[i].second);
        }
        sort(q,q+n,cmp);
        long long res = 0;
        const int mod = 31536000;
        long long t = 0 ;
        for(int i = 0;i < n;i++)
        {

            res +=(q[i].first  + (t * q[i].second % mod)) % mod;
            res %= mod;
            t = res;
        }
        printf("%lld\n",res);
    }
}
