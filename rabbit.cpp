#include <iostream>
using namespace std;
string answer[101];
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
    int m,d;

    for ( ; ;)
    {
        cin>>m>>d;
        if (m == 0 && d == 0)
        return 0;
        int i = 0;
        for (;i < m;i++)
        {
            int temp = i+1;

            char temp1[2];
            answer[i] = "\0";
            while (temp != 0)
            {
                temp1[0] = (temp % 10) + '0';
                temp1[1] = '\0';
                answer[i] = temp1 + answer[i];
                temp /= 10;
            }

        }

        for (;i <= d;i++)
        {
            answer[i] = add(answer[i - 1],answer[i - m]);

        }
        i = 0;
        cout<<answer[d]<<endl;

    }
    return 0;
}
