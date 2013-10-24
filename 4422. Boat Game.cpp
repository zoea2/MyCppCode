#include <iostream>
using namespace std;
int main()
{
    int t,n,m,appNum,boat[2],count,pace;
    cin>>t;
    while (t)
    {
        t--;
        cin>>n>>m>>appNum;
        int app[appNum];
        for (int i = 0;i < appNum;i++)
            cin>>app[i];
        boat[0] = 0;
        boat[1] = m - 1;
        count = 0;
        for (int i = 0;i < appNum;i++)
        {
            if (app[i] - 1 < boat[0])
            {
                pace = boat[0] - (app[i] - 1);
                count += pace;
                boat[0] -= pace ;
                boat[1] -= pace;
            }
            else if (app[i] - 1 > boat[1])
            {
                pace = app[i] - 1 - boat[1];
                count += pace;
                boat[0] += pace;
                boat[1] += pace;
            }
        }
        cout<<count<<endl;
     }
}
