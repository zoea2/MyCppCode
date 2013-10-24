#include <iostream>
using namespace std;
bool a(int &i,int n)
{
    int sum;
    int temp;
    if (n <= 100)
    {
        for (i = 1;i < n;i++)
        {
            sum = 0;
            temp = i;
            while (temp != 0)
            {

                sum += (temp % 10);
                temp /= 10;
            }
            if(sum + i == n)
            {
                return true;
            }
        }
        return false;
    }
    else
    {
        for (i = n - 100;i < n;i++)
        {
            sum = 0;
            temp = i;
            while (temp != 0)
            {

                sum += (temp % 10);
                temp /= 10;
            }
            if(sum + i == n)
            {
                return true;
            }
        }
        return false;
    }
}
int main()
{
    int t,n;
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        int count = 0;
        if (a(count,n))
        cout<<count<<endl;
        else
        cout<<"0\n";


    }
}
