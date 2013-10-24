#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;
int main()
{
    int dimen;
    cin>>dimen;
    int sum;
    cin>>sum;
    int weight[20];
    for (int i = 0;i < dimen;i++)
    {
        cin>>weight[i];
    }
    int result[20];
    for (int i = 0;i < dimen - 1;i++)
    {
        result[i] = weight[dimen - 2 - i] / weight[dimen - 1 - i] - 1;
    }
    result[dimen - 1] = sum / weight[0] - 1;
    for (int i = dimen - 1;i >= 0;i--)
        cout<<result[i]<<" ";
}
