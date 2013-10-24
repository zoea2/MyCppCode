#include <iostream>
using namespace std;
int main()
{
    string code;
    cin>>code;
    while (code != "0")
    {
        int num[3] = {1,1,1};
        for (int i = 1;i < code.length();i++)
        {
            num[0] = num[1];
            num[1] = num[2];
            if (code[i] == '0')
            num[2] = num[0];
            else if (code[i-1] == '1' ||(code[i-1] == '2'&&code[i]<='6'))
            num[2] = num[0] + num[1];
            else
            num[2] = num[1];
        }
        cout<<num[2]<<endl;
        cin>>code;
    }
}
