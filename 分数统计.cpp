#include <cstdio>
int main()
{
    int t;
    scanf("%d",&t);
    while(t)
    {
        t--;
        int m;
        scanf("%d",&m);
        int score[m];
        float scores = 0;
        for (int i = 0;i < m;i++)
            scanf("%d",&score[i]);
        int max = score[0];
        int maxindex = 0;
        for (int i = 0;i < m;i++)
        {
            if (max < score[i])
            {
                max = score[i];
                maxindex = i;
            }
        }
        score[maxindex] = 0;
        if (maxindex == 0)
        {
            max = score[1];
            maxindex = 1;
            for (int i = 1;i < m;i++)
            {
                if (max > score[i])
                {
                    max = score[i];
                    maxindex = i;
                }
            }
        }
        else
        {
            max = score[0];
            maxindex = 0;
            for (int i = 0;i < m;i++)
            {
                if (score[i] != 0)
                {
                    if (max > score[i])
                    {
                    max = score[i];
                    maxindex = i;
                    }
                }
            }
        }
        score[maxindex] = 0;
        for(int i = 0;i < m;i++)
            scores += score[i];
        scores = scores * 1.0 / (m - 2);
        printf("%.2f\n",scores);

    }
    return 0;
}
