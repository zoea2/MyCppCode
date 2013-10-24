#include <iostream>
#include <queue>
using namespace std;
struct node
{
    char l;
    int c;
    node(char a,int b,int s)
    {
        l = a;
        c = b;
        step = s+1;
    }
    int step;
};
int main()
{
    int t;
    cin>>t;
    char l1,l2;
    int c1,c2;
    while(t--)
    {
        bool visit[8][9] = {0};
        cin>>l1>>c1>>l2>>c2;
        node start = node(l1,c1,-1);
        queue<node> q;
        q.push(start);
        visit[l1-'a'][c1] = true;
        while(!q.empty())
        {
            node temp = q.front();
            q.pop();
            if (temp.l == l2 && temp.c == c2)
            {
                cout<<"To get from "<<l1<<c1<<" to "<<l2<<c2<<" takes "<<temp.step<<" knight moves."<<endl;

                break;
            }
            if (temp.l + 2 <= 'h' && temp.c -1 >= 1 && !visit[temp.l-'a'+2][temp.c-1])
            {
                q.push(node(temp.l + 2,temp.c-1,temp.step));
                visit[temp.l-'a'+2][temp.c-1] = true;
            }
            if (temp.l + 2 <= 'h' && temp.c + 1 <= 8 && !visit[temp.l-'a'+2][temp.c+1])
            {
                q.push(node(temp.l + 2,temp.c+1,temp.step));
                visit[temp.l-'a'+2][temp.c+1] = true;
            }
            if (temp.l - 2 >= 'a' && temp.c -1 >= 1 && !visit[temp.l-'a'-2][temp.c-1])
            {
                q.push(node(temp.l - 2,temp.c-1,temp.step));
                visit[temp.l-'a'-2][temp.c-1] = true;
            }
            if (temp.l - 2 >= 'a' && temp.c + 1 <= 8 && !visit[temp.l-'a'-2][temp.c+1])
            {
                q.push(node(temp.l - 2,temp.c+1,temp.step));
                visit[temp.l-'a'-2][temp.c+1] = true;
            }
              if (temp.l + 1 <= 'h' && temp.c -2 >= 1 && !visit[temp.l-'a'+1][temp.c-2])
            {
                q.push(node(temp.l + 1,temp.c-2,temp.step));
                visit[temp.l-'a'+1][temp.c-2] = true;
            }
            if (temp.l + 1 <= 'h' && temp.c + 2 <= 8 && !visit[temp.l-'a'+1][temp.c+2])
            {
                q.push(node(temp.l + 1,temp.c+2,temp.step));
                visit[temp.l-'a'+1][temp.c+2] = true;
            }
            if (temp.l - 1 >= 'a' && temp.c -2 >= 1 && !visit[temp.l-'a'-1][temp.c-2])
            {
                q.push(node(temp.l - 1,temp.c-2,temp.step));
                visit[temp.l-'a'-1][temp.c-2] = true;
            }
            if (temp.l - 1 >= 'a' && temp.c + 2 <= 8 && !visit[temp.l-'a'-1][temp.c+2])
            {
                q.push(node(temp.l - 1,temp.c+2,temp.step));
                visit[temp.l-'a'-1][temp.c+2] = true;
            }
        }
    }
}
