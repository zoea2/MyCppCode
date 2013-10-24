#include <iostream>
using namespace std;
int hanoi(int n)
{
    int count = 0;
    if (n == 1)
    return 1;
    else
    {
        return (1 + hanoi(n-1) + hanoi(n-1));
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<hanoi(n);
}
