#include<iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int lot[10001][1];
int gcd(int a,int b)
{
    if (b == 0)
    return a;
    else
    return gcd(b,a%b);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int temp0;
    while(n != 0 || m != 0)
    {
        memset(lot,0,sizeof(lot));
        int sum = 0;
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < m;j++)
            {
                scanf("%d",&temp0);
                if (j == m-1)
                {
                    lot[i][0] = temp0;
                    sum += lot[i][0];
                }
            }
        }
        for (int i = 0;i < n;i++)
        {
            int temp = gcd(sum,lot[i][0]);
            printf("%d / %d\n",lot[i][0] / temp,sum / temp);
        }
        scanf("%d%d",&n,&m);
    }
}
