#include <iostream>
using namespace std;
struct node
{
    int left;
    int right;
};
int main()
{
    int t,n,m,con,x,y;
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        node ball[n+1];
        ball[0].right = 1;
        for (int i = 1;i < n+1;i++)
        {
            ball[i].left = i - 1;
            ball[i].right = i + 1;
        }
        cin>>m;
        while(m--)
        {
            cin>>con>>x>>y;
            if (con == 1)
            {
                if (ball[x].right != y)
                {
                    ball[ball[x].left].right = ball[x].right;
                    ball[ball[x].right].left = ball[x].left;
                    ball[ball[y].left].right = x;
                    ball[x].left = ball[y].left;
                    ball[y].left = x;
                    ball[x].right = y;
                }
            }
            else
            {
                if (ball[x].left != y)
                {
                    ball[ball[x].left].right = ball[x].right;
                    ball[ball[x].right].left = ball[x].left;
                    ball[x].right = ball[y].right;
                    ball[ball[y].right].left = x;
                    ball[x].left = y;
                    ball[y].right = x;
                }
            }
        }
        int cur = 0;
        for (int i = 0;i < n;i++)
        {
            cur = ball[cur].right;
            cout<<cur<<" ";
        }
        cout<<endl;
    }
}
