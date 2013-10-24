#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int homework[n][m];
    float score[n][2];
    for (int i = 0;i < n;i++)
    {
        score[i][0] = 0;
        for (int j = 0;j < m;j++)
        {
            cin>>homework[i][j];
            score[i][0] += homework[i][j];
        }
        score[i][1] = score[i][0] * 1.0 / m;
    }
    int count = 0;
    for(int i = 0;i < n; i++)
    {
        if(score[i][1] < 60)
        count ++;
        cout<<fixed<<setprecision(2)<<score[i][1]<<endl;
    }
    cout<<count<<endl;

}
