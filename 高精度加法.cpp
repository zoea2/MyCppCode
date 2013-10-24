#include <iostream>
using namespace std;
string add(string a,string b)
{
    int aa,bb,temp = 0,sum;
    string result = (a.size() > b.size())? a : b;
    int length = (a.size() > b.size())? a.size() : b.size();
    int i = 0;
    for(    ;i < ((a.size() < b.size())? a.size() : b.size()) ;i++)
    {
        aa = a[a.size() - 1 - i] - '0';
        bb = b[b.size() - 1 - i] - '0';
        sum = aa + bb + temp;
        if (sum >= 10)
        {
            sum = sum - 10;
            temp = 1;
        }
        else
        temp = 0;
        result[length - 1 - i] = sum + '0';
    }
    sum = 0;
    while (i < ((a.size() > b.size())? a.size() : b.size()) && temp == 1)
    {
        sum = (result[length - 1 - i] - '0') + temp;
        if (sum >= 10)
        {
            sum = sum - 10;
            temp = 1;
        }
        else
        temp = 0;
        result[length - 1 - i] = sum + '0';
        i++;
    }
    if (temp == 1)
    result = "1" + result;
    return result;
}
int main()
{
    string a,b;
    cin>>a>>b;
    string c = add(a,b);
    cout<<c<<endl;
}
