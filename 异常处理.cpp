#include <cstring>
#include <cmath>
#include <stdexcept>
#include <iostream>
using namespace std;
// Problem#: 5167
// Submission#: 1322639
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;
class IllegalSubscriptException:public runtime_error
{
    public:
    IllegalSubscriptException()
    :runtime_error("Illegal Subscript Exception")
    {
        ;
    }
};
class Date
{
public:
  Date(int y=0, int m=1, int d=1)
  {
           year = y;
           month = m;
           date = d;
           }
  static bool leapyear(int year)
  {
         if ((year % 4 == 0 && year % 100 != 0 )|| year % 400 == 0)
         return true;
         return false;
         }
  int getYear() const
  {
      return year;
      }
  int getMonth() const
  {
      return month;
      }
  int getDay() const
  {return date;}
  bool operator<(Date d)
  {
       if (year < d.getYear())
       return true;
       else if (year == d.getYear())
       {
            if (month < d.getMonth())
            return true;
            else if (month == d.getMonth())
            {
                 if (date < d.getDay())
                 return true;}
                 }
       return false;
       }
   bool operator>(Date d)
  {
       if (year > d.getYear())
       return true;
       else if (year == d.getYear())
       {
            if (month > d.getMonth())
            return true;
            else if (month == d.getMonth())
            {
                 if (date > d.getDay())
                 return true;}
                 }
       return false;
       }
  bool operator== (Date d)
  {
       if (year == d.getYear())
       {
                if (month == d.getMonth())
                {
                          if  (date == d.getDay())
                          return true;
                          }
                          }
        return false;
        }
   bool operator<= (Date d)
   {
        return (*this < d || *this == d);
        }
   bool operator>= (Date d)
   {
        return (*this > d || *this == d);
        }
   bool operator!= (Date d)
   {
        return !(*this == d);
        }
   int& operator[] (const string &s)
   {
         if (s == "year")
         return this->year;
         if (s == "month")
         return month;
         if (s == "day")
         return date;
         else
         throw IllegalSubscriptException();
         }

   Date operator++()
   {
             if (leapyear(year) && month == 2)
             {
                                if (date == 29)
                                {
                                         month = 3;date = 1;
                                         }
                                else
                                date++;
                                }
             else if(month == 2 )
             {
                  if (date == 28)
                  {month = 3;date = 1;}
                  else
                  date++;
                  }
             else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 )
             {
                  if ( date == 31)
                  {month++;date = 1;}
                  else
                  date++;
                  }
             else if (month == 4 || month == 6 || month == 9 || month == 11)
             {
                  if (date == 30)
                  {month++;date = 1;}
                  else
                  {date++;}
                  }
             else if (month == 12)
             {
                  if (date == 31)
                  {year++;month = 1;date = 1;}
                  else
                  date++;
                  }
             return *this;
   }
   Date operator++ (int d)
   {
         Date temp(year,month,date);
         if (leapyear(year) && month == 2)
             {
                                if (date == 29)
                                {
                                         month = 3;date = 1;
                                         }
                                else
                                date++;
                                }
             else if(month == 2 )
             {
                  if (date == 28)
                  {month = 3;date = 1;}
                  else
                  date++;
                  }
             else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 )
             {
                  if ( date == 31)
                  {month++;date = 1;}
                  else
                  date++;
                  }
             else if (month == 4 || month == 6 || month == 9 || month == 11)
             {
                  if (date == 30)
                  {month++;date = 1;}
                  else
                  {date++;}
                  }
             else if (month == 12)
             {
                  if (date == 31)
                  {year++;month = 1;date = 1;}
                  else
                  date++;
                  }
             return temp;
             }
   Date operator--()
   {
        if (leapyear(year) && month == 3)
             {
                                if (date == 1)
                                {
                                         month = 2;date = 29;
                                         }
                                else
                                date--;
                                }
             else if(month == 3)
             {
                  if (date == 1)
                  {month = 2;date = 28;}
                  else
                  date--;
                  }
             else if (month == 12 || month == 5 || month == 7 || month == 10 )
             {
                  if ( date == 1)
                  {month--;date = 30;}
                  else
                  date--;
                  }
             else if (month == 4 || month == 6 || month == 9 || month == 11||month == 2||month == 8)
             {
                  if (date == 1)
                  {month--;date = 31;}
                  else
                  {date--;}
                  }
             else if (month == 1)
             {
                  if (date == 1)
                  {year--;month = 12;date = 31;}
                  else
                  date--;
                  }
             return *this;
   }
   Date operator--(int d)
   {
        Date temp(year,month,date);
        if (leapyear(year) && month == 3)
             {
                                if (date == 1)
                                {
                                         month = 2;date = 29;
                                         }
                                else
                                date--;
                                }
             else if(month == 3)
             {
                  if (date == 1)
                  {month = 2;date = 28;}
                  else
                  date--;
                  }
             else if (month == 12 || month == 5 || month == 7 || month == 10 )
             {
                  if ( date == 1)
                  {month--;date = 30;}
                  else
                  date--;
                  }
             else if (month == 4 || month == 6 || month == 9 || month == 11||month == 2||month == 8)
             {
                  if (date == 1)
                  {month--;date = 31;}
                  else
                  {date--;}
                  }
             else if (month == 1)
             {
                  if (date == 1)
                  {year--;month = 12;date = 31;}
                  else
                  date--;
                  }
             return temp;
   }
   Date operator+(int d)
   {
       Date temp = Date (*this);
       if (d > 0)
       {
             for (int i = 0;i < d;i++)
             temp++;
       }
       else{
             for (int i = 0;i < -d;i++)
             temp--;
       }

       return temp;
   }
    Date operator-(int d)
   {
       Date temp = Date (*this);
       if (d > 0)
       {
             for (int i = 0;i < d;i++)
             temp--;
       }
       else{
             for (int i = 0;i < -d;i++)
             temp++;
       }

       return temp;
   }
   Date operator+= (int d)
   {

       if (d > 0)
       {
             for (int i = 0;i < d;i++)
             (*this)++;
       }
       else{
             for (int i = 0;i < -d;i++)
             (*this)--;
       }
       return *this;
   }
   Date operator-= (int d)
   {
       if (d > 0)
       {
             for (int i = 0;i < d;i++)
             (*this)--;
       }
       else{
             for (int i = 0;i < -d;i++)
             (*this)++;
       }
       return *this;
   }
   friend ostream &operator<<(ostream & stream, Date &d)
   {
           stream<<d.year<<"-"<<d.month<<"-"<<d.date;
           return stream;
          }

  // add any member you need here
  private:
          int year,month,date;
};
