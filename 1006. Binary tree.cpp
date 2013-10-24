#include <iostream>
using namespace std;
class btree
{
    public:
    char data;
    int lchild;
    int rchild;
    btree()
    {
        data = '#';
        lchild = 0;
        rchild = 0;
    }
};
void pre(btree t[],int head)
{
    if (head)
    {
        cout<<t[head].data;
        if (t[head].lchild != 0)
        pre(t,t[head].lchild);
        if (t[head].rchild != 0)
        pre(t,t[head].rchild);
    }
}
int main()
{
    int num;
    while(cin>>num)
    {
        btree t[1002];
        int index;
        bool is[1001] = {0};
        bool visit[1001] = {0};
        for (int i = 0;i < num;i++)
        {
            cin>>index;
            cin>>t[index].data>>t[index].lchild>>t[index].rchild;
            is[index] = 1;
        }
        int head;
        for (int i = 1;i <= 1000;i++)
        {
            if (t[i].data == '#')
            continue;
            else if(is[i])
            {
                if (t[i].lchild != 0)
                visit[t[i].lchild] = 1;
                if (t[i].rchild != 0)
                visit[t[i].rchild] = 1;
            }
        }
        for (int i = 1;i <= 1000;i++)
        {

            if(is[i]&&!visit[i])
            {
                head = i;
                break;
            }
        }

        pre(t,head);
        cout<<endl;

    }
}
