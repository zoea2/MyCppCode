#include <stdio.h>
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m),n != 0 || m != 0)
    {
        int product = 1;
        for (int i = n ;i > n - m;i--)
            product *= i;
        for (int i = 2;i <= m;i ++)
            product /= i;
        printf("%d\n",product);

    }
    return 0;
}
