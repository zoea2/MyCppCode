#include <queue>
#include <iostream>
#include <cstring>
using namespace std;
struct step
{
    int status[8];
    string steps;
};

int target[8];
const int init[8] = {1,2,3,4,8,7,6,5};
int maxstep;
void A(step current,queue<step>& q)
{
    step tmp;
    for(int i = 0;i < 4;i++)
    {
        tmp.status[i] = current.status[i+4];
        tmp.status[i+4] = current.status[i];
    }
    tmp.steps = current.steps + 'A';
    q.push(tmp);
}
void B(step current,queue<step>& q)
{
    step tmp;
    for(int i = 1;i < 4;i++)
    {
        tmp.status[i] = current.status[i-1];
        tmp.status[i+4] = current.status[i+3];
    }
    tmp.status[0] = current.status[3];
    tmp.status[4] = current.status[7];
    tmp.steps = current.steps + 'B';
    q.push(tmp);
}
void C(step current,queue<step>& q)
{
    step tmp = current;
    tmp.status[1] = current.status[5];
    tmp.status[2] = current.status[1];
    tmp.status[5] = current.status[6];
    tmp.status[6] = current.status[2];
    tmp.steps = current.steps + 'C';
    q.push(tmp);
}
void bfs()
{
    queue<step> q;
    step tmp;
    memcpy(tmp.status,init,sizeof(init));
    q.push(tmp);
    while(!q.empty())
    {
        tmp = q.front();
        q.pop();
        if (memcmp(tmp.status,target,sizeof(target)) == 0)
        {
            cout<<tmp.steps.size()<< " "<<tmp.steps<<endl;
            return;
        }
        if (tmp.steps.size() == maxstep)
            continue;
        A(tmp,q);
        B(tmp,q);
        C(tmp,q);
    }
    cout<<-1<<endl;
}
int main()
{
    cin>>maxstep;
    while (maxstep != -1)
    {
        for (int i = 0;i < 8;i++)
        cin>>target[i];
        bfs();
        cin>>maxstep;
    }
}

