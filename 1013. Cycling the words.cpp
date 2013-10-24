#include <iostream>
using namespace std;
int main()
{
    int count = 0;
    int count1 = 0;
    string a[100];
    while(cin>>a[count])
    {
        count++;
    }
    for (int i = 0;i < count;i++)
    {
        cout<<a[i];
        if (i != count - 1)
            cout<<' ';
    }
    cout<<endl;
    for (int i = 0;i < count-1;i++)
    {
        for (int j = i + 1;count1 <count;count1++)
        {
            cout<<a[j];
            if (count1 != count - 1)
            cout<<' ';
            if (j == count - 1)
            j = -1;
            j++;
        }

            cout<<endl;
        count1 = 0;
    }
}
