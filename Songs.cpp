#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
struct song
{
    int id;
    long long time;
    double fre;
};
bool cmp(song a,song b)
{
    return (a.fre / a.time) > (b.fre / b.time);
}
int main()
{
    long long n,m;
    while(scanf("%lld",&n) != EOF)
    {
        song s[n];
        for(long long i = 0;i < n;i++)
        {
            scanf("%d%lld%lf",&s[i].id,&s[i].time,&s[i].fre);
        }
        sort(s,s+n,cmp);
        scanf("%lld",&m);
        printf("%d\n",s[m-1].id);
    }
}
