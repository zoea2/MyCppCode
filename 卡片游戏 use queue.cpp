#include <queue>
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t)
    {
        --t;
        int n;
        cin>>n;
        queue<int> q;
        int a;
        for (int i = 1;i <= n;i++)
        {

            q.push(i);
        }
        int temp;
        while(q.size() > 1)
        {
            temp = q.front();
            q.pop();
            cout<<temp<<" ";
            temp = q.front();
            q.pop();
            q.push(temp);

        }
        cout<<q.front()<<" "<<endl;
    }
}
