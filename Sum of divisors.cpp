#include <cstdio>
#include <cmath>

using namespace std;

int n,m;
int bit[200];

int change(int num)
{
    int cnt = 0;
    while(num > 0)
    {
        bit[cnt++] = num % m;
        num /= m;
    }
    return cnt;
}

int main()
{
    while(scanf("%d%d",&n,&m) != EOF)
    {
        int count;
        int result = 0;
        int t = (int)sqrt(n*1.0);
        for(int i = 1;i <= t;i++)
        {
            if(n % i == 0)
            {
                count = change(i);
                for(int j = 0;j < count;j++)
                {
                    result += bit[j] * bit[j];
                }
                int tmp = n / i;
                if(i != tmp)
                {
                    count = change(tmp);
                    for(int j = 0;j < count;j++)
                    {
                        result += bit[j] * bit[j];
                    }
                }
            }
        }
        count = change(result);
        for(int i = count-1;i >= 0;i--)
        {
            if(bit[i] > 9)
                printf("%c",bit[i] - 10 + 'A');
            else
                printf("%d",bit[i]);
        }
        printf("\n");
    }
}
