
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
using namespace std;
class Rational
{
public:
  Rational();
  Rational(long numerator, long denominator);
  long getNumerator();
  long getDenominator();
  Rational add(Rational &secondRational);
  Rational subtract(Rational &secondRational);
  Rational multiply(Rational &secondRational);
  Rational divide(Rational &secondRational);
  /* Returns an int value -1, 0, or 1 to indicate whether this rational
     number is less than, equal to, or greater than the specified number.
  */
  int compareTo(Rational &secondRational);
  bool equals(Rational &secondRational);
  int intValue(); //Returns the numerator/denominator
  double doubleValue(); //Returns 1.0*numberator/denominator
  string toString();
  bool operator<(Rational &secondRational)
  {
      return (this->compareTo(secondRational) < 0);
  }
  bool operator<=(Rational &secondRational)
  {
      return (this->compareTo(secondRational) <= 0);
  }
  bool operator>(Rational &secondRational)
  {
      return (this->compareTo(secondRational) > 0);
  }
    bool operator>=(Rational &secondRational)
  {
      return (this->compareTo(secondRational) >= 0);
  }
  bool operator!= (Rational &secondRational)
  {
      return (this->compareTo(secondRational) != 0);
  }
  bool operator== (Rational &secondRational)
  {
      return (this->compareTo(secondRational) == 0);
  }
    Rational operator+(Rational &secondRational)
    {
        return this->add(secondRational);
    }
    Rational operator-(Rational &secondRational)
    {
        return this->subtract(secondRational);
    }
    Rational operator*(Rational &secondRational)
    {
        return this->multiply(secondRational);
    }
    Rational operator/ (Rational &secondRational)
    {
        return this->divide(secondRational);
    }
    Rational operator+=(Rational &secondRational)
    {
        *this = this->add(secondRational);
        return (*this);
    }
    Rational operator-=(Rational &secondRational)
    {
        *this = this->subtract(secondRational);
        return (*this);
    }
    Rational operator*=(Rational &secondRational)
    {
        *this = this->multiply(secondRational);
        return (*this);
    }
    Rational operator/= (Rational &secondRational)
    {
        *this = this->divide(secondRational);
        return (*this);
    }
    long& operator[](const int &index)
    {
        if (index == 0)
        return numerator;
        else if (index == 1)
        return denominator;    }
     Rational operator++()
     {
         numerator += denominator;
         return (*this);
     }
     Rational operator--()
     {
         numerator -= denominator;
         return (*this);
     }
     Rational operator++(int dummy)
     {
         Rational temp (numerator,denominator);
         numerator += denominator;
         return temp;
     }
     Rational operator--(int dummy)
     {
         Rational temp (numerator,denominator);
         numerator -= denominator;
         return temp;
     }
     Rational operator+()
     {
         return (*this);
     }
     Rational operator-()
     {
         numerator *= -1;
         return *this;
     }
        friend ostream &operator<<(ostream &stream, Rational &rational);
        friend istream &operator>>(istream &stream, Rational &rational);


private:
  long numerator; //分子.
  long denominator; //分母，不能为0.
  static long gcd(long n, long d);
};
Rational::Rational()
{
  numerator = 0;
  denominator = 1;
}
Rational::Rational(long numerator, long denominator)
{

    long temp = gcd(numerator,denominator);
    this->numerator = numerator / temp * ((denominator > 0)? 1 : -1);
    this->denominator = denominator / temp;
}
long Rational::getNumerator()
{
    return numerator;
}
long Rational::getDenominator()
{
    return denominator;
}
long Rational::gcd(long n, long d)
{
    long temp;
    n = abs(n);
    d = abs(d);
    while (d != 0)
    {
        temp = n % d;
        n = d;
        d = temp;
    }
    return n;
}
Rational Rational::add(Rational &secondRational)
{
    long n =  numerator * secondRational.getDenominator() + secondRational.getNumerator() * denominator;
    long d =  denominator * secondRational.getDenominator();
    long temp = gcd(n,d);
    n = n / temp * ((d > 0) ? 1: -1);
    d = d / temp;
    return Rational(n,d);
}
Rational Rational::subtract(Rational &secondRational)
{
    long n =  numerator * secondRational.getDenominator() - secondRational.getNumerator() * denominator;
    long d =  denominator * secondRational.getDenominator();
    long temp = gcd(n,d);
    n = n / temp * ((d > 0) ? 1: -1);
    d = d / temp;
    return Rational(n,d);

}
Rational Rational::multiply(Rational &secondRational)
{
    long d = denominator * secondRational.getDenominator();
    long n = numerator * secondRational.getNumerator();
    long temp = gcd(n,d);
    n = n / temp * ((d > 0) ? 1: -1);
    d = d / temp;
    return Rational(n,d);
}
Rational Rational::divide(Rational &secondRational)
{
    long d = denominator * secondRational.getNumerator();
    long n = numerator * secondRational.getDenominator();
    long temp = gcd(n,d);
    n = n / temp * ((d > 0) ? 1: -1);
    d = d / temp;
    return Rational(n,d);
}
int Rational::compareTo(Rational &secondRational)
{
    Rational temp = this->subtract(secondRational);
    if (temp.getNumerator() < 0)
    return -1;
    else if (temp.getNumerator() == 0)
    return 0;
    else
    return 1;
}
bool Rational::equals(Rational &secondRational)
{
    if (compareTo(secondRational) == 0)
    return true;
    return false;
}
int Rational::intValue()
{
    if (denominator == 0)
    return numerator;
    return numerator/denominator;
}
double Rational::doubleValue()
{
       if (denominator == 0)
       return numerator * 1.0;
       return 1.0 * numerator / denominator;
}
string Rational::toString()
{
  char s[50];
  if ( denominator == 1) {
    sprintf(s,"%ld",numerator);
  } else {
    sprintf(s,"%ld/%ld",numerator,denominator);
  }
  return string(s);

}
  ostream& operator<<(ostream &stream, Rational &rational)
{
  cout << rational.toString();
  return stream;
    }
    istream& operator>>(istream &stream,Rational &rational )
    {
        stream>>rational.numerator>>rational.denominator;
        return stream;
    }

int main()
{
    Rational r1 = Rational(0,3);
    Rational r2 = Rational (2,10);
    cout<<(r1-r2).toString()<<endl;
    cout<<(++r1).toString();
}
