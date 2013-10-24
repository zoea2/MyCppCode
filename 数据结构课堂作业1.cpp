#include <iostream>
using namespace std;
class Birthday
{
      public:
      int daysFromNextBirthday(int year, int month, int day)
      {
          int count = 0;
          int m[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
          if (month == 3 )
          {
                    if (day < 8)
                    return 8 - day;
                    if (day >= 8)
                    {
                        if ((year + 1) % 100 == 0)
                        {
                                if ((year + 1 ) % 400 == 0)
                                return 366-(day-8);
                        }
                        else if ((year + 1) % 4 == 0)
                        return 366-(day-8);
                        return 365-(day-8);
                    }
          }
          else
          {
            int i = month;
            while (i != 2)
            {
                        count += m[i-1];
                        i++;
                        if (i == 13)
                        i = 1;
            }
            if (month>3)
            {
                if ((year + 1) % 100 == 0)
                    {
                            if ((year + 1 ) % 400 == 0)
                            count+=29;
                            else
                            count += 28;

                    }
                          else if ((year + 1) % 4 == 0)
                          count+=29;
                          else
                          count+=28;
                          count+=8;
                          count -= day;
              }
              else if (month != 2)
              {
                   if ((year) % 100 == 0)
                    {
                                      if ((year) % 400 == 0)
                                      count+= 29;
                                      else
                                      count += 28;

                    }
                    else if (year % 4 == 0)
                    count+= 29;
                    else
                    count+=28;
                    count+=8;
                    count -= day;
              }
              else if (month == 2)
              {
                        if ((year) % 100 == 0)
                        {
                                      if (year % 400 == 0)
                                      count+=29;
                                      else
                                      count += 28;
                        }
                        else if ((year) % 4 == 0)
                        count+=29;
                        else
                        count+=28;
                        count -= day;
                        count+=8;
              }
          }
          return count;
      }

};
int main()
{
    int y,m,d;
    cin>>y>>m>>d;
    Birthday a;
    cout<<a.daysFromNextBirthday(y,m,d);

}
