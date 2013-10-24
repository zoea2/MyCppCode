#include <iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
int boy[1000];
int girl[1000];
int main()
{
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n;
        cin>>n;
        for (int i = 0;i < n;i++)
            cin>>boy[i];
        for (int i = 0;i < n;i++)
            cin>>girl[i];
        sort(boy,boy+n);
        sort(girl,girl+n);
        int count = 0;
        for (int i = n-1;i >= 0;i--)
        {
            if (boy[i] == 0)
            continue;
            if (boy[i] > 0)
            {
                for (int j = 0;j < n;j++)
                {
                    if (girl[j] > 0)
                        continue;
                    else if (girl[j] == 0)
                        continue;
                    else if (abs(boy[i]) == abs(girl[j]))
                        continue;
                    else if(abs(boy[i]) < abs(girl[j]))
                    {
                        count++;
                        girl[j] = 0;
                        break;
                    }
                }

            }
            if (boy[i] < 0)
            {
                for (int j = 0;j < n;j++)
                {
                    if (girl[j] < 0)
                        continue;
                    else if (girl[j] == 0)
                        continue;
                    else if (abs(boy[i]) == abs(girl[j]))
                        continue;
                    else if(abs(boy[i]) > abs(girl[j]))
                    {
                        count++;
                        girl[j] = 0;
                        break;
                    }
                }
            }

       }
        cout<<count<<endl;
    }
    return 0;
}
