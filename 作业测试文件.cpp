// Problem#: 6011
// Submission#: 1518610
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stack>
#include <iostream>
using namespace std;
int main()
{
    string exp;
    stack<char> oper;
    int i;
    oper.push('#');
    int t;
    cin>>t;
    while(t--)
    {
        cin>>exp;
        i = 0;
        while(i < exp.size())
        {
            if (exp[i] >= 'A'&& exp[i] <= 'Z'||exp[i] >= 'a'&& exp[i] <= 'z')
                cout<<exp[i];
            else
            {

                if (exp[i] == '(')
                    oper.push(exp[i]);
                else if (exp[i] == '+' || exp[i] == '-')
                {

                    if (oper.top()!= '#'&&oper.top()!= '(')
                    {
                        cout<<oper.top();
                        oper.pop();
                        continue;
                    }
                    else
                    oper.push(exp[i]);
                }
                else if (exp[i] == '*' || exp[i] == '/')
                {
                    if (oper.top() == '*' || oper.top() == '/')
                    {
                        cout<<oper.top();
                        oper.pop();
                        continue;
                    }
                    else
                    oper.push(exp[i]);
                }
                else if (exp[i] == ')')
                {
                    if (oper.top() == '(')
                        oper.pop();
                    else
                    {
                        cout<<oper.top();
                        oper.pop();
                        continue;
                    }

                }
            }
            i++;

        }
        while (oper.top()!='#')
        {
            cout<<oper.top();
            oper.pop();
        }
        cout<<endl;
    }



}
