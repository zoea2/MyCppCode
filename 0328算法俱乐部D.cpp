#include <iostream>
#include <queue>
using namespace std;
class pos
{
    public:
    int x,y;
    pos(int x,int y)
    {
        this->x =x;
        this->y = y;
    }
};
int main()
{
    int n;
    cin>>n;
    char la[35][35];
    int col[34][34] = {0};
    col[1][1] = 1;
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= n;j++)
        cin>>la[i][j];
    }
    queue<pos> q;
    pos beg = pos(1,1);
    q.push(beg);
    int count = 0;
    while(!q.empty())
    {
        pos temp = q.front();
        q.pop();
        if (temp.x == 1 && temp.y==1)
        {
            if(la[2][1] == '#')
            count++;
            if (la[1][2] == '#')
            count++;
        }
        else if (temp.x == n && temp.y == n)
        {
            if(la[n-1][n] == '#')
            count++;
            if (la[n][n-1] == '#')
            count++;
        }
        else
        {
             if (la[temp.x+1][temp.y]=='#'||temp.x+1>n)
            {
                count++;
                //cout<<temp.x<<" "<<temp.y <<"x+1"<<endl;
            }
            if (la[temp.x-1][temp.y]=='#'||temp.x-1<1)
            {
                count++;
                //cout<<temp.x<<" "<<temp.y<<"x-1"<<endl;
            }
            if (la[temp.x][temp.y+1]=='#'||temp.y+1>n)
            {
                count++;
                //cout<<temp.x<<" "<<temp.y<<"y+1"<<endl;
            }
            if (la[temp.x][temp.y-1]=='#'||temp.y-1<1)
            {
                count++;
                //cout<<temp.x<<" "<<temp.y<<"y-1"<<endl;
            }
        }
        if (la[temp.x+1][temp.y]=='.'&&col[temp.x+1][temp.y]==0&&temp.x+1<=n)
        {
            col[temp.x+1][temp.y]=1;
            pos temp1 = pos(temp.x+1,temp.y);
            q.push(temp1);
        }
        if (la[temp.x-1][temp.y]=='.'&&col[temp.x-1][temp.y]==0&&temp.x-1>=1)
        {
            col[temp.x-1][temp.y]=1;
            pos temp2 = pos(temp.x-1,temp.y);
            q.push(temp2);
        }
        if (la[temp.x][temp.y+1]=='.'&&col[temp.x][temp.y+1]==0&&temp.y+1<=n)
        {
            col[temp.x][temp.y+1]=1;
            pos temp3 = pos(temp.x,temp.y+1);
            q.push(temp3);
        }

        if (la[temp.x][temp.y-1]=='.'&&col[temp.x][temp.y-1]==0&&temp.y-1>=1)
        {
            col[temp.x][temp.y-1]=1;
            pos temp4 = pos(temp.x,temp.y-1);
            q.push(temp4);
        }

    }
    pos end = pos(n,n);
    q.push(end);
    int count0 = 0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= n;j++)
        col[i][j] = 0;
    }
    col[n][n] = 1;
    while(!q.empty())
    {
        pos temp = q.front();
        q.pop();
        if (temp.x == n && temp.y == n)
        {
            if(la[n-1][n] == '#')
            count0++;
            if (la[n][n-1] == '#')
            count0++;
        }
        else if (temp.x == 1 && temp.y==1)
        {
            if(la[2][1] == '#')
            count0++;
            if (la[1][2] == '#')
            count0++;
        }
        else
        {
            if (la[temp.x+1][temp.y]=='#'||temp.x+1>n)
            {
                count0++;
                //cout<<temp.x<<" "<<temp.y <<"x+1"<<endl;
            }
            if (la[temp.x-1][temp.y]=='#'||temp.x-1<1)
            {
                count0++;
                //cout<<temp.x<<" "<<temp.y<<"x-1"<<endl;
            }
            if (la[temp.x][temp.y+1]=='#'||temp.y+1>n)
            {
                count0++;
                //cout<<temp.x<<" "<<temp.y<<"y+1"<<endl;
            }
            if (la[temp.x][temp.y-1]=='#'||temp.y-1<1)
            {
                count0++;
                //cout<<temp.x<<" "<<temp.y<<"y-1"<<endl;
            }
        }
        if (la[temp.x+1][temp.y]=='.'&&col[temp.x+1][temp.y]==0&&temp.x+1<=n)
        {
            col[temp.x+1][temp.y]=1;
            pos temp1 = pos(temp.x+1,temp.y);
            q.push(temp1);
        }
        if (la[temp.x-1][temp.y]=='.'&&col[temp.x-1][temp.y]==0&&temp.x-1>=1)
        {
            col[temp.x-1][temp.y]=1;
            pos temp2 = pos(temp.x-1,temp.y);
            q.push(temp2);
        }
        if (la[temp.x][temp.y+1]=='.'&&col[temp.x][temp.y+1]==0&&temp.y+1<=n)
        {
            col[temp.x][temp.y+1]=1;
            pos temp3 = pos(temp.x,temp.y+1);
            q.push(temp3);
        }

        if (la[temp.x][temp.y-1]=='.'&&col[temp.x][temp.y-1]==0&&temp.y-1>=1)
        {
            col[temp.x][temp.y-1]=1;
            pos temp4 = pos(temp.x,temp.y-1);
            q.push(temp4);
        }

    }
    if (count == count0)
    {
        cout<<9*count;

    }
    else
    {
        cout<<9*(count+count0);

    }

}
