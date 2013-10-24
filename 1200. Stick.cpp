#include<iostream>
#include <algorithm>
using namespace std;
int main()
{
    for (int p = 0;p < 100;p++)
    {
        int n;
        cin>>n;
        if (n == 0)
            return 0;
        int length[n];
        for (int i = 0;i < n;i++)
            cin>>length[i];
        sort(length,length + n);
        for (int j = 0;j < n; j += 2)
        {
            if (length[j] != length[j+1])
            {
                cout<<length[j]<<endl;
                break;
            }
        }
    }
    return 0;
}
