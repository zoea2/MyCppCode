#include <iostream>
#include <cmath>
using namespace std;

double area(double T[3][2])
{
    double p,a,b,c;
    a = sqrt(pow((T[1][0] - T[0][0]) * 1.0,2) + pow((T[1][1] - T[0][1]) * 1.0,2));
    b = sqrt(pow((T[1][0] - T[2][0]) * 1.0,2) + pow((T[1][1] - T[2][1]) * 1.0,2));
    c = sqrt(pow((T[2][0] - T[0][0]) * 1.0,2) + pow((T[2][1] - T[0][1]) * 1.0,2));
    p = (a + b + c) / 2;
    double area1 = sqrt(p(p-a)(p-b)(p-c));
    return area1;
}
