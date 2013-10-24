#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int count1 = 40 + 2 * b;
    int count2 = 2 * a + 39;
    if (count1 > count2)
    cout<<count1;
    else
    cout<<count2;
}
