#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n;
        cin>>n;
        int basis[n];
        for(int i = 0;i < n;i++)
            cin>>basis[i];
        string longint;
        cin>>longint;
        int length = longint.length();
        char num;
        cout<<"(";
        for(int i = 0;i < n ;i++)
        {
            int rep = 0;
            for (int j = 0;j < length;j ++)
            {
                num = longint[j];
                int temp = num - '0';
                rep = ((rep * 10 ) + temp) % basis[i];
            }
            rep = rep % basis[i];
            if(i < n-1)
                cout<<rep<<",";
            else
            cout<<rep<<")"<<endl;

        }


    }
    return 0;
}
