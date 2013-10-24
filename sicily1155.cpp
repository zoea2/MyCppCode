#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    while(n != 0)
    {
        int col[200] = {0};
        col[0] = 1;
        int pit[200][200] = {0};
        int begin,end;
        bool isPost = 0;
        cin>>m;
        for (int i = 0;i < m;i++)
        {
            cin>>begin>>end;
            pit[begin][end] = 1;
        }
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            if (temp == n - 1)
            {
                cout<<"I can post the letter"<<endl;
                isPost = 1;
                break;
            }
            for (int i = 0;i < n;i++)
            {
                if (pit[temp][i] == 1&&col[i] == 0)
                {
                    q.push(i);
                    col[i] = 1;
                }
            }
        }
        if (isPost != 1)
        cout<<"I can't post the letter"<<endl;
        cin>>n;
    }
}
