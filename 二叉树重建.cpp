#include <iostream>
#include <queue>
using namespace std;
class node
{
    public:
    char data;
    int left,right;
    node()
    {
        left = -1;
        right = -1;
    }

};
void ans(string a,string b,node tree[],int num)
{
    if (a.size() > 1)
    {
        int root;
    for (int i = 0;i <num ;i++)
    {
        if (tree[i].data == a[0])
        {
            root = i;
            break;
        }
    }
    int bpos;
    for (int i = 0;i < b.size();i++)
    {
        if (b[i] == a[0])
        {
            bpos = i;
            break;
        }
    }
    if (bpos != 0)
    {
        for (int j = 0;j < num;j++)
        if (tree[j].data == a[1])
        tree[root].left = j;
    }
    if (bpos != b.size()-1)
    {
        for (int j = 0;j < num;j++)
        if (tree[j].data == a[bpos+1])
        tree[root].right = j;
    }
    string c,d;
    c = a.substr(1,bpos);
    d = b.substr(0,bpos);
    ans(c,d,tree,num);
    c = a.substr(bpos+1);
    d = b.substr(bpos+1);
    ans(c,d,tree,num);
    }
}
void level(node tree[])
{
    node temp = tree[0];
    queue<node> q;
    q.push(temp);
    while(!q.empty())
    {
        temp = q.front();
        if (temp.left != -1)
        q.push(tree[temp.left]);
        if (temp.right != -1)
        q.push(tree[temp.right]);
        cout<<temp.data;
        q.pop();
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        int num = s1.size();
        node tree[num];
        for (int i = 0;i < num;i++)
        tree[i].data = s1[i];
        int count = 0;
        ans(s1,s2,tree,num);
        level(tree);
        cout<<endl;
    }

}
