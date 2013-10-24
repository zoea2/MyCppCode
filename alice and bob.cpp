#include <cstdio>
int num[50];
bool find(int n)
{
    for(int i = 0;i < n;i++)
    {
        if(num[i] == 2)
        return true;
    }
    return false;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int c = 1;c <= t; c++)
    {
        int n;
        scanf("%d",&n);
        int count1 = 0;
        int countEther = 0;
        int sum = 0;
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&num[i]);
            if(num[i] == 1)
                count1++;
            else
            {
                countEther++;
                sum += num[i];
            }
        }
        //printf("%d %d %d \n",count1,countEther,sum);
        if(countEther == 0)
        {
            if(count1 % 3 != 0)
                printf("Case #%d: Alice\n",c);
            else
                printf("Case #%d: Bob\n",c);
        }
        else
        {
            if(count1 == 0)
            {
                if((sum + countEther) % 2 == 0)
                    printf("Case #%d: Alice\n",c);
                else
                    printf("Case #%d: Bob\n",c);
            }
            else if(count1 % 2 == 1)
            {
                if(countEther == 1 && find(n))
                {
                    if(count1 % 3 != 0)
                        printf("Case #%d: Alice\n",c);
                    else
                        printf("Case #%d: Bob\n",c);
                }
                else
                    printf("Case #%d: Alice\n",c);
            }

            else
            {
                if(countEther == 1 && find(n))
                 {
                    if(count1 % 3 != 0)
                        printf("Case #%d: Alice\n",c);
                    else
                        printf("Case #%d: Bob\n",c);
                }
                else if((sum + countEther) % 2 == 0)
                    printf("Case #%d: Alice\n",c);
                else
                    printf("Case #%d: Bob\n",c);
            }
        }
    }
}
