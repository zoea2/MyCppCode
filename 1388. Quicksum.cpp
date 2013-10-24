#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char a[256];
    cin.getline(a,256,'\n');
    int sum,temp;
    while (a[0] != '#')
    {

        sum = 0;
        for (int i = 0;i <strlen(a);i++)
        {
            if (a[i] != ' ')
            {
                temp = a[i] - 'A' + 1;
                sum  += (i + 1) * temp;
            }

        }
        cout<<sum<<endl;
        cin.getline(a,256,'\n');
    }
    return 0;
}
