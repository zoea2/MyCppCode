#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
struct node
{
    char grass;
    int pass;
    int x,y;
};
int count;
node farm[751][751];
int bfs(int a,int b)
{
    queue<node> q;
    node tmp = farm[a][b];
    farm[a][b].pass = 1;
    q.push(tmp);
    count++;
    int i,j;

    while(!q.empty())
    {
        tmp = q.front();
        q.pop();
        i = tmp.x;
        j = tmp.y;
        if (farm[i-1][j].grass == '.' && farm[i-1][j].pass == 0)
        {
            count ++;
            farm[i-1][j].pass = 1;
            q.push(farm[i-1][j]);
        }
        if(farm[i+1][j].grass == '.' && farm[i+1][j].pass == 0)

        {
            count++;
            farm[i+1][j].pass = 1;
            q.push(farm[i+1][j]);
        }
        if(farm[i][j+1].grass == '.' && farm[i][j+1].pass == 0)
        {
            count++;
            farm[i][j+1].pass = 1;
            q.push(farm[i][j+1]);
        }
        if(farm[i][j-1].grass == '.' && farm[i][j-1].pass == 0)
        {
            count++;
            farm[i][j-1].pass = 1;
            q.push(farm[i][j-1]);
        }
        if(farm[i-1][j+1].grass == '.' && farm[i-1][j+1].pass == 0)
        {
            count++;
            farm[i-1][j+1].pass = 1;
            q.push(farm[i-1][j+1]);
        }
        if(farm[i+1][j+1].grass == '.' && farm[i+1][j+1].pass == 0)
        {
            count++;
            farm[i+1][j+1].pass = 1;
            q.push(farm[i+1][j+1]);
        }
        if(farm[i-1][j-1].grass == '.' && farm[i-1][j-1].pass == 0)
        {
            count++;
            farm[i-1][j-1].pass = 1;
            q.push(farm[i-1][j-1]);
        }
        if(farm[i+1][j-1].grass == '.' && farm[i+1][j-1].pass == 0)
        {
            count++;
            farm[i+1][j-1].pass = 1;
            q.push(farm[i+1][j-1]);
        }

    }
    return count;
}

int main()

{
    int w,h;
    cin>>w>>h;
    int max = 0;
    for (int i = 1;i <= h;i++)
    {
        for (int j = 1;j <= w;j++)
        {
            cin>>farm[i][j].grass;
            farm[i][j].x = i;
            farm[i][j].y = j;
            farm[i][j].pass = 0;
        }

    }
    for(int i = 1;i <= h;i++)
    {
        for(int j = 1;j <= w;j++)
        {
            if (farm[i][j].grass == '.' && farm[i][j].pass == 0)
            {
                count = 0;
                bfs(i,j);
                if(max < count)
                max = count;
            }
        }
    }
    cout<<max<<endl;
    return 0;
}
