#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int t,i;
    cin>>t;
    string s;
    stack<char> ope;
    while(t--)
    {
        while (!ope.empty())
        {
            ope.pop();
        }
        cin>>s;
        i = 0;
        while(i < s.size())
        {
            if (s[i] != '{'&&s[i] != '}'&&s[i] != '['&&s[i] != ']'&&s[i] != '('&&s[i] != ')')
            {
                i++;
            }
            else
            {
                if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                {
                    ope.push(s[i]);

                }
                else if (s[i] == ')')
                {
                    if (ope.empty() || ope.top()!= '(')
                    {
                        cout<<"No"<<endl;
                        break;
                    }
                    else
                    ope.pop();
                }
                else if (s[i] == ']')
                {
                    if (ope.empty() ||ope.top() != '[')
                    {
                        cout<<"No"<<endl;
                        break;
                    }
                    else
                    ope.pop();

                }
                else if (s[i] == '}')
                {
                    if (ope.empty() ||ope.top() != '{')
                    {
                        cout<<"No"<<endl;
                        break;
                    }
                    else
                    ope.pop();
                }
                i++;
            }
        }
        if (i == s.size())
        {
            if (ope.empty())
            cout<<"Yes"<<endl;
            else
            cout<<"No"<<endl;
        }
    }
}
