#include <iostream>
#include <cstring>
using namespace std;
char w[10001];
char t[1000001];
int next[10001];
void genext(int n)
{
    int i = 0,j = -1;
    next[0] = -1;
    while(i <= n)
    {
        if (w[i] == w[j] || j == -1)
        {
            i++;
            j++;
            if (w[i] != w[j])
            next[i] = j;
            else
            next[i] = next[j];
        }
        else
        j = next[j];
    }
}
int kmp(int n,int m)
{
    int count = 0;
    int i = 0,j = 0;
    while(i < n)
    {
        if(j == m)
        count++;
        if (t[i] == w[j] || j == -1)
        {
            i++;
            j++;
        }
        else
        j = next[j];

    }
    if (j == m)
    count++;
    return count;
}
int main()
{
    int T;
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        //memset(w,0,sizeof(w));
        //memset(t,0,sizeof(t));
        //memset(next,0,sizeof(next));
        cin>>w>>t;
        genext(strlen(w));
        cout<<kmp(strlen(t),strlen(w))<<endl;
    }
}
