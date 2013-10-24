#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    int n,m;
    for (int p = 0;p < t;p++)
    {
        scanf("%d%d",&n,&m);
        int score[m][n];
        for(int i = 0;i < n;i++)
        {
            for (int j = 0;j < m;j++)
                scanf("%d",&score[j][i]);
        }
        double average;
        for (int i = 0;i < m;i++)
        {
            average = 0;
            sort(score[i],score[i]+n);
            for(int j = 1;j < n - 1;j++)
                average += score[i][j];
            average /= (n - 2) * 1.0;
            printf("%.2f\n",average);
        }
    }
}
