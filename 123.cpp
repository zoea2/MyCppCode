// source code of submission 1008254, Zhongshan University Online Judge System
#include <iostream>
using namespace std;
bool is(int num,int &j)
{
     for(j = 150;j < num;j++)
        {
            int a = j;
            int b = 0;
            while (a != 0)
            {
                b += a % 10;
                a /= 10;
                }
            if (num == j + b)
            {
                return true;
            }
        }
       return false;
       }
int main()
{
    int n;
    cin>>n;
    for (int i = 0;i < n;i++)
    {
        int num;
        cin>>num;

        int j ;
        if (is(num,j))
            cout<<j<<endl;
        else
            cout<<"0"<<endl;
            }
     return 0;
     }
