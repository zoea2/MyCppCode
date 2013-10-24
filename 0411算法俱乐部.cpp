#include <iostream>
#include <queue>
#include <cmath>
#include <iomanip>
#include <stdio.h>
using namespace std;

int main()
{
    int nail;
    double radius;
    cin>>nail>>radius;
    double dis = 3.141592653 * 2 * radius;
    double point[102][2];
    for (int i = 0;i < nail;i++)
    cin>>point[i][0]>>point[i][1];
    if (nail == 1)
    {
        printf("%.2f",3.141592653 * 2 * radius);
        cout<<endl;
        return 0;
    }
    for (int i = 0;i < nail - 1;i++)
    {
        dis += sqrt((point[i+1][0] - point[i][0]) *(point[i+1][0] - point[i][0]) + (point[i+1][1] - point[i][1])*(point[i+1][1] - point[i][1]));

    }
    dis += sqrt((point[0][0] - point[nail-1][0]) *(point[0][0] - point[nail-1][0]) + (point[0][1] - point[nail-1][1])*(point[0][1] - point[nail-1][1]));


    printf("%.2f",dis);
    cout<<endl;

}
