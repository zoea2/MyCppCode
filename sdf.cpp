#include <iostream>
#include <stdio.h>
using namespace std;
void count(int n,unsigned long long &result)
{
    unsigned long long product = 1;
    for (int t = 1;t <= n;t++)
    {
        product *= t;
        result += product;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    unsigned long long result = 0;
    count(n,result);
    printf("%d\n",result % 1000000);

    return 0;
}
