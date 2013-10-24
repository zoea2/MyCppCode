#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        string a;
        cin>>a;
        int score = 0;
        int total = 0;
        int m = a.length();
        for (int j = 0;j < m;j++)
        {
            if (a[j] == 'O' && a[j - 1] == 'O')
            {
                score += 1;
                total += score;
            }
            else if (a[j] == 'O' && a[j - 1] != 'O')
            {
                score = 1;
                total += 1;
            }



                }
        cout<<total<<endl;
    }
}
