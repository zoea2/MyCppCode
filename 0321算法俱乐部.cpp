#include <iostream>

using namespace std;
int main()
{
    int count1 = 0,count2 = 0;
    string str;
    char a[10001];
    int count = 0;
    while(cin.zz)
    {
        ;
    }
    cout<<a<<endl;
    str = a;
    for (int i = 0;i < str.length();i++)
    {
        if (str.find("tram",i) != -1)
        {
            if (str[str.find("tram",i)+4] == ' ')
            {
                count1++;
            }
            i = str.find("tram",i)+3;
        }
        else
        break;
    }
    for (int i = 0;i < str.length();i++)
    {
        if (str.find("trolleybus",i) != -1)
        {
            if (str[str.find("trolleybus",i)+10] == ' ')
            {
                count2++;
            }
            i = str.find("trolleybus",i)+9;
        }
        else
        break;
    }

    if (count1 > count2)
    cout<<"Tram driver";
    else if (count1 < count2)
    cout<<"Trolleybus driver";
    else
    cout<<"Bus driver";
}
