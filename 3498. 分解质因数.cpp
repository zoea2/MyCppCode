#include<cstdio>
int main()
{
    int t;
    scanf("%d",&t);
    while(t)
    {
        --t;
        int n;
        scanf("%d",&n);
        for (int i = 2;i <= n; )
        {
            if ( n % i == 0)
            {
                if(n / i == 1)
                {
                    printf("%d \n",i);
                    break;
                }
                else
                {
                    printf("%d ",i);
                    n = n / i;
                }

            }

            else
            i++;
        }
    }
    return 0;
}
