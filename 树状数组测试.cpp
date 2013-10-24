#include <iostream>
using namespace std;
int main()
{
    int x = 20;
    x = x & (-x);
    cout<<x<<endl;
}
