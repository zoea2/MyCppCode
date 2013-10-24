#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int t ;
    scanf("%d",&t);
    for (int i = 0;i < t;i++)
    {
        int m,d;
        scanf("%d%d",&m,&d);
        int total;
        if (m == 1)
            total = d;
        else if (m == 2)
            total = 31 + d;
        else if (m == 3)
            total = 59 + d;
        else if (m == 4)
            total = 90 + d;
        else if (m == 5)
            total = 120 + d;
        else if (m == 6)
            total = 151 + d;
        else if (m == 7)
            total = 181 + d;
        else if (m == 8)
            total = 212 + d;
        else if (m == 9)
            total = 243 + d;
        else if (m == 10)
            total = 273 + d;
        else if (m == 11)
            total = 304 + d;
        else if (m == 12)
            total = 334 + d;
        if (total % 7 == 1)
            printf("Saturday\n");
        else if (total % 7 == 2)
            printf("Sunday\n");
        else if (total % 7 == 3)
            printf("Monday\n");
        else if (total % 7 == 4)
            printf("Tuesday\n");
        else if (total % 7 == 5)
            printf("Wednesday\n");
        else if (total % 7 == 6)
            printf("Thursday\n");
        else if (total % 7 == 0)
            printf("Friday\n");

    }
    return 0;

}
