#include <iostream>
using namespace std;
int main()
{
    string code;
    while(cin>>code)
    {
        int count = 10;
        int ans = 0;
        for (int i = 0;i < code.length();i++)
        {
            if(code[i] == '-')
            continue;
            else
            {
                ans += count * (code[i]-'0');
                count--;
            }
        }
        ans = 11 - (ans % 11);
        if (ans == 10)
        cout<<code<<"-X"<<endl;
        else if (ans == 11)
        cout<<code<<"-0"<<endl;
        else
        cout<<code<<"-"<<ans<<endl;
    }
}
