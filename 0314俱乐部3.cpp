#include <iostream>
#include <string>
using namespace std;


int main()
{
    int t,num;
    cin>>t;
    string a;
    int count = 0,pow = 1;
    while(t)
    {
        t--;
        cin>>num;

        if (a.size()>=num)
        {
            cout<<a[num-1];
        }
        else
        {
            for (int i = a.size();i < num;i++)
            {

                if (count == 0)
                {
                    a+='1';
                    count++;
                }
                else if (count < pow)
                {
                    a+='0';
                    count++;
                }
                else if (count == pow)
                {
                    count = 0;
                    pow++;
                    i--;
                }
            }
            cout<<a[num-1];
        }


        if(t!=0)
        cout<<" ";


    }
}
