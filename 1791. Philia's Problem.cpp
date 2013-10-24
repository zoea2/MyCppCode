#include <iostream>
#include <cstdio>
using namespace std;
int getweekdays(int year, int m, int d)
{
    if(m==1 || m==2 )
    {
        m+=12;
        --year;
    }
    return (d+2*m+3*(m+1)/5+year + year/4-year/100+year/400)%7;
}
int main()
{
    int t;
    cin>>t;
    while (t)
    {
        t--;
        int m,d,year,days,week;
        cin>>m>>d>>year;
        week=getweekdays(year,m,d);
        if(week == 6)
        {
            week = 7 ;
        }
        else
        {
            week = 6 - week;
        }
        if(m == 2)
        {
            if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
            {
                if (week > 29 - d)
                {
                    m = 3;
                    d = week - (29 - d);
                }
                else
                d += week;
            }
            else
            {
                if(week > 28 - d)
                {
                    m = 3;
                    d = week - (28 - d);
                }
                else
                d += week;
            }
        }
        else if(m == 12)
        {
            if (week > 31 - d)
                {
                    m = 1;
                    d = week - (31 - d);
                    year++;
                }
                else
                d += week;
        }
        else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 )
        {
            if (week > 31 - d)
                {
                    m++;
                    d = week - (31 - d);
                }
                else
                d += week;
        }
        else if (m == 4 || m == 6 || m == 9 || m == 11)
        {
            if (week > 30 - d)
                {
                    m++;
                    d = week - (30 - d);
                }
                else
                d += week;
        }
        printf("%02d %02d %d\n",m, d, year);
    }
}
