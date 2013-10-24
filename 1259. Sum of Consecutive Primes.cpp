#include <iostream>
using namespace std;
int main()
{
    int prime[10001] = {0};
    int get[10001] = {0};
    for (int i = 2;i<=10000;i++)
    {
        prime[i] = 1;
    }
    for (int i = 2;i<=10000;i++)
    {
        if (prime[i] == 1)
        {
            for (int j = 2;j * i <= 10000;j++)
            {
                prime[i*j] = 0;
            }
        }
    }
    int total;
    for (int i = 2; i <= 10000; i++)
    {
        if (prime[i] == 0)
            continue;
        total = i;
        get[total]++;
        for (int j = i + 1; j <= 10000; j++)
        {
            if (prime[j] == 0)
                continue;
            total += j;
            if (total <= 10000)
                get[total]++;
            else
                break;
        }
    }
    int num;
    cin>>num;
    while(num!=0)
    {
        cout<<get[num]<<endl;
        cin>>num;
    }
}
