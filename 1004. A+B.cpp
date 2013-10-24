// Problem#: 6882
// Submission#: 1759968
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cmath>
using namespace std;
string add(int base,string a,string b)
{
    int length;
    string ans;
    if (a.length() < b.length())
        length = a.length();
    else
        length = b.length();
    int carry = 0;
    for (int i = 0;i < length;i++)
    {
        int temp1,temp2;
        if (a[a.length() - 1 - i] >= '0' && a[a.length() - 1 - i]<= '9')
            temp1 = a[a.length() - 1 - i] - '0';
        else if (a[a.length() - 1 - i]>='A' && a[a.length() - 1 - i]<='Z')
            temp1 = a[a.length() - 1 - i] - 'A' + 10;
        if (b[b.length() - 1 - i] >= '0' && b[b.length() - 1 - i]<= '9')
            temp2 = b[b.length() - 1 - i] - '0';
        else if (b[b.length() - 1 - i]>='A' && b[b.length() - 1 - i]<='Z')
            temp2 = b[b.length() - 1 - i] - 'A' + 10;
        if (temp1+temp2+carry >= base)
        {
            temp1 = temp1+temp2+carry - base;
            carry = 1;
        }
        else
        {

            temp1 = temp1+temp2+carry;
            carry = 0;
        }
        if (temp1 < 10)
        ans.insert(0,1,temp1 + '0');
        else
        ans.insert(0,1,temp1 + 'A' - 10);
    }
    if (a.length() == b.length() && carry == 1)
    {
        ans.insert(0,1,'1');
    }
    else if (a.length() < b.length())
    {
        for (int i = b.length() - 1 - length;i >= 0;i--)
        {
            int temp2;
            if (b[i] >= '0' && b[i]<= '9')
                temp2 = b[i] - '0';
            else if (b[i]>='A' && b[i]<='Z')
                temp2 = b[i] - 'A' + 10;
            if (temp2+carry >= base)
            {
                temp2 = temp2+carry - base;
                carry = 1;
            }
            else
            {
                temp2 = temp2+carry;
                carry = 0;
            }
            if (temp2 < 10)
            ans.insert(0,1,temp2 + '0');
            else
            ans.insert(0,1,temp2 + 'A'-10);
        }
        if (carry == 1)
        ans.insert(0,1,'1');
    }
    else if (a.length() > b.length())
    {
        for (int i = a.length() - 1 - length;i >= 0;i--)
        {
            int temp2;
            if (a[i] >= '0' && a[i]<= '9')
                temp2 = a[i] - '0';
            else if (a[i]>='A' && a[i]<='Z')
                temp2 = a[i] - 'A' + 10;
            if (temp2+carry >= base)
            {
                temp2 = temp2+carry - base;
                carry = 1;
            }
            else
            {
                temp2 = temp2+carry;
                carry = 0;
            }
            if (temp2 < 10)
            ans.insert(0,1,temp2 + '0');
            else
            ans.insert(0,1,temp2 + 'A'-10);
        }
        if (carry == 1)
        ans.insert(0,1,'1');
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int base;
        cin>>base;
        string a,b;
        cin>>a>>b;
        cout<<add(base,a,b)<<endl;

    }
    //system("pause");
}
