#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    string n,m;
    while(t)
    {
        t--;
        string n,m;
        cin>>n>>m;
        int rep = 0;
        char num;
        if (n != m)
        {
            cout<<"NO"<<endl;
            continue;
        }
        for (int i = 0;i < n.length();i++)
        {
            num = n[i];
            rep = (rep * 10 + (num - '0')) % 11;
        }
        if (rep != 0)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;
    }
    return 0;
}
