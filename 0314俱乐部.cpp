#include <iostream>
using namespace std;
int main()
{
    int num;
    cin<<num;
    if (num>= 1 && num <= 4)
    cout<<"few";
    else if (num > 4 && num <= 9 )
    cout<<"several";
    else if(num>9&&num<=19)
    cout<<"pack";
    else if (num > 19&&num <=49)
    cout<<"lots";
    else if(num > 49&&num<=99)
    cout<<"horde";
    else if(num>99&&num<=249)
    cout<<"throng";
    else if(num>249&&num<499)
    cout<<"swarm";
    else if(num>499&&num<=999)
    cout<<"zounds";
    else if (num==1000)
    cout<<"legion";
}
