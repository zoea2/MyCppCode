#include<iostream>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        char matrix[n][n];
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < n;j++)
            {
                cin>>matrix[i][j];
            }
        }
        for (int i = 0;i < n;i++)
        {
            for (int j = n-1;j >= 0;j--)
            {
                cout<<matrix[j][i];
            }
            cout<<endl;
        }
        if (t != 0)
        cout<<endl;
    }
}
