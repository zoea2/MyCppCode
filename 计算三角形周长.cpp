#include<stdio.h>
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for (int j = 0;j < t ;j++)
    {


        double length = 0,x,y;
        double point[3][2];
        for(int i = 0;i < 3;i ++)
        {
            cin>>point[i][0]>>point[i][1];


        }
        x = pow((point[0][0] - point[1][0]) * 1.0,2) ;
        y = pow((point[0][1] - point[1][1]) * 1.0,2) ;
        double a = sqrt ((x + y) * 1.0);
        length += a;
        x =  pow((point[0][0] - point[2][0]) * 1.0 , 2);
        y =  pow((point[0][1] - point[2][1]) * 1.0 , 2) ;
        a = sqrt ((x + y) * 1.0);
        length += a;
        x = pow((point[2][0] - point[1][0]) * 1.0 , 2) ;
        y = pow((point[2][1] - point[1][1]) * 1.0 , 2) ;
        a = sqrt ((x + y) * 1.0);
        length += a;
        cout<<fixed<<setprecision(5)<<length<<endl;
    }
    return 0;
}
