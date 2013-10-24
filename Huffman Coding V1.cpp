#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
class node
{
    public:
    char data;
    int weight,left,right,parent;
    node()
    {
        weight = 0;
        left = -1;
        right = -1;
        parent = -1;
    }
};
class number
{
    public:
    int time;
    char c;
    number()
    {
        time = 0;
    }
};
bool cmp(number a,number b)
{
    return a.time > b.time;
}
void select(node tree[],int &s1,int &s2,int n)
{
    int min = 200;
    for (int i = 0;i < n;i++)
    {
        if (tree[i].weight != 0&&tree[i].weight < min)
        {
            min = tree[i].weight;
            s1 = i;
        }

    }
    tree[s1].weight = 200;
    int min2 = 200;
    for (int i = 0;i < n;i++)
    {
        if (tree[i].weight > 0&&tree[i].weight < min2)
        {
            min2 = tree[i].weight;
            s2 = i;
        }
    }
    tree[s1].weight = min;
}
int main()
{
    int n;
    cin>>n;
    char s[n];
    number num[26];
    for (int i = 0;i < 26;i++)
    {
        num[i].c = i+'A';
    }
    set<char> se;
    for (int i = 0;i < n;i++)
    {
        cin>>s[i];
        num[s[i]-'A'].time++;
        se.insert(s[i]);
    }
    int m = se.size();
    int nn = 2 * m - 1;
    node tree[nn];
    int i = 0;
    for (int j = 0;j < 26;j++)
    {
        if (num[j].time!=0)
        {
            tree[i].data = 'A' + j;
            tree[i].weight = num[j].time;
            i++;
        }
    }
    for (i = m;i < nn;i++)
    {
        int s1,s2;
        select(tree,s1,s2,nn);
        tree[i].weight = tree[s1].weight+tree[s2].weight;
        tree[i].left = s1;
        tree[i].right = s2;
        tree[s1].weight = 200;
        tree[s2].weight = 200;
        tree[s1].parent = i;
        tree[s2].parent = i;
    }

    /*for (int i = 0;i < m;i++)
        cout<<tree[i].data << " "<<tree[i].weight<<" "<<tree[i].parent<<endl;
    for (int i = m;i < nn;i++)
        cout<<i << " "<<tree[i].weight<<" "<<tree[i].parent<<" "<<tree[i].left<<" "<<tree[i].right<<endl;*/
    sort(num,num+26,cmp);
    for (int i = 0;i < m;i++)
    {
        string ans;
        int j;
        for (j = 0;j < m;j++)
        {
            if (tree[j].data == num[i].c)
            break;
        }
        while (j != -1)
        {
            int k = tree[j].parent;
            if (tree[k].left == j)
            ans.insert(0,1,'0');
            else if (tree[k].right == j)
            ans.insert(0,1,'1');
            j = k;
        }
        cout<<num[i].c<<" "<<num[i].time<<" "<<ans<<endl;
    }
}
