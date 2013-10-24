#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int n;
    while(t)
    {
       t--;
       cin>>n;
       if (n == 1)
       {
           cout<<"0 1 0 0 0 0 0 0 0 0"<<endl;
           break;
       }
       string num = "1";
        char temp;
        int m;
       for (int i = 2;i <= n;i++)
    {
        m = i;
        while(m != 0)
        {
            temp = (m % 10) + '0';
            num += temp;
            m /= 10;
        }

    }

       int count[10] = {0,0,0,0,0,0,0,0,0,0};

       for (int i = 0;i < num.length();i++)
       {
           if (num[i] == '0')
           count[0]++;
           else if (num[i] == '1')
           count[1]++;
           else if (num[i] == '2')
           count[2]++;
           else if (num[i] == '3')
           count[3]++;
           else if (num[i] == '4')
           count[4]++;
           else if (num[i] == '5')
           count[5]++;
           else if (num[i] == '6')
           count[6]++;
           else if (num[i] == '7')
           count[7]++;
           else if (num[i] == '8')
           count[8]++;
           else if (num[i] == '9')
           count[9]++;
       }
       for(int i = 0;i < 9;i++)
       cout<<count[i]<<" ";
       cout<<count[9]<<endl;
    }
    return 0;
}
