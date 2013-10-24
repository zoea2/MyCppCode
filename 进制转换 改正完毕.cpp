#include <iostream>
using namespace std;
int main()
{
    int t;
    unsigned int n,temp;
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        string number;
        if (n == 0)
        {
            cout<<"0"<<endl;
            continue;
        }
        while(n != 0)
        {
            temp = n % 2;
            number += temp + '0';
            n /= 2;
        }
        for (int i = number.length() - 1;i >= 0;i--)
            cout<<number[i];
        cout<<endl;
    }
    return 0;

}
