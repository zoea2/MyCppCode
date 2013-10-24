#include <iostream>
using namespace std;
int answer[101];
int main()
{
    int n;

    for ( ; ;)
    {
        cin>>n;
        if (n == -1)
        return 0;
        int i = 0;
        answer[0] = 2;
        answer[1] = 2;
        answer[2] = 2;
        i = 3;

        for (;i <= n;i++)
        {
            answer[i] = answer[i - 1] + answer[i - 2];

        }
        i = 0;
        cout<<answer[n]<<endl;

    }
    return 0;
}
