#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for (int i = 0;i < t;i++)
    {
        string number;
        cin>>number;
        int length = number.length();
        int num = 0;
        for (int j = 0;j < length ;j++)
        {
            num += pow(2.0,j) * (number[length - 1 - j] - '0');
        }
        printf("%d\n",num);
    }
    return 0;
}
