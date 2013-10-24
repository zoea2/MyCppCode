#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    double point[4];
    for (int i = 0;i < n;i++)
    {
        for(int j = 0;j < 4;j++)
            cin>>point[j];
        double x = point[2] - point[0];
        double y = point[3] - point[1];
        double length = sqrt(x * x + y * y);
        cout<<fixed<<setprecision(2)<<length<<endl;

    }
    return 0;
}
