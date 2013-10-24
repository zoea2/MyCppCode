#include <cstring>
#include <cstdio>
bool stone[1000000002];
int dp[100000000];
int l,s,t,m,temp;
int min(int l)
{
    int minnum = 200;
    for(int i = l - t;i < l-s;i++)
    {
        if(i >= 0)
            if(minnum > dp[i])
                minnum = dp[i];
    }
    return minnum;
}
int main()
{
    scanf("%d%d%d%d",&l,&s,&t,&m);
    for(int i = 0;i < m;i++)
    {
        scanf("%d",&temp);
        stone[temp] = true;
    }
    for(int i = 1;i <= l;i++)
    dp[i] = min(i) + stone[i];
    printf("%d\n",dp[l]);

}
