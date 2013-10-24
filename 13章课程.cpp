#include <iostream>
#include <stdio.h>
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
  this->numerator = numerator;
  this->denominator = denominator;
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
    int temp;
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
    if (denominator == secondRational.getDenominator())
    numerator += secondRational.getNumerator();
    else
    {
        denominator *= secondRational.getDenominator();
        numerator *= secondRational.getDenominator();
        numerator += secondRational.getNumerator() * secondRational.getDenominator();

    }
    while (gcd(denominator,numerator) != 1)
    {
            numerator /= gcd(denominator,numerator);
            denominator /= gcd(denominator,numerator);
    }
    return *this;
}
Rational Rational::subtract(Rational &secondRational)
{
    if (denominator == secondRational.getDenominator())
    numerator -= secondRational.getNumerator();
    else
    {
        denominator *= secondRational.getDenominator();
        numerator *= secondRational.getDenominator();
        numerator -= secondRational.getNumerator() * secondRational.getDenominator();

    }
    while (gcd(denominator,numerator) != 1)
    {
            numerator /= gcd(denominator,numerator);
            denominator /= gcd(denominator,numerator);
    }
    return *this;
}
Rational Rational::multiply(Rational &secondRational)
{
    denominator *= secondRational.getDenominator();
    numerator *= secondRational.getNumerator();
    while (gcd(denominator,numerator) != 1)
    {
            numerator /= gcd(denominator,numerator);
            denominator /= gcd(denominator,numerator);
    }
    return *this;
}
Rational Rational::divide(Rational &secondRational)
{
    denominator *= secondRational.getNumerator();
    numerator *= secondRational.getDenominator();
    while (gcd(denominator,numerator) != 1)
    {
            numerator /= gcd(denominator,numerator);
            denominator /= gcd(denominator,numerator);
    }
    return *this;
}
int Rational::compareTo(Rational &secondRational)
{
    if (denominator == secondRational.getDenominator())
    {
        if(numerator == secondRational.getNumerator())
        return 0;
        else if (numerator > secondRational.getNumerator())
        return 1;
        else
        return -1;
    }
    else
    {
        long newd = denominator * secondRational.getDenominator();
        long newn = numerator * secondRational.getDenominator();
        if (newn == secondRational.getNumerator()* secondRational.getDenominator())
        return 0;
        else if (newn > secondRational.getNumerator()* secondRational.getDenominator())
        return 1;
        else
        return -1;
    }
}
bool Rational::equals(Rational &secondRational)
{
    if (compareTo(secondRational) == 0)
    return true;
    return false;
}
int Rational::intValue() //Returns the numerator/denominator
{
    return numerator/denominator;
}
double Rational::doubleValue() //Returns 1.0*numberator/denominator
{
    double temp =  numerator/denominator;
    return temp;
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
