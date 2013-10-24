#include <iostream>
#include <stdio.h>
using namespace std;
bool haveAnswer(int &j,int a,int b,int c)
{
    for ( ;j <= 100;j++)
    {
            if((j % 3 == a) && (j % 5 == b) && (j % 7 == c))
            {
                return true;
            }
    }
    return false;
}
int main()
{
    int t;
    scanf("%d",&t);
    for (int i = 0;i < t;i ++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int j = 10;
        if(haveAnswer(j,a,b,c))
            printf("%d\n",j);
        else
            printf("No answer\n");

    }
    return 0;
}
