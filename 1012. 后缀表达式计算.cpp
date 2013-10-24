#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;
int main()
{
    int t;
    cin>>t;
    string s;
    while(t--)
    {
        cin>>s;
        int i =0;
        stack<float> num;
        while (i < s.size())
        {
            if (s[i] >= 'a'&& s[i]<= 'z')
            {
                num.push(s[i] - 'a' + 1);
            }
            else if (s[i] == '+')
            {
                float temp1 = num.top();
                num.pop();
                float temp2 = num.top();
                num.pop();
                temp1 += temp2;
                num.push(temp1);
            }
            else if (s[i] == '-')
            {
                float temp1 = num.top();
                num.pop();
                float temp2 = num.top();
                num.pop();
                temp2 -= temp1;
                num.push(temp2);
            }
            else if (s[i] == '*')
            {
                float temp1 = num.top();
                num.pop();
                float temp2 = num.top();
                num.pop();
                temp2 *= temp1;
                num.push(temp2);
            }
            else if (s[i] == '/')
            {
                float temp1 = num.top();
                num.pop();
                float temp2 = num.top();
                num.pop();
                temp2 /= temp1;
                num.push(temp2);
            }
            i++;
        }
        cout<<fixed<<setprecision(2)<<num.top()<<endl;
    }
}
