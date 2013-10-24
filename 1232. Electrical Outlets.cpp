#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for (int i = 0;i < n;i++)
    {
        int k;
        cin>>k;
        int strip[k];
        int total = 0;
        for(int j = 0;j < k;j++)
        {
            cin>>strip[j];
            total += strip[j];
            }
         total -= k - 1;
         cout<<total<<endl;
         }
     return 0;
     }
