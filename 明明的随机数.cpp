#include <iostream>
using namespace std;
bool Nequal (int num[],int number[],int count,int j)
{
    for(int t = 0; t < count;t++)
    {
        if (num[t] == number[j])
        return false;
    }
    return true;
}
int main()
{
    for (int i = 0;i < 10;i++)
    {
        int n;
        cin >> n;
        int number[n];
        int num[n];
        for (int j = 0; j < n ; j++)
            cin>>number[j];
        num[0] = number[0];
        int count = 1;
        for (int j = 1;j < n;j++)
        {
            if (Nequal(num,number,count,j))
            {
                num[count] = number[j];
                count ++;
            }
        }
        for (int j = 0;j < count ;j ++)
        {
            for (int t = j + 1;t < count;t++)
            {
                if (num[j] > num[t])
                {
                    int temp = num[j];
                    num[j] = num [t];
                    num[t] = temp;
                }
            }
        }
        cout<<count<<endl;
        for(int j = 0;j < count; j++)
        {
             cout<<num[j];
             if (j != count - 1)
             cout<<" ";
             else
             cout<<endl;

        }

    }
    return 0;
}
