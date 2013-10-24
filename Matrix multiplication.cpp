#include <stdio.h>
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int a[n][n],b[n][n],c[n][n];
        for(int i = 0;i < n;i++)
        {
            for (int j = 0;j < n;j++)
                scanf("%d", &a[i][j]);
        }
        for(int i = 0;i < n;i++)
        {
            for (int j = 0;j < n;j++)
                scanf("%d", &b[i][j]);
        }
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                c[i][j] = 0;
                for (int t = 0; t < n;t++)
                    c[i][j] += a[i][t] * b[t][j];
            }
        }
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                printf("%d",c[i][j]);
                if (j != n - 1)
                    printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}

