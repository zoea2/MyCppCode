#include <iostream>
using namespace std;
bool bigger(int number[],int n)
{
    for(int k = 1;k < n ;k++)
    {
        if (number[0] < number[k])
        return true;
    }
    return false;
}
int main()
{
    int t;
    cin>>t;
    int n,m;
    for (int p = 0;p < t;p++)
    {
        cin>>n>>m;
        int number[n];
        for(int i = 0;i < n;i ++)
            cin>>number[i];
        int count = 0;
        while (number[m] != 0)
        {
            if(bigger(number,n))
            {
                int temp = number[0];
                for (int j = 0;j < n - 1; j ++)
                {
                    number[j] = number[j+1];
                }
                number[n - 1] = temp;

                if (m == 0)
                    m = n - 1;
                else
                m = m - 1;


            }
            else
            {
                number[0] = 0;
                count++;
            }

        }
        cout<<count<<endl;
    }
    return 0;
}
