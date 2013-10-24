#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while (t)
    {
        --t;
        int n;
        scanf("%d",&n);
        int poker[n];
        for (int i = 0;i < n;i++)
            poker[i] = i + 1;
        while(n > 2)
        {
            printf("%d ",poker[0]);
            int temp = poker[1];
            for (int i = 0;i < n - 2;i++)
                poker[i] = poker [i + 2];
            poker[n - 2] = temp;
            n--;
        }
        if (n == 2)
            printf("%d %d \n",poker[0],poker[1]);
        else if(n == 1)
            printf("%d \n",poker[0]);
    }
    return 0;
}
