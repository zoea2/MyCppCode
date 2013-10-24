#include <iostream>

using namespace std;
int main()
{
    int t,n,num;
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        string number;
        int count[10] = {0,0,0,0,0,0,0,0,0,0};
        char temp;
        for (int i = 1;i <= n;i++)
        {
            num = i;
            while (num != 0)
            {
                temp = (num % 10) + '0';
                number += temp;
                num /= 10;
            }
        }
        for (int i = 0;i < number.length();i++)
        {
            int temp1;
            temp1 = number[i] - '0';
            count[temp1]++;
        }
        cout<<count[0];
        for (int i = 1;i < 10;i++)
            cout<<" "<<count[i];
        cout<<endl;

    }

}
