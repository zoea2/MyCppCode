#include <stack>
#include <iostream>
using namespace std;
int main()
{
    string exp;
    cin>>exp;
    stack<char> oper;
    int i = 0;
    oper.push('#');
    while(i < exp.size())
    {
        if (exp[i] >= 'A'&& exp[i] <= 'Z'||exp[i] >= 'a'&& exp[i] <= 'z')
            cout<<exp[i];
        else
        {

                if (exp[i] == '+' || exp[i] == '-')
                {
                    if (oper.top()!= '#')
                    {
                        cout<<oper.top();
                        oper.pop();
                        continue;
                    }
                    else
                    oper.push(exp[i]);
                }
                else if (exp[i] == '*' || exp[i] == '/'||exp[i] == '%')
                {
                    if (oper.top() == '*' || oper.top() == '/'||oper.top() == '%')
                    {
                        cout<<oper.top();
                        oper.pop();
                        continue;
                    }
                    else
                    oper.push(exp[i]);
                }
        }
        i++;

    }
    while (oper.top()!='#')
    {
        cout<<oper.top();
        oper.pop();
    }


}
