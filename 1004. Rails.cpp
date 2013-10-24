#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main()
{
    int num;
    cin>>num;
    while(num)
    {
        int x;
        while (cin>>x)
        {
            if (x == 0)
            {
                cout<<endl;
                break;
            }
            int a[num];
            a[0] = x;
            for (int i = 1;i < num;i++)
            cin>>a[i];
            queue<int> q;
            for (int i = 1;i <= num;i++)
            q.push(i);
            stack<int> s;
            bool flag = true;
            for (int i = 0;i < num;i++)
            {
                if (!q.empty()&&q.front() == a[i])
                q.pop();
                else if (!s.empty()&&s.top()==a[i])
                s.pop();
                else if (!q.empty()&&q.front()<a[i])
                {
                    s.push(q.front());
                    i--;
                    q.pop();
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            cout<<"Yes"<<endl;
            else
            cout<<"No"<<endl;
        }

        cin>>num;
    }

}
