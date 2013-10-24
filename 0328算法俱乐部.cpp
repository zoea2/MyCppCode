#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main()
{
    int adj[100][100] = {0};
    int n;
    cin>>n;
    int colour[100];
    colour[1] = 0;

    for (int i = 2;i <= n;i++ )
        colour[i] = -1;
    int temp;
    for (int i = 1;i <= n;i++)
    {
        while (cin>>temp)
        {
            if (temp != 0)
            {
                adj[i][temp] = 1;
                adj[temp][i] = 1;
            }
            else
            break;
        }
    }
    queue<int> b;
    b.push(1);
    while(!b.empty())
    {
        int temp1 = b.front();
        b.pop();
        for (int j = 1;j <= n;j++)
        {
           if (j == temp1)
                continue;
            if(adj[temp1][j] == 1)
            {
                if (colour[j] == -1)
                {

                    if (colour[temp1] == 0)
                    colour[j] = 1;
                    else
                    colour[j] = 0;
                    b.push(j);
                    }
                else if (colour[j] == colour[temp1])
                {
                        cout<<-1;
                        return 0;
                }
            }

        }

    }

    for(int i = 1;i <= n;i++)
    cout<<colour[i];

}
