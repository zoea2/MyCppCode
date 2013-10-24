#include <iostream>
using namespace std;
int gcd(int n,int m)
{
    if (n % m == 0)
    return m;
    else
    return gcd(m,n % m);
}
int main()
{
    int t,a,b,c,d,e,f;
    cin>>t;
    while(t)
    {
        t--;
        cin>>a>>b>>c>>d;
        if (b == d)
        {
            e = a + c;
            f = b;
        }
        else
        {
            int temp = b;
            b *= d;
            a *= d;
            d *= temp;
            c *= temp;
            f = b;
            e = a + c;
        }

        int g = gcd(e,f);
        e /= g;
        f /= g;
        if (f == 1)
        cout<<e<<endl;
        else
        cout<<e<<"/"<<f<<endl;
    }
}
