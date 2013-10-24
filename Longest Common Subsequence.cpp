#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[1010][1010];
char s1[1010];
char s2[1010];
int main()
{
    while(gets(s1) && gets(s2))
    {
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        for(int i = 1;i <= len1;i++)
        {
            for(int j = 1;j <= len2;j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        printf("%d\n",dp[len1][len2]);
    }
}
