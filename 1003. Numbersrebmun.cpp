#include <iostream>
#include <cctype>
using namespace std;
bool isP(string a)
{
    for (int i = 0;i < a.length() / 2;i++)
    {
        if (a[i] != a[a.length() - i - 1])
        return false;
    }
    return true;
}
int main()
{
    int t;
    string name;
    cin>>t;
    while(t)
    {
        t--;
        cin>>name;
        for (int i = 0;i < name.length();i++)
        {
            name[i] = tolower(name[i]);
            if (name[i] <= 'c')
                name[i] = '2';
            else if (name[i] <= 'f')
                name[i] = '3';
            else if (name[i] <= 'i')
                name[i] = '4';
            else if (name[i] <= 'l')
                name[i] = '5';
            else if (name[i] <= 'o')
                name[i] = '6';
            else if (name[i] <= 's')
                name[i] = '7';
            else if (name[i] <= 'v')
                name[i] = '8';
            else
                name[i] = '9';
        }
        if (isP(name))
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;

    }
}
