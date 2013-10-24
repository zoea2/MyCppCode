#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char num[1000];
    int count = 0;
    if (n == 0)

    {
        cout<<10;
        return 0;}
    else if (n < 10)
    {
        cout<<n;
        return 0;
    }
    for (int i = 9;i > 1;i--)
    {
        while(n % i == 0 && n != 1)
        {
            num[count] = i + '0';
            count++;
            n /= i;

        }
        if (n == 1)
        break;
    }

    if (n == 1)
    {
        for (int i = count - 1;i >= 0;i--)
        {
            cout<<num[i];
        }
    }
    else
    cout<<-1;

}
