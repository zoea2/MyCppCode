#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
    int a,b;
}c[202];
bool cmp(const node& x,const node& y)
{
    return x.b>y.b;
}
int n,m;
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>c[i].a;
    for(int i=0;i<n;++i)
        cin>>c[i].b;
    sort(c,c+n,cmp);
    int ans[202][202] = {0};
    for  (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <=m;j++)
        {
            if (ans[i-1][j]<ans[i-1][j-1]+c[i-1].a-c[i-1].b*(j-1))
            ans[i][j] = ans[i-1][j-1]+c[i-1].a-c[i-1].b*(j-1);
            else
            ans[i][j] = ans[i-1][j];


        }
    }
    cout<<ans[n][m]<<endl;

}
