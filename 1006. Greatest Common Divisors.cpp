#include <iostream>
using namespace std;
bool gcd(int a,int b,int low,int high,int &i)
{
    for (i = high;i >= low;i--)
    {
        if (a % i == 0 && b % i == 0)
        return true;
    }
    return false;
}
int main()
{
    int t;
    cin>>t;
    while (t)
    {
        t--;
        int a,b,low,high;
        cin>>a>>b>>low>>high;
        int i;
        if(gcd(a,b,low,high,i))
        cout<<i<<endl;
        else
        cout<<"No answer"<<endl;

    }
}
