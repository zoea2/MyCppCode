#include <iostream>
#include <cmath>
using namespace std;
bool prime(int a,int b)
{
    for (int i = 2;i <= a;i++)
    {
        if (a % i == 0 && b % i == 0)
        return false;
    }
    return true;
}
int main()
{
    int gcd,lcm;
    cin>>gcd>>lcm;
    while (gcd != 0 && lcm != 0)
    {
        int temp1 = lcm / gcd;
        int temp2 = sqrt(temp1 * 1.0);
        int a,b;
        for (int i = temp2;i >= 1;i--)
        {
            if (temp1 % i == 0)
            {
                if (prime(i,temp1 / i))
                {
                    a = i * gcd;
                    b = temp1 / i * gcd;
                    break;
                }
            }
        }
        cout<< b - a <<" "<< a << " " << b<<endl;
        cin>>gcd>>lcm;
    }
}
