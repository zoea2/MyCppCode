#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

#define inf 9223372036854775808LL

int main()
{
    long long n;
    long long left ;
    long long right;
    long long mid;
    double k;
    long long ansr;
    long long ansk;
    long long temp;
    long long tmp;

    while(scanf("%lld",&n) == 1)
    {
        ansr = 1;
        ansk = n-1;
        temp = n-1;
        for(int i = 2;i < 45;i++)
        {
            left = 2;
            right = (temp-1) / i;
            while(left <= right)
            {
                mid = (left + right) >> 1;
                k = pow((double)mid,i);
                //printf("%lld\n",mid);
                if(k > inf)
                {
                    right = mid - 1;
                    continue;
                }
                else
                    tmp = (long long )k;
                tmp = (tmp - 1) / (mid - 1);
                if(tmp == n || tmp == n+1)
                {
                    if(temp > mid * (i-1))
                    {
                        temp = mid * (i-1);
                        ansr = i-1;
                        ansk = mid;
                    }
                    break;
                }
                else if(tmp > n)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }
        printf("%lld %lld\n",ansr,ansk);
    }
}
