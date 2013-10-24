#include <iostream>
using namespace std;
int main()
{
    int i,j;
    cin>>i>>j;
    int max = 1;
    int count = 1;
    for (int t = i ;t <= j ;t++ )
    {
        int n = t;
        count = 1;
        while (n != 1)
        {
            if (n % 2 != 0)
            {
                n = 3 * n + 1;
                count ++;
            }
            else
            {
                n = n / 2;
                count ++;
            }
        }
        if (max < count)
        max = count;

    }
    cout<<max<<endl;

}
