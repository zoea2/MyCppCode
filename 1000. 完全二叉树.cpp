// Problem#: 6209
// Submission#: 1593969
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <stdio.h>
using namespace std;
class tree
{

    public:
    int parents;
    int lchild;
    int rchild;

    tree()
    {
        lchild = -1;
        rchild = -1;
        parents = -1;
    }
};
int main()
{
    tree t[1000];
    t[0].parents = -1;
    t[0].lchild = 1;
    t[0].rchild = 2;
    t[1].parents = 0;
    t[2].parents = 0;
    int ccount = 3;
    for (int i = 1;ccount < 1000;i++)
    {
        t[i].lchild = ccount;
        t[ccount++].parents = i;
        t[i].rchild = ccount;
        t[ccount++].parents = i;
    }

    //for (int i = 0;i < 1000;i++)
    //cout<<t[i].parents<<" "<<t[i].lchild<<" "<<t[i].rchild<<endl;
    int t1;
    cin>>t1;
    int res1[500];
    int res2[500];
    while(t1--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int count = 1,count0 = 1;
        res1[0] = a;
        a = t[a-1].parents;
        while(a != -1)
        {
            res1[count++] = a+1;
            a = t[a].parents;
        }
        res2[0] = b;
        b = t[b-1].parents;
        while(b != -1)
        {
            res2[count0++] = b + 1;
            b = t[b].parents;
        }
        bool is = 0;
        int res;
        int i = count-1,j = count0-1;
        while(i >=0 && j >= 0)
        {
            if (res1[i] == res2[j])
            {
                i--;j--;
            }
            else break;
        }
        i++;
        res = res1[i];
        printf("%d\n",res);
    }
}
