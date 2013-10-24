#include <iostream>

using namespace std;
int main()
{
    int t,m;
    cin>>t>>m;
    int ans[102][1002] = {0};
    int value[m];
    int time[m];
    for (int i = 0;i < m;i++)
        cin>>time[i]>>value[i];
    for (int i = 1;i <= m;i++)
    {
        for (int j = t;j>=0;j--)
        {
            if (j >= time[i-1]&&ans[i-1][j]<ans[i-1][j-time[i-1]]+value[i-1])
            ans[i][j] = ans[i-1][j-time[i-1]]+value[i-1];
            else
            ans[i][j] = ans[i-1][j];

        }
    }
    cout<<ans[m][t]<<endl;
}
