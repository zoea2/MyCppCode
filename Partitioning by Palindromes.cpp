#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[1002];
int dp[1002];

bool isPal(int left,int right)
{
    while(left <= right)
        if(s[left++] != s[right--])
            return false;

    return true;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",&s);
        int len = strlen(s);
        for(int i = 1;i <= len;i++)
            dp[i] = 10000;
        dp[0] = 0;
        for(int i = 1;i <= len;i++)
        {
            for(int j = 1;j <= i;j++)
            {
                if(isPal(j-1,i-1))
                    dp[i] = min(dp[i],dp[j-1]+1);
            }
        }
        printf("%d\n",dp[len]);
    }
}
